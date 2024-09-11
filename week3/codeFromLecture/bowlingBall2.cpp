#include <iostream>
#include <cmath>

using namespace std;

const double gravity_mps=9.8;

int main()
{
    // Variables
    double height_m=0.0, current_m=0.0, seconds=0.0;

    // Input
    cout << "Enter building height in meters: ";
    cin >> height_m;

    current_m=height_m - .5 * gravity_mps * pow(seconds,2.0);
    cout << "Seconds\tMeters\n";
    while (current_m >= 0.0) {
        cout << seconds << "\t" << current_m << endl;
        //seconds=seconds+.1;
        seconds += .1;
        // += -= *= /= %=
        current_m=height_m - .5 * gravity_mps * pow(seconds,2.0);
    }
    cout << seconds << "\t" << current_m << endl;
    return 0;
}
