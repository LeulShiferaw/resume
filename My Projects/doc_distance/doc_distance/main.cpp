
//TO DO LIST:
//Turn all useless characters into ' ' 
//Then create a function that removes ' '

#include <c++\std_lib_facilities.h>

//Max value of result
//Constant used in the last stage
constexpr float pi_over_2 = 44 / 7;

//User defined
//Contains the frequency of a word
//and the string value of the word
struct word
{
	int freq = 0;
	string value = "";
};

//User defined
//Contains the word distributions
//of a document.
class word_distribution
{
private:
	vector<word> words;
public:
	//Amount of words in file
	int size(){ return words.size(); }
	
	//dot product with another file
	int dot_product(word_distribution&);
	
	//displays the words with their 
	//frequency.
	void display();

	//Adds a new word to our words vector
	//or increments the corresponding freq
	void add_word(string);

	//returns the magnitude of the frequencies
	//as if they were part of an actual vector
	double magnitude();

	//returns all the words in the doc
	vector<word> my_words(){ return words; }
};

//Compares to strings
//Even those that end with fullstops.
//Eg. abiy. abiy
bool compare(const string& x1, const string& x2);

//Checks if the character is capital
bool is_capital(char x);

//If the string contains captial letters then
//it will decapitalize it.
//Detects fullstops or other operators and turns them into ' '
//which will be ignored in compare.
void decapitilize(vector<string>& file);

int main()
{
	ifstream file_reader1("doc1.txt");
	ifstream file_reader2("doc2.txt");

	if (!file_reader1.is_open() || !file_reader2.is_open())
	{
		cout << "Couldn't open file";
		return 0;
	}

	string temp;
	vector<string> doc1, doc2;
	
	while (file_reader1 >> temp)
		doc1.push_back(temp);

	while (file_reader2 >> temp)
		doc2.push_back(temp);
	
	word_distribution word_dis1;
	word_distribution word_dis2;

	sort(doc1);
	sort(doc2);

	decapitilize(doc1);
	decapitilize(doc2);

	//Add words to word distributions
	for (int i = 0; i < doc1.size(); ++i)
	{
		word_dis1.add_word(doc1[i]);
	}

	for (int i = 0; i < doc2.size(); ++i)
	{
		word_dis2.add_word(doc2[i]);
	}

	//Find A.B/|A|.|B|
	float cos_teta = (word_dis1.dot_product(word_dis2)) / (word_dis1.magnitude()*word_dis2.magnitude());
	
	//Then arc cosine it
	float answer = acos(cos_teta);

	//Turn it into percentage
	//The maximum value(100 percent) is PI/2
	answer /= pi_over_2;
	answer *= 100;
	answer = 100 - (answer);
	
	cout << answer;
}

void decapitilize(vector<string>& file)
{
	for (int i = 0; i < file.size(); ++i)
	{
		for (int j = 0; j < file[i].size(); ++j)
		{
			if (is_capital(file[i][j]))
			{
				int buffer = file[i][j] - 'A';
				file[i][j] = 'a' + buffer;
			}
			if (file[i][j] == '.')
				file[i][j] = ' ';
		}
	}
}

bool is_capital(char x)
{
	if (x <= 'Z'&& x >= 'A')
		return true;
	return false;
}

bool compare(const string& x1, const string& x2)
{
	if (x1.size() == x2.size())
		return x1 == x2;

	//If the last character is a ' ' 
	if (x1.size() == x2.size() + 1)
	{
		if (x1[x1.size() - 1] == ' ')
		{
			for (int i = 0; i < x1.size() - 1; ++i)
			{
				if (x2[i] != x1[i])
					return false;
			}
			return true;
		}
	}

	if (x2.size() == x1.size() + 1)
	{
		if (x2[x2.size() - 1] == ' ')
		{
			for (int i = 0; i < x2.size() - 1; ++i)
			{
				if (x2[i] != x1[i])
					return false;
			}
			return true;
		}
	}

	return false;
}


//Word distribution implementations
void word_distribution::add_word(string x)
{
	for (int i = 0; i < words.size(); ++i)
	{
		if (compare(x, words[i].value))
		{
			++words[i].freq;
			return;
		}
	}
	word temp;
	temp.value = x;
	temp.freq = 1;
	words.push_back(temp);
}

void word_distribution::display()
{
	for (int i = 0; i < words.size(); ++i)
	{
		cout << words[i].value << " " << words[i].freq << endl;
	}
}

double word_distribution::magnitude()
{
	double magn = 0.0;
	for (int i = 0; i < words.size(); ++i)
		magn += words[i].freq*words[i].freq;
	return sqrt(magn);
}

int word_distribution::dot_product(word_distribution& words2)
{
	vector<word> w2 = words2.my_words();
	int product = 0;
	if (words.size() >= words2.size())
	{
		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = 0; j < w2.size(); ++j)
			{
				if (words[i].value == w2[j].value)
				{
					product += words[i].freq*w2[j].freq;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < w2.size(); ++i)
		{
			for (int j = 0; j < words.size(); ++j)
			{
				if (w2[i].value == words[j].value)
				{
					product += w2[i].freq*words[j].freq;
					break;
				}
			}
		}
	}
	return product;
}
//End of word distribution implementations