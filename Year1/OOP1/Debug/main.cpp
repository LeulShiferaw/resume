#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int peak(int *A, const int &s, const int &e)
{
	if(s+1==e)
		return A[s];
	else if(A[e-1] >= A[e-2])
		return e-1;
	int m = (s+e)/2;
	if(A[m] < A[m-1])
		return peak(A, s, m);
	else if(A[m] < A[m+1])
		return peak(A, m, e);
	else return m;

	return 1;//To avoid warnings
}

int peak_n(int *A, const int &n)
{
	if(n==1)
		return A[0];
	for(int i = 0; i<n; ++i)
	{
		if(i == 0 && A[0] >= A[1])
			return A[0];
		else if(i == n-1)
			return A[n-1];
		else if(A[i] >= A[i-1] && A[i] >= A[i+1])
			return A[i];
	}
	return 1; // Avoid warnings
}

int rand_range(const int &l, const int &h)
{
	return rand() % (h-l+1) + l;
}

void displayA(int *A, const int &n)
{
	for(int i = 0; i<n; ++i)
		cout << A[i] << " ";
	cout << endl;
}

//r-result, n-number of terms
void permute(vector<string> & store, string curr, const int &r, const int &n, const int &mn)
{
	if(curr.size() >= n)
	{
		int sum = 0;
		for(int i = 0; i<curr.size(); ++i)
			sum += curr[i] - '0';
		if(sum == r)
			store.push_back(curr);
		return;
	}

	for(int i = 1; i <= mn; ++i)
		permute(store, curr + (char)('0' + i), r, n, mn);
	return;
}

int main()
{
	srand(time(0));
	int n = 4;

	vector<string> s;

	permute(s, "", 13, n, 6);

	for(int i = 0; i<s.size(); ++i)
		cout << s[i] << endl;

	return 0;
}
