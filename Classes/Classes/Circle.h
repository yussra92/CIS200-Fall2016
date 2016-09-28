#pragma once
class Circle {
public:
	Circle();
	double circumference();
	double area();
	void setRadius(double radius);
	double getRadius();
	double getVolume();
	const double PI = 3.14159;

private:
	double radius;
	
};