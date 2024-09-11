/*
* Program to calculate volume of a sphere using user input of radius
*/

#include <iostream>
#include <cmath>

int main()
{
    // Variables
    double radius = 0.0;

    // Input
    std::cout << "Enter radius in inches:";
    std::cin >> radius;

    // Processing
    // >= <= < > == !=
    if (radius >= 0.0) {
        double volume=4.0 / 3.0 * M_PI * pow(radius,3.0);
        std::cout << "Volume is " << volume << " cubic inches\n";

    }

    //std::cout << volume << std::endl;

    return 0;
}
