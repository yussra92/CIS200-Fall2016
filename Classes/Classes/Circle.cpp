#include "Circle.h"

Circle::Circle()
{
	setRadius(0.0);
}

double Circle::circumference()
{
	return PI * 2 * radius;
}

double Circle::area()
{
	return PI * radius * radius;
}

void Circle::setRadius(double r)
{
	if (r > 0)
	{
		radius = r;
	}
	else
	{
		radius = 0.0;
	}
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getVolume()
{
	return 4.0/3.0*radius*radius*radius*PI;
}
