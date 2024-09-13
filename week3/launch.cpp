/*
If a projectile is launched straight into the air, it's height at any point can be calculated by the following formula:
h = v t - 1 / 2 g t2
where h is the height of the projectile in feet
v is the initial velocity of the projectile in feet per second (that is, velocity of the projectile when launched)
g is acceleration due to gravity which is -32
t is the number of seconds that have elapsed
Write a C++ program that will prompt the user for the initial velocity in miles per hour.  The program will need to
convert it to feet per second.  The program should also not allow the user to enter a negative value.
Within a loop, starting with the time at 0 and incrementing by .1 seconds per iteration, calculate the height of the
projectile.  The output of the program should display the number of seconds in one column and the height of the
projectile in feet in the second column.  The numbers in both columns should be left justified with the decimal points
lining up.  For example:
0.1     123.456
0.2.    120.123
Once the projectile reaches a height of zero, the program should stop.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double gravity_ftps = 32; //gravity constant in ft/s^2

int main() {

    //Variables
    double velocity_mph = 0.0, velocity_ftps = 0.0, flight_time = 0.0;
    //Input
    cout << "Enter the initial velocity of the projectile (mp/h):";
    cin >> velocity_mph;

    //Input Check
    while (velocity_mph <0) {
        cout << "Velocity must be greater than zero!\n" << endl;
        cout << "Enter the velocity of the projectile: ";
        cin >> velocity_mph;
    }

    //Conversion from mp/h to fp/s
    velocity_ftps = velocity_mph * 1.467;

    //Calculation of the total flight time
    flight_time = 2.0 * velocity_ftps / gravity_ftps;

    cout << "Total flight time: " << flight_time << endl;

    double seconds = 0.0;
    while (seconds<=flight_time) {

        cout.width(15);
        cout.precision(1);
        cout.setf(ios::fixed);
        cout.setf(ios::right);
        cout.setf(ios::showpoint);
        cout << seconds << " seconds";

        double height_ftps = velocity_ftps * seconds - gravity_ftps * pow(seconds, 2) / 2;

        cout.width(15);
        cout.precision(3);
        cout.setf(ios::fixed);
        cout.setf(ios::right);
        cout.setf(ios::showpoint);
        cout << height_ftps << " ft" << endl;


        seconds += 0.10;
    }

    cout.width(15);
    cout.precision(1);
    cout.setf(ios::fixed);
    cout.setf(ios::right);
    cout.setf(ios::showpoint);
    cout << flight_time << " seconds";

    cout.width(15);
    cout.precision(3);
    cout.setf(ios::fixed);
    cout.setf(ios::right);
    cout.setf(ios::showpoint);
    cout << "0.000" << " ft" << endl;

    return 0;


}