/*
 * JTSK-320143
 * a1_p3.cpp
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

/*
 * The problem was that when class D inherited from both B and C it inherited the print function twice. 
 * The compiler didn't know which one to choose.
 */

/*
 * The solution is to use public virtual instead of just public. That makes them inherit separately.
 */
#include<iostream>

using namespace std;
 
class A
{
	private:
		int x;
	public:
		void setX(int i) {x = i;}
		void print() { cout << x; }
};
 
class B:  public virtual A
{
	public:
		B()  { setX(10); }
};
 
class C:  public virtual A  
{
	public:
		C()  { setX(20); }
};
 
class D: public B, public C {
};
 
int main()
{
    D d;
    d.print();
    return 0;
}
