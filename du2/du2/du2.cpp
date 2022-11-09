// du2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
// Josef Holis
// DU2, ALG2

#include <iostream>
#include <vector>

#include "Polynomial.h"

int main()
{
    std::vector<double> pol1 = { 4, 5, -1, 7, 0, 3 };
    
    Polynomial P(pol1);

    P.showPolynomian("P");

    std::cout << "a2 = " << P.getCoefficient(2) << "\n";

    std::cout << "Degree of polynomian = " << P.getDegreeOfPolynomian() << "\n";

    std::cout << "Calculation of the polynomian value P(5) = " << P.polynomianValueCalculation(5) << "\n";
    
    
   
    std::vector<double> pol2 = { -3, 1, 0, -1, 0, 0, 4 };

    Polynomial Q(pol2);

    std::cout << "\nSum of two polynomials: \n";
    P.showPolynomian("P");
    Q.showPolynomian("Q");

    Polynomial R = P.Add(Q);

    R.showPolynomian("R");

    return 0;
}
