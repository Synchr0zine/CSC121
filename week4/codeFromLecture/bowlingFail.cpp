#include <iostream>
#include <cmath>

using namespace std;

const double GRAVITY_MPS=9.8;

int main()
{
    // variables
    double height_m=0.0, seconds=0.0;

    // input
    cout << "Enter height in meters:";
    cin >> height_m;

    /*if (! cin.fail() || cin.good()) {
        // processing
        seconds=sqrt( 2.0 * height_m / GRAVITY_MPS);

        // output
        cout << "Seconds: " << seconds << endl;
    }else cout << "Error, cant read input";
    */

    while (cin.fail() || height_m<0) {
        cout << "Error! Cant read input or negative number has been entered" << endl;
        cin.clear(); //clears the fail flags
        cin.ignore(INT_MAX,'\n'); //clears the input buffer
        cout << "Enter height in meters: ";
        cin >> height_m;
    }

    // processing
    seconds=sqrt( 2.0 * height_m / GRAVITY_MPS);

    // output
    cout << "Seconds: " << seconds << endl;

    return 0;

}
