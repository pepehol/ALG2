#include "Polynomial.h"

Polynomial::Polynomial()
{
	this->polynomial.push_back(0);
}

Polynomial::Polynomial(double a0)
{
	this->polynomial.push_back(a0);
}

Polynomial::Polynomial(double a0, double a1)
{
	this->polynomial.push_back(a0);
	this->polynomial.push_back(a1);
}

Polynomial::Polynomial(double a0, double a1, double a2)
{
	this->polynomial.push_back(a0);
	this->polynomial.push_back(a1);
	this->polynomial.push_back(a2);
}

Polynomial::Polynomial(std::vector<double> A)
{
	this->polynomial = A;
}

double Polynomial::getCoefficient(const unsigned int n)
{
	return this->polynomial[n];
}

unsigned int Polynomial::getDegreeOfPolynomian()
{
	return this->polynomial.size() - 1;
}

double Polynomial::polynomianValueCalculation(double x0)
{
	double p = 0;

	for (int i = this->polynomial.size() - 1; i >= 0; i--)
	{
		p = x0 * p + this->polynomial[i];
	}

	return p;
}

Polynomial Polynomial::Add(Polynomial other)
{
	std::vector<double> helper;

	unsigned int i = 0;

	if (this->polynomial.size() >= other.polynomial.size())
	{
		for (i; i <= other.polynomial.size() - 1; i++)
		{
			helper.push_back(other.polynomial[i] + this->polynomial[i]);
		}

		for (i; i <= this->polynomial.size() - 1; i++)
		{
			helper.push_back(this->polynomial[i]);
		}
	}
	else
	{
		for (i; i <= this->polynomial.size() - 1; i++)
		{
			helper.push_back(this->polynomial[i] + other.polynomial[i]);
		}

		for (i; i <= other.polynomial.size() - 1; i++)
		{
			helper.push_back(other.polynomial[i]);
		}
	}

	Polynomial p(helper);

	return p;
}

void Polynomial::showPolynomian(std::string p)
{
	std::cout << p << "(x) = ";

	for (int i = this->polynomial.size() - 1; i >= 0; i--)
	{
		if (this->polynomial[i] == 0)
		{
			continue;
		}

		if (this->polynomial[i] < 0 && i != this->polynomial.size() - 1)
		{
			std::cout << "( ";
		}

		std::cout << this->polynomial[i];


		if (i != 0)
		{
			std::cout<< "x^" << i;

			if (this->polynomial[i] < 0 && i != this->polynomial.size() - 1)
			{
				std::cout << " )";
			}

			std::cout << " + ";
		}

		if (this->polynomial[i] < 0 && i == 0)
		{
			std::cout << " )";
		}
	}

	std::cout << std::endl;
}