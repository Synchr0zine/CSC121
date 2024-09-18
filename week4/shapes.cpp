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

    cout << "1. Cube\n2.Sphere\n3.Prism\n4.Cylinder\n5.Cone\n6.Quit\nEnter choice: ";
    cin >> menu;

    while (menu != QUIT) {
        if (menu == CUBE) {
            double length = ReadDimension("Enter cube length: ");
            cout << "Volume is : " << CubeVolume(length) << endl;
            cout << "Area is : " << CubeArea(length) << endl;
        }
        if (menu == SPHERE) {
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
    return 6.0 * pow(length, 2);
}

double CubeVolume(double length) {
    return pow(length, 3);
}
