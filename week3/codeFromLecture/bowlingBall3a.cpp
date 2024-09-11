#include <iostream>
#include <cmath>

using namespace std;

const double gravity_mps=9.8;
const long numberOfIncrements=20;

int main()
{
    // Variables
    double height_m=0.0, current_m=0.0, seconds=0.0,
           totalSeconds=0.0, increment=0.0;

    // Input
    cout << "Enter building height in meters: ";
    cin >> height_m;
    while (height_m < 0.0) {
        cout << "Error! height must be >= 0\n";
        cout << "Enter building height in meters: ";
        cin >> height_m;
    }

    totalSeconds=sqrt(2*height_m/gravity_mps);
    cout << "Total Seconds: " << totalSeconds << endl;
    increment=totalSeconds / numberOfIncrements;
    cout << "Increment: " << increment << endl;

    current_m=height_m - .5 * gravity_mps * pow(seconds,2.0);

    int loop=0; //loop control variable
    while (loop <= numberOfIncrements) {
        //cout << seconds << "\t" << current_m << endl;

        cout.width(15);
        cout.precision(4);
        cout.setf(ios::fixed);
        cout.setf(ios::right);
        cout.setf(ios::showpoint);
        cout << loop;

        cout.width(15);
        cout.precision(4);
        cout.setf(ios::fixed);
        cout.setf(ios::right);
        cout.setf(ios::showpoint);
        cout << seconds;

        cout.width(15);
        cout.precision(4);
        cout.setf(ios::fixed | ios::right | ios::showpoint);
        cout << current_m << endl;
        //seconds=seconds+increment;
        seconds += increment;
        current_m=height_m - .5 * gravity_mps * pow(seconds,2.0);
        //loop += 1;
        loop++;  // loop--   ++loop --loop autoincrement/autodecrement
    }
    return 0;
}
