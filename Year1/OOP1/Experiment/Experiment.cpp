#include <iostream>
#include <string>

using namespace std;

bool has_five(int &n)
{
    while(n!=0)
    {
        if(n%10 == 5)
            return true;
        n/=10;
    }
    return false;
}

int main(int argc, char ** argv)
{
    int n, s = 2, e = 189, c = 0;
    for(int i = s; i<e; ++i)
        if(!has_five(n))
        {
            cout << n << endl;
            ++c;
        }
    return 0;
}