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