#include <iostream>
#include <cmath>

using namespace std;

const int CUBE = 1;
const int SPHERE = 2;
const int PRISM = 3;
const int CYLINDER = 4;
const int CONE = 5;
const int QUIT = 6;

//Prototyping
double ReadDimension(string prompt);
double CubeArea(double length);
double CubeVolume(double length);
double SphereArea(double radius);
double SphereVolume(double radius);
double PrismArea(double length, double width, double height);
double PrismVolume(double length, double width, double height);
double CylinderArea(double radius, double height);
double CylinderVolume(double radius, double height);
double ConeArea(double radius, double height);
double ConeVolume(double radius, double height);

int main() {
    int menu = 0;

    cout << "1. Cube\n2.Sphere\n3.Prism(Right Rectangular)\n4.Cylinder\n5.Cone\n6.Quit\nEnter choice: ";
    cin >> menu;

    while (menu != QUIT) {
        if (menu == CUBE) {
            double length = ReadDimension("Enter cube length: ");
            cout << "Volume is : " << CubeVolume(length) << endl;
            cout << "Area is : " << CubeArea(length) << endl;
        }

        if (menu == SPHERE) {
            double radius = ReadDimension("Enter sphere radius: ");
            cout << "Volume is : " << SphereVolume(radius) << endl;
            cout << "Area is : " << SphereArea(radius) << endl;
        }

        if (menu == PRISM) {
        }

        if (menu == CYLINDER) {
        }

        if (menu == CONE) {
        }


        if (menu != CUBE && menu != SPHERE && menu != PRISM && menu != CYLINDER && menu != CONE) {
            cout << "Invalid menu choice\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        cout << "1. Cube\n2.Sphere\n3.Prism\n4.Cylinder\n5.Cone\n6.Quit\nEnter choice: ";
        cin >> menu;
    }
}

double ReadDimension(string prompt) {
    double returnValue = 0.0;
    cout << prompt;
    cin >> returnValue;

    while (cin.fail() || returnValue <= 0.0) {
        cout << "Invalid input, please enter again" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << prompt;
        cin >> returnValue;
    }

    return returnValue;
}


double CubeArea(double length) {
    return 6 * pow(length, 2);
}

double CubeVolume(double length) {
    return pow(length, 3);
}

double SphereArea(double radius) {
    return 4 * M_PI * pow(radius, 2);
}

double SphereVolume(double radius) {
    return 4 * (M_PI * pow(radius, 3)) /3;
}

double PrismArea(double length, double width, double height) {
    return 2 * (length * width + height * length + width * height);
}

double PrismVolume(double length, double width, double height) {
    return length * width * height;
}

double CylinderArea(double radius, double height) {
    return 2 * (M_PI * radius * height) + 2 * (M_PI * pow(radius, 2));
}

double CylinderVolume(double radius, double height) {
    return M_PI * pow(radius,2) * height;
}

double ConeArea(double radius, double height) {
    return M_PI * radius * (radius + sqrt(pow(height,2)+pow(radius,2)));
}

double ConeVolume(double radius, double height) {
    return M_PI * pow(radius, 2) * height / 3;
}
