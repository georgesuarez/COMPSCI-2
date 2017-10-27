/*
	Write functions
		double sphere_volume(double r);
		double sphere_surface(double r);
		double cylinder_volume(double r, double h);
		double cylinder_surface(double r, double h);
		double cone_volume(double r, double h);
		double cone_surface(double r, double h);

	that compute the volume and surface area of a sphere with radius r, a cylinder with
	a circular base with radius r and height h, and a cone with a circular base with radius
	r and height h. Then write a program that prompts the user for the values of r and h,
	calls the six functions, and prints the results.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Function Declarations
double sphere_volume(double);
// sphere_volume - calculates the volume of the sphere
// @param double - the radius of the sphere
// @returns double - the  volume of the sphere

double sphere_surface(double);
// sphere_surface - calculates the surface area of the sphere
// @param double - the radius of the sphere
// @returns double - the radius of the sphere

double cylinder_volume(double, double);
// cylinder_volume - calculates the volume of the cylinder
// @param double - radius of the cylinder
// @param double - height of the cylinder
// @returns double - the volume of the cylinder

double cylinder_surface(double, double);
// cylinder_surface - calculates the surface area of the cylinder
// @param double - the radius of the cylinder
// @param double - the height of the cylinder
// @returns double - the surface area of the cylinder

double cone_volume(double, double);
// cylinder_volume - calculates the volume of the cone
// @param double - radius of the cone
// @param double - height of the cone
// @returns double - the volume of the cone

double cone_surface(double, double);
// cone_surface - calculates the surface area of the cone
// @param double - the radius of the cone
// @param double - the height of the cone
// @returns double - the surface area of the cone

const float PI = 3.14159;

int main()
{

	double r, h;

	cout << "Enter the radius: ";
	cin >> r;

	cout << "Enter the height: ";
	cin >> h;
	cout << endl;

	cout << "Sphere Volume: " << sphere_volume(r) << endl;
	cout << "Sphere Surface Area: " << sphere_surface(r) << endl;
	cout << "Cylinder Volume: " << cylinder_volume(r, h) << endl;
	cout << "Cylinder Surface: " << cylinder_surface(r, h) << endl;
	cout << "Cone Volume: " << cone_volume(r, h) << endl;
	cout << "Cone Surface Area: " << cone_surface(r, h) << endl;

	return 0;
}

// Function Declarations

double sphere_volume(double r)
{
	return (4.0 / 3.0) * PI * pow(r, 3);
}

double sphere_surface(double r)
{
	return 4.0 * PI * pow(r, 2);
}

double cylinder_volume(double r, double h)
{
	return PI * pow(r, 2) * h;
}

double cylinder_surface(double r, double h)
{
	return (2.0 * PI * r * h) + (2.0 * PI * pow(r, 2));
}

double cone_volume(double r, double h)
{
	return (1.0 / 3.0) * PI * (r * r) * h;
}

double cone_surface(double r, double h)
{
	return PI * r * (r + sqrt(h * h + r * r));
}