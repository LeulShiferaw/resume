#include <c++\std_lib_facilities.h>

class rabbit
{
public:
	bool active;
	int age_in_month;
public:
	rabbit() :active(false), age_in_month(0){}
	void increment();
};

void rabbit::increment()
{
	++age_in_month;
	if (age_in_month >= 2)
		active = true;
}

int main()
{
	try
	{
		vector<rabbit> rabbit_pop;

		rabbit temp_rab;
		rabbit_pop.push_back(temp_rab);

		while (true)
		{
			for (int i = 0; i < rabbit_pop.size(); ++i)
			{
				if (rabbit_pop[i].active)
				{
					rabbit temp;
					rabbit_pop.push_back(temp);
				}
				rabbit_pop[i].increment();
			}
			cout << rabbit_pop.size() << endl;
			cin.get();
		}
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown error!" << endl;
		return 2;
	}

	
}