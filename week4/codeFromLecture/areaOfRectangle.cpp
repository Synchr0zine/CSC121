#include <iostream>
#include <string>
#include <climits>

using namespace std;

double ReadDimension(string prompt); //prototyping
double Area(double l, double w);

int main() {
    double length = ReadDimension("Length:");
    double width = ReadDimension("Width:");

    cout << "Area is: " << Area(length,width) << endl;
    return 0;
}

double Area(double l, double w) {
    return l*w;
}

double ReadDimension(string prompt) {
    double returnValue = 0.0;
    cout << prompt;
    cin >> returnValue;

    while (cin.fail()) {
        cerr << "Can not read input" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << prompt;
        cin >> returnValue;
    }

    return returnValue;
}
