#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int menuChoice = 0;

    cout << "1. Sphere\n2.Cube\nEnter choice: ";
    cin >> menuChoice;

    if (menuChoice ==1) {
        double radius=0;
        cout << "Enter radius: ";
        cin >> radius;
        if(radius>0){
            double volume = 4.0 / 3.0 * M_PI * pow(radius,3);
            cout << "Volume of sphere: " << volume << endl;
        }else cout <<"Radius must be >= 0" << endl;

        if(menuChoice==2) {
            double side=0;
            cout << "Enter side: ";
            cin >> side;
            if(side>0){
                double volume  = pow(side,3);
                cout << "Volume of cube: " << volume << endl;

            }else cout <<"Side must be >= 0" << endl;


        }
    }
}