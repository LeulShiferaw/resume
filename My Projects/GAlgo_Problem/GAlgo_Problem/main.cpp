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
int gene_len = 5;
int extra_genes = 2;
double mutation_rate = 0.1;
double crossover_rate = 0.7;
bool binary_mode = false;    //Do binary search
string bit_limit = "";
map<string, char> translation;


void encode(vector<char> types)
{
	int n_bits = ceil(log2(types.size())); //There are 2^n d/t ways of writing different combos of n-bits

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
	void calc_fitness(const string &target);
	bool is_valid(const string &bit);
	string DNA = "";
	double fitness;
	string computed_result;
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

//To determine the number of mutations
int n_mutations = 0;
int total_attempt = 0;
void chromosome::mutate()
{
	for (int i = 0; i < DNA.size(); ++i)
	{
		if (random() <= mutation_rate)
		{
			++n_mutations;
			DNA[i] = '0' + ('1' - DNA[i]);
		}
		++total_attempt;
	}
}

bool chromosome::is_valid(const string &bit)
{
	if (bit > bit_limit)
		return false;
	return true;
}

void chromosome::calc_fitness(const string &target)
{
	string result = "";
	double error = 0.0;

	for (int i = 0; i < DNA.size(); i += gene_len)
	{
		string curr_bit = DNA.substr(i, gene_len);
		if (is_valid(curr_bit))
		{
			result += translation[curr_bit];
			error += abs(target[result.size() - 1] - translation[curr_bit]);
			if (result.size() == target.size())
				break;
		}
	}

	for (int i = result.size(); i < target.size(); ++i)
		error += target[i];

	fitness = 1.0 / (double)abs(error);
	computed_result = result;
}

class GA
{
public:
	GA(const int &n_bits, const string &t);
	void choose_chromosomes();
	void evolution_fitness();           //handles crossing over, mutations, and fitness computation.
	bool target_reached() { return t_reached; }
	void display_fittest();
	void display_target();                //Display Target
	bool gen_maxed_out() { if (n_gen >= max_generations) return true; else return false; }
	int number_gen() { return n_gen; }
private:
	int chosen_1, chosen_2;
	string target;
	int f_index = 0;
	string fittest = "";
	bool t_reached;
	int t_index;
	double total_fitness = 0.0;
	vector<chromosome> popn;
	int n_gen = 0;
};

GA::GA(const int &n_bits, const string &t)
{
	target = t;
	t_reached = false;
	t_index = 0;
	double fittest_fitness = 0.0f;
	for (int i = 0; i < popn_size; ++i)
	{
		popn.push_back(chromosome(n_bits));
		popn.back().calc_fitness(t);
		if (isinf(popn.back().fitness))
		{
			t_reached = true;
			t_index = popn.size() - 1;
			break;
		}
		if (popn.back().fitness>fittest_fitness)
		{
			fittest_fitness = popn.back().fitness;
			fittest = popn.back().computed_result;
			f_index = popn.size() - 1;
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

	new_popn.push_back(popn[f_index]);
	new_popn.push_back(popn[f_index]);
	
	f_index = 0;                            //The current fittest always goes to the next gen as the first individual
	double fittest_fitness = popn[f_index].fitness;		
	
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

		if (!isinf(p1.fitness) && p1.fitness > fittest_fitness)
		{
			fittest_fitness = p1.fitness;
			fittest = p1.computed_result;
			f_index = new_popn.size();
		}
		if (!isinf(p2.fitness) && p2.fitness > fittest_fitness)
		{
			fittest_fitness = p2.fitness;
			fittest = p2.computed_result;
			f_index = new_popn.size() + 1;
		}

		new_popn.push_back(p1);
		new_popn.push_back(p2);
	}
	popn = new_popn;
	++n_gen;
}

void GA::display_fittest()
{
	cout << fittest << " : " << popn[f_index].computed_result << endl;
}

void GA::display_target()
{
	if (!binary_mode)
	{
		cout << "Result: " << popn[t_index].computed_result << endl;
		cout << "Number of Generations: " << n_gen << endl;
	}
	else
		cout << popn[t_index].computed_result;
}

int total_n_gen = 0;
void evolve(string target)
{
	if (target.size() < 3)
	{
		GA my_GA(target.size()*(gene_len + extra_genes), target);
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
			total_n_gen += my_GA.number_gen();
			//my_GA.display_fittest();
			//cin.get();
		}
		return;
	}
	total_n_gen += 2;
	evolve(target.substr(0, target.size() / 2));
	evolve(target.substr(target.size() / 2, target.size()));
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

		//Binary search method
		if (binary_mode)
		{
			if (total_attempt > 0)
				cout << (double)(n_mutations) / (double)total_attempt *100.0 << " % mutated." << endl;
			else
				cout << "0 % mutated." << endl;
			cout << "Result: ";
			evolve(x);
			cout << endl;
			cout << "Number of generations: " << total_n_gen << endl;
			total_n_gen = 0;
		}
		else
		{
			GA my_GA(x.size()*(gene_len + extra_genes), x);
			while (true)
			{
				//my_GA.display_chromosomes();
				if (my_GA.target_reached())
				{
					if (total_attempt > 0)
						cout << (double)(n_mutations) / (double)total_attempt *100.0 << " % mutated." << endl;
					else
						cout << "0 % mutated." << endl;
					my_GA.display_target();
					break;
				}
				//else if (my_GA.gen_maxed_out())
				//{
				//	cout << "Couldn't find solution!" << endl;
				//	break;
				//}
				my_GA.evolution_fitness(); //Go to next gen and recalc the fitnesss.
				//my_GA.display_fittest();
				//cin.get();
			}
		}
	}
}
