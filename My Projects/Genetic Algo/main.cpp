#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int popn_size = 100;
int max_generations = 1000;
int chromosome_len = 1600;
int gene_len = 4;
double mutation_rate = 0.1;
double crossover_rate = 0.7;
string bit_limit = "";
map<string, char> translation;


void encode(vector<char> types)
{
	int n_bits = ceil(log2(types.size()));

	int max_bit_power = pow(2, n_bits - 1);
	for (int i = 0; i < types.size(); ++i)
	{
		string bit = "";

		int curr_bit = max_bit_power;
		int number = i;
		while (curr_bit != 0)
		{
			if (number < curr_bit)
				bit += '0';
			else
			{
				number -= curr_bit;
				bit += '1';
			}
			curr_bit /= 2;
		}
		translation[bit] = types[i];

		if (i == types.size() - 1)
			bit_limit = bit;
	}
}

double rand_range(double low, double high)
{
	if ((int)(high - low) == 0)
		return 0;

	return (rand() % (int)(high - low)) + low;
}

double random()
{
	return (double)rand() / (double)RAND_MAX;
}

int rand_0_1()
{
	if (random() >= 0.50)
		return 1;
	else
		return 0;
}

class chromosome
{
public:
	chromosome(const int &n_bits);
	void crossover(chromosome &other);
	void mutate();
	void calc_fitness(const double &target);
	bool is_valid(const string &bit);
	string DNA = "";
	double fitness;
	double computed_result;
};

chromosome::chromosome(const int &n_bits)
{
	for (int i = 0; i < n_bits; ++i)
		DNA += '1' - rand_0_1();
}

void chromosome::crossover(chromosome& other)
{
	if (rand_range(0, 1) > crossover_rate)
		return;
	int c_point = rand_range(0, DNA.size() - 1);
	for (int i = c_point; i < DNA.size(); ++i)
	{
		int temp = DNA[i];
		DNA[i] = other.DNA[i];
		other.DNA[i] = temp;
	}
}

void chromosome::mutate()
{
	for (int i = 0; i < DNA.size(); ++i)
	{
		if (random() <= mutation_rate)
			DNA[i] = '0' + ('1' - DNA[i]);
	}
}

bool chromosome::is_valid(const string &bit)
{
	if (bit > bit_limit)
		return false;
	return true;
}

void chromosome::calc_fitness(const double &target)
{
	string result;

	fitness = 1.0 / (double)abs(error);
	computed_result = result;
}

class GA
{
public:
	GA(const int &n_bits, const int &t);
	void choose_chromosomes();
	void evolution_fitness();           //handles crossing over, mutations, and fitness computation.
	bool target_reached() { return t_reached; }
	void display_chromosomes();
	void display_target();                //Display Target
	bool gen_maxed_out() { if (n_gen >= max_generations) return true; else return false; }
private:
	int chosen_1, chosen_2;
	double target;
	bool t_reached;
	int t_index;
	double total_fitness = 0.0;
	vector<chromosome> popn;
	int n_gen = 0;
};

GA::GA(const int &n_bits, const int &t)
{
	target = t;
	t_reached = false;
	t_index = 0;
	for (int i = 0; i < popn_size; ++i)
	{
		popn.push_back(chromosome(n_bits));
		popn.back().calc_fitness(t);
		if (isinf(popn.back().fitness))
		{
			t_reached = true;
			t_index = popn.size() - 1;
		}
		total_fitness += popn.back().fitness;
	}


}

void GA::choose_chromosomes()
{
	double wheel_spin = random()*total_fitness;

	for (int i = 0; i<popn.size(); ++i)
	{
		if (wheel_spin <= popn[i].fitness)
		{
			chosen_1 = i;
			break;
		}
		wheel_spin -= popn[i].fitness;
	}

	wheel_spin = random()*total_fitness;
	for (int i = 0; i<popn.size(); ++i)
	{
		if (wheel_spin <= popn[i].fitness)
		{
			chosen_2 = i;
			break;
		}
		wheel_spin -= popn[i].fitness;
	}
}

void GA::evolution_fitness()
{
	total_fitness = 0;
	vector<chromosome> new_popn;
	while (new_popn.size() != popn.size())
	{
		choose_chromosomes();
		chromosome p1 = popn[chosen_1];
		chromosome p2 = popn[chosen_2];

		p1.crossover(p2);
		p1.mutate();
		p2.mutate();

		p1.calc_fitness(target);
		p2.calc_fitness(target);

		if (isinf(p1.fitness))
		{
			t_reached = true;
			t_index = new_popn.size();
		}
		else if (isinf(p2.fitness))
		{
			t_reached = true;
			t_index = new_popn.size() + 1;
		}

		total_fitness += p1.fitness;
		total_fitness += p2.fitness;

		new_popn.push_back(p1);
		new_popn.push_back(p2);
	}
	popn = new_popn;
	++n_gen;
}

void GA::display_chromosomes()
{
	for (int i = 0; i < popn.size(); ++i)
	{
		cout << "Fitness: " << popn[i].fitness << endl;
		cout << "Result: " << popn[i].computed_result << endl;
		cout << "Chromosme: " << popn[i].DNA << endl << endl;
	}
	cout << endl;
}

void GA::display_target()
{
	int counter = 0;
	int curr_operator = -1;
	int start = 0;

	//First find a number. It helps maintain the counter
	for (int i = 0; i < popn[t_index].DNA.size(); i += gene_len)
	{
		string curr_bit = popn[t_index].DNA.substr(i, gene_len);
		if (popn[t_index].is_valid(curr_bit))
		{
			if (popn[t_index].is_digit(curr_bit))
			{
				start = i + gene_len;                 //starting point for the rest of the process
				cout << translation[curr_bit];
				break;
			}

		}
	}

	for (int i = start; i < popn[t_index].DNA.size(); i += gene_len)
	{
		string curr_bit = popn[t_index].DNA.substr(i, gene_len);
		if (popn[t_index].is_valid(curr_bit))
		{
			if (popn[t_index].is_digit(curr_bit))
			{
				if (counter == 1)
				{
					switch (curr_operator)
					{
					case 0:
						cout << "+" << translation[curr_bit];
						break;
					case 1:
						cout << "-" << translation[curr_bit];
						break;
					case 2:
						cout << "*" << translation[curr_bit];
						break;
					case 3:
						if (translation[curr_bit] != 0)
							cout << "/" << translation[curr_bit];
						break;
					default:
						break;
					}
					counter = 0;
				}
			}
			else if (counter == 0)
			{
				switch (translation[curr_bit])
				{
				case '+':
					curr_operator = 0;
					break;
				case '-':
					curr_operator = 1;
					break;
				case '*':
					curr_operator = 2;
					break;
				case '/':
					curr_operator = 3;
					break;
				default:
					break;
				}
				++counter;
			}
		}
	}
	cout << endl;
	cout << "Number of Generations: " << n_gen << endl;
}

int main()
{
	srand(time(NULL));
	vector<char> results;
	for (int i = 0; i < 26; ++i)
	{
		results.push_back('a' + i);
	}
	encode(results);

	cout << "Enter mutation rate: ";
	cin >> mutation_rate;

	cout << "Enter crossover rate: ";
	cin >> crossover_rate;

	cout << "Enter population size: ";
	cin >> popn_size;

	cout << endl;

	while (true)
	{
		string x;
		cout << "Enter target: ";
		cin >> x;
		GA my_GA(x.size(), x);

		while (true)
		{
			//my_GA.display_chromosomes();
			if (my_GA.target_reached())
			{
				my_GA.display_target();
				break;
			}
			//else if (my_GA.gen_maxed_out())
			//{
			//	cout << "Couldn't find solution!" << endl;
			//	break;
			//}
			my_GA.evolution_fitness(); //Go to next gen and recalc the fitnesss.
		}
	}


}
