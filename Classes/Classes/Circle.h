#pragma once
class Circle {
public:
	Circle();
	double circumference();
	double area();
	void setRadius(double radius);
	double getRadius();

private:
	double radius;
	const double PI = 3.14159;
};