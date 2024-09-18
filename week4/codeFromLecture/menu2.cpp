#include <iostream>
#include <cmath>

using namespace std;

const int SPHERE = 1;
const int CUBE = 2;
const int CYLINDER = 3;
const int QUIT = 4;

int main() {
    int menuChoice = 0;

    cout << "1. Sphere\n2.Cube\n3.Cylinder\n4.Quit\nEnter choice: ";
    cin >> menuChoice;

    while (menuChoice != QUIT) {
        if (menuChoice == SPHERE) {
            double radius = 0;
            cout << "Enter radius: ";
            cin >> radius;
            while (radius >= 0) {
                double volume = 4.0 / 3.0 * M_PI * pow(radius, 3);
                cout << "Volume of sphere: " << volume << endl;
            }
        } else cout << "Radius must be >= 0" << endl;

        if (menuChoice == CUBE) {
            double side = 0;
            cout << "Enter side: ";
            cin >> side;
            if (side > 0) {
                double volume = pow(side, 3);
                cout << "Volume of cube: " << volume << endl;
            } else cout << "Side must be >= 0" << endl;
        }
    }
}
