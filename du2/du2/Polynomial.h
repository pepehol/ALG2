#pragma once
#include <iostream>
#include <vector>
#include <string>

class Polynomial
{
private:
	std::vector<double> polynomial;

public:
	Polynomial();
	Polynomial(double a0);
	Polynomial(double a0, double a1);
	Polynomial(double a0, double a1, double a2);
	Polynomial(std::vector<double> A);

	double getCoefficient(const unsigned int n);
	unsigned int getDegreeOfPolynomian();
	double polynomianValueCalculation(double x0);
	Polynomial Add(Polynomial other);
	void showPolynomian(std::string p);
};

