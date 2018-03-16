/*
 * JTSK-320143
 * a1_p4.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include<iostream>
using namespace std;
 
/*
 * The problem was that A doesn't have an empty constructor.
 */

/*
 * Since we inherited using public virtual we have to call the constructors directly from class D.
 */
class A
{
	private:
  		int x;
	public:
  		A(int i) { x = i; }
  		void print() { cout << x; }
};
 
class B: virtual public A
{
	public:
  		B():A(10) {  }
};
 
class C:  virtual public A 
{
	public:
  		C():A(10) {  }
};
 
class D: public B, public C {
	public:
		D():A(10){};
};
 
int main()
{
    D d;
    d.print();
    return 0;
}
