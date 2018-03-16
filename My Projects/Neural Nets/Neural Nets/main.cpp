#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

int    act_func = 1;           //1-Sigmoid, 2-Hyperbolic tangent, 3-Sine function, 4-Cosine function
double learning_rate = 0.15;   //The rate at which it learns
double momentum = 0.00;
bool scale = false;
map<vector<int>, int> translation;

double random()                //Return a random decimal b/n 0 and 1
{
	return (double)rand() / (double)RAND_MAX;
}

double random_neg()
{
	if (random() >= 0.50)
		return (double)rand() / (double)RAND_MAX;
	else
		return (double)-rand() / (double)RAND_MAX;
}

class Neuron
{
public:
	Neuron(const int &next_l_size);
	double get_output() { return output; }
	double get_input() { return input; }
	double get_weight(int x) { return weights[x]; }  //Redundant. REMOVE ASAP.
	void set_input(double x) { input = x; }
	void set_output(double x) { output = x; }
	vector<double> weights;
	vector<double> gradients;
	vector<double> prev_updates;
private:
	double input;
	double output;
};

//Create the weights of the neuron and assign random values to them
Neuron::Neuron(const int &next_l_size)
{
	for (int i = 0; i<next_l_size; ++i)
	{
		weights.push_back(random_neg());
		gradients.push_back(0.0);
		prev_updates.push_back(0.0);
	}

}

class Net
{
public:
	Net(const vector<int> &net_info);
	double feed_forward(const vector<double> &inputs);  //Also return the last value
	void back_prop(const double &target);
	double f(double x) { if (act_func == 1) return 1.0 / (1.0 + exp(-x)); else if (act_func == 2) return tanh(x); else if (act_func == 3) return sin(x); else if (act_func == 4) return cos(x); else if (act_func == 5) return x; } //Sigmoid, hyperbolic tangent, sine, cosine
	double f_derv(double x) { if (act_func == 1) return f(x)*(1 - f(x)); else if (act_func == 2) return 1 - pow(tanh(x), 2); else if (act_func == 3) return cos(x); else if (act_func == 4) return -sin(x); else if (act_func == 5) return 1; }
private:
	vector<vector<Neuron>> Neural_Net;
};

//Create the entire neural net
Net::Net(const vector<int> &net_info)
{
	//The number of layers is the size of the net_info function
	for (int i = 0; i<net_info.size(); ++i)
	{
		//Create the layers and the neurons with in them
		vector<Neuron> temp_layer;
		for (int j = 0; j<net_info[i]; ++j)
		{
			if (i == net_info.size() - 1)
				temp_layer.push_back(Neuron(0));
			else
				temp_layer.push_back(Neuron(net_info[i + 1]));
		}
		//The output layer doesn't contain a bias neuron.
		if (i != net_info.size() - 1)
		{
			temp_layer.push_back(Neuron(net_info[i + 1]));//Bias
			temp_layer.back().set_input(1.0);  //Bias
			temp_layer.back().set_output(1.0); //Bias
		}
		Neural_Net.push_back(temp_layer); //Assign the layer to the net
	}
}

//Also returns the result, but only one result so it works if the number of outputs is 1.
double Net::feed_forward(const vector<double> &inputs)
{
	//First layer
	for (int i = 0; i<Neural_Net[0].size() - 1; ++i)//Exclude the bias
	{
		Neural_Net[0][i].set_input(inputs[i]);
		Neural_Net[0][i].set_output(inputs[i]);
	}

	//Set the input and output of the rest
	for (int i = 1; i<Neural_Net.size(); ++i)
	{
		int end = Neural_Net[i].size() - 1; //Excludes the bias
		if (i == Neural_Net.size() - 1)//the output layer doesn't have a bias neuron.
			end += 1;

		//For each neuron in layer i
		for (int j = 0; j<end; ++j)
		{
			double sum = 0.0;
			for (int k = 0; k<Neural_Net[i - 1].size(); ++k) //Calculate the sum of the w*o of the previous layer
				sum += Neural_Net[i - 1][k].get_output()*Neural_Net[i - 1][k].get_weight(j);//Get weight to my neuron
			Neural_Net[i][j].set_input(sum);     //Assign the result as the input of this neuron
			if (scale)
				Neural_Net[i][j].set_output(f(sum)); //Then use the activation function and make it an output
			else
				Neural_Net[i][j].set_output(sum);
		}
	}
	return Neural_Net[Neural_Net.size() - 1][0].get_output(); //Only for one output Neural Nets.
}

void Net::back_prop(const double &target)
{
	double net_result = Neural_Net[Neural_Net.size() - 1][0].get_output();
	double delta = net_result - target;
	for (int i = Neural_Net.size() - 2; i >= 0; --i)//Every Layer starting from the second last layer.
	{
		for (int j = 0; j<Neural_Net[i].size(); ++j)//Every Neuron in layer i even the bias neuron. The bias's weights still change
		{
			for (int k = 0; k<Neural_Net[i][j].weights.size(); ++k)//Every Weight
			{
				if (i == Neural_Net.size() - 2) //Gradient calculation for the second last layer
				{
					if(!scale)
						Neural_Net[i][j].gradients[k] = f_derv(Neural_Net[i + 1][k].get_input())* Neural_Net[i][j].get_output() * delta;
					else
						Neural_Net[i][j].gradients[k] = Neural_Net[i][j].get_output() * delta;
				}
				else
				{
					double sum_0 = 0.0;
					for (int h = 0; h < Neural_Net[i + 1][k].weights.size(); ++h)
					{
						if (Neural_Net[i + 1][k].get_output() == 0)
							sum_0 += 0;
						else
						{
							sum_0 += Neural_Net[i + 1][k].gradients[h] / Neural_Net[i + 1][k].get_output()*
								Neural_Net[i + 1][k].weights[h];
						}
					}
					Neural_Net[i][j].gradients[k] = sum_0*f_derv(Neural_Net[i + 1][k].get_input())*
						Neural_Net[i][j].get_output();
				}
				Neural_Net[i][j].weights[k] += (-learning_rate*Neural_Net[i][j].gradients[k]) + (momentum*Neural_Net[i][j].prev_updates[k]);
				Neural_Net[i][j].prev_updates[k] = (-learning_rate*Neural_Net[i][j].gradients[k]);
			}
		}
	}
}

int rand_input()
{
	return random() * 10;
	/*if (random() >= 0.50)
		return 1;
	else
		return 0;*/
}

double output(int a, int b)
{
	return a + b;
}

int main()
{
	srand(time(NULL));
	Net my_Net({ 2, 1, 1 });
	int n_traning_loops = 1000000;

	for (int i = 1; i <= n_traning_loops; ++i)
	{
		vector<double> inputs;
		double i1 = rand_input(), i2 = rand_input();
		inputs = { i1, i2 };

		my_Net.feed_forward(inputs);
			
		my_Net.back_prop(output(i1, i2));
	}

	int n_test_loops = 100;
	int n_passed = 0;
	for (int i = 1; i <= n_test_loops; ++i)
	{
		double i1 = rand_input(), i2 = rand_input();
		if (round(my_Net.feed_forward({ i1, i2 })) == output(i1, i2))
			++n_passed;
			
	}

	cout << "The trained neural net is " << (double)n_passed / (double)n_test_loops*100.0 << "% efficient." << endl;

	while (true)
	{
		double i1, i2;
		cout << "Input: ";
		cin >> i1 >> i2;
		cout << "Result: " << my_Net.feed_forward({ i1, i2 }) << endl;
	}
}
