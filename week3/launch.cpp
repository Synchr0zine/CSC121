/*
If a projectile is launched straight into the air, it's height at any point can be calculated by the following formula:
h = v t - 1 / 2 g t2
where h is the height of the projectile in feet
v is the initial velocity of the projectile in feet per second (that is, velocity of the projectile when launched)
g is acceleration due to gravity which is -32
t is the number of seconds that have elapsed
Write a C++ program that will prompt the user for the initial velocity in miles per hour.  The program will need to convert it to feet per second.  The program should also not allow the user to enter a negative value.
Within a loop, starting with the time at 0 and incrementing by .1 seconds per iteration, calculate the height of the projectile.  The output of the program should display the number of seconds in one column and the height of the projectile in feet in the second column.  The numbers in both columns should be left justified with the decimal points lining up.  For example:
0.1     123.456
0.2.    120.123
Once the projectile reaches a height of zero, the program should stop.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

}