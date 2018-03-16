/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#define PI 3.14159265358979323846
#include <string>

class Shape {			// base class
	protected:   				// protected access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name  

		//Setters
		void set_name(const std::string &n){name = n;}
		
		//Getters
		std::string get_name(){return name;}
};

class CenteredShape : public Shape {  // inherits from Shape
	protected: 
		double x,y;  // the center of the shape
	public:
		CenteredShape(const std::string&, double, double);  // usual three constructors
		CenteredShape();
		CenteredShape(const CenteredShape&);
		void move(double, double);	// moves the shape, i.e. it modifies it center

		//Setters
		void set_x(const double &x){this->x = x;}
		void set_y(const double &x){y = x;}

		//Getters
		double get_x(){return x;}
		double get_y(){return y;}
};

class RegularPolygon : public CenteredShape { // a regular polygon is a centered_shape with a number of edges
	protected: 
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon();
		RegularPolygon(const RegularPolygon&);

		//Setters
		void set_edges(const int &x){EdgesNumber = x;}

		//Getters
		int get_edges(){return EdgesNumber;}
};

class Circle : public CenteredShape {  // a Circle is a shape with a center and a radius
	protected:
		double Radius;
	public:
		Circle(const std::string&, double, double, double);
		Circle();
		Circle(const Circle&);

		//Setters
		void set_radius(const double &x){Radius = x;}
		
		//Getters
		double get_radius(){return Radius;}

		double perimeter();
		double area();
};
  
class Rectangle : public RegularPolygon
{
protected:
	double w, h;
public:
	Rectangle();
	Rectangle(const std::string &, double, double, const double&, const double&);
	Rectangle(const Rectangle &);

	//Setters
	void set_w(const double &x){w = x;}
	void set_h(const double &x){h = x;}

	//Getters
	double get_w(){return w;}
	double get_h(){return h;}

	double perimeter();
	double area();
};

class Square : public Rectangle
{
protected:
	double s;
public:
	Square();
	Square(const std::string &, double, double, const double &);
	Square(const Square &);

	//Setters
	void set_s(const double &x){s = x;}

	//Getters
	double get_s(){return s;}
};

#endif