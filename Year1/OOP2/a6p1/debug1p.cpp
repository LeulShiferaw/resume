/*
  CH08-320143
  a5_p1.cpp
  Leul Shiferaw
  l.shiferaw@jacobs-university.de
*/

#include <iostream>
using namespace std;

//With gdb I first entered the start command to run it line by line.
//Then I used the next command until I got to the find function.
//To enter the find function I used the step command. 
//In the find function I printed i in each iteration using the print command
//from that I saw that it was accessing i[nr] which is not supposed to be accessed.
//If I enter 0 as the value to be searched even if it doesn't have the element stored in the array
//it will return n
//This is because it accesses the nth element which is automatically 0.
//Also since v has multiple elements the delete command is supposed to be "delete []v" not "delete v"
int find(int a[], int nr, int el) {
	for(int i=0; i<=nr; i++)//It is suppose to be i<nr
		if (a[i] == el)
			return i;
	return -1;
}

int main() {
	int n, val;
	cout << "n=";
	cin >> n;
	int *v=new int[n];
	cout << "Elements the elements of array:" << endl;
	for(int i=0; i<n; i++)
		cin >> v[i];
	cout << "val=";
	cin >> val;
	int result = find(v, n, val);
	cout << "Position of the searched element=" << result << endl;
	delete v;
	return 0;
}
