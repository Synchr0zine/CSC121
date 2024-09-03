/*
You want to calculate how tall a building is and have determined that the best way is to roll a bowling ball off the
roof of the building and time how many seconds it takes to hit the ground.  The height of the building in meters can be
calculated as follows:

h = 1/2 g t2
h is the height of the building in meters
g is acceleration due to gravity which is equal to 9.8
t is the number of seconds it takes the bowling ball to hit the ground
Write a C++ program that will prompt the user for the number of seconds and will calculate the height of the building.
*/


# include <iostream>
# include <cmath>

using namespace std;

const double gravity = 9.8;

int main() {
    double seconds = 0.0;

    cout<<"Enter the number of seconds: ";
    cin>>seconds;

    double height = (gravity*pow(seconds,2))/2;

    cout<<"The height of the building is: "<<height<<" meters."<<endl;

    return 0;

}