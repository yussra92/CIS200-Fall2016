
#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;

int main()
{
	Circle circle1;
	circle1.setRadius(7);
	cout << circle1.getRadius() << endl;
	cout << circle1.area() << endl;
	cout << circle1.circumference() << endl;

	Circle circle2;
	circle2.setRadius(50);
	cout << circle2.getRadius() << endl;
	cout << circle2.area() << endl;
	cout << circle2.circumference() << endl;

	string input;
	cin >> input;

}