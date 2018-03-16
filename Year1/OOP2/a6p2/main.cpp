#include <iostream>
#include <sstream>
using namespace std;

/*
 * First obj1 was assigned to an uninitialized variable. Then obj3 was pointing to a NULL object when trying to access the toString method. And lastly we can't delete a pointer pointing to NULL.
 */
class Test {
	private:
		double *a;
		int n;
	public:
		Test() {
			a=NULL;
			n=0;
		}
		Test(double *a, int n) {
			this->n = n;
			if (this->a != NULL) {
				delete this->a;
			}
			this->a = new double[n];
			for(int i=0; i<n; i++)
				this->a[i] = a[i];
		}
		string toString() {
			ostringstream ss;
			ss << "Length: " << n << endl << "Elements: ";
			for(int i=0; i<n; i++)
				ss << a[i] << " ";
			ss << endl;
			return ss.str();
		}
		~Test() {
			delete a;
		}
};

int main() {
	Test arr[5];
	double v[3] = {1.2, 2.3, 3.45};
	Test *obj1;
	obj1=&arr[0];
	Test *obj2 = new Test(v, 3);
	Test *obj3 = NULL;
	cout << obj1->toString();
	cout << obj2->toString();
	cout << obj3->toString();
	delete obj1;
	delete obj2;
	delete obj3;
	return 0;
}
