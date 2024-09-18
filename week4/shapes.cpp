#include <iostream>
#include <cmath>

using namespace std;

//Constants as menu options
const int CUBE = 1;
const int SPHERE = 2;
const int PRISM = 3;
const int CYLINDER = 4;
const int CONE = 5;
const int QUIT = 6;

//Prototyping
double ReadDimension(string prompt);
double CubeArea(double length);
double CubeVolume(double length);
double SphereArea(double radius);
double SphereVolume(double radius);
double PrismArea(double length, double width, double height);
double PrismVolume(double length, double width, double height);
double CylinderArea(double radius, double height);
double CylinderVolume(double radius, double height);
double ConeArea(double radius, double height);
double ConeVolume(double radius, double height);
string Line();

int main() {
    int menu = 0; //Menu list variable

    //Display the menu to the user
    cout << "1. Cube\n2. Sphere\n3. Prism(Right Rectangular)\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice: ";
    cin >> menu;

    //Main loop keeps the program running until user inputs quits
    while (menu != QUIT) {
        if (menu == CUBE) { // Cube Area and Volume
            double length = ReadDimension("Enter cube length: ");
            cout << "Cube Volume is : " << CubeVolume(length) << endl;
            cout << "Cube Area is : " << CubeArea(length) << endl;
        }

        if (menu == SPHERE) { //Sphere Area and Volume
            double radius = ReadDimension("Enter sphere radius: ");
            cout << "Sphere Volume is : " << SphereVolume(radius) << endl;
            cout << "Sphere Area is : " << SphereArea(radius) << endl;
        }

        if (menu == PRISM) { //Prism Area and Volume
            double length = ReadDimension("Enter prism length: ");
            double width = ReadDimension("Enter prism width: ");
            double height = ReadDimension("Enter prism height: ");
            cout << "Prism Volume is : " << PrismVolume(length, width, height) << endl;
            cout << "Prism Area is : " << PrismArea(length, width, height) << endl;
        }

        if (menu == CYLINDER) { //Cylinder Area and Volume
            double radius = ReadDimension("Enter cylinder radius: ");
            double height = ReadDimension("Enter cylinder height: ");
            cout << "Cylinder Volume is : " << CylinderVolume(radius, height) << endl;
            cout << "Cylinder Area is : " << CylinderArea(radius, height) << endl;
        }

        if (menu == CONE) { //Cone Area and Volume
            double radius = ReadDimension("Enter cone radius: ");
            double height = ReadDimension("Enter cone height: ");
            cout << "Cone Volume is : " << ConeVolume(radius, height) << endl;
            cout << "Cone Area is : " << ConeArea(radius, height) << endl;
        }

        //Check if the menu choices are valid or not and prompt again if not valid
        if (menu != CUBE && menu != SPHERE && menu != PRISM && menu != CYLINDER && menu != CONE) {
            cout << "Invalid menu choice, please enter input again\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        //Redisplay the menu after the calculations
        cout << Line();
        cout << "1. Cube\n2. Sphere\n3. Prism(Right Rectangular)\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice: ";
        cin >> menu;
    }

    cout << "Thanks for using the shapes program!\n";
    return 0; //End the program
}

//Function that validates the inputs from the user making sure they are within the specs
double ReadDimension(string prompt) {
    double returnValue = 0.0;
    cout << prompt; //Display the required prompt to the user
    cin >> returnValue; //Get the value from the user

    while (cin.fail() || returnValue <= 0.0) {
        //If the input is below zero or if the cin enters a failure state, clears the buffer and re-prompts
        cout << "Invalid input, please enter a correct value." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << prompt;
        cin >> returnValue;
    }

    return returnValue; //Returns the validated input
}


//Functions to calculate area and volume for each shape on the menu

double CubeArea(double length) {
    return 6 * pow(length, 2);
}

double CubeVolume(double length) {
    return pow(length, 3);
}

double SphereArea(double radius) {
    return 4 * M_PI * pow(radius, 2);
}

double SphereVolume(double radius) {
    return 4 * (M_PI * pow(radius, 3)) /3;
}

double PrismArea(double length, double width, double height) {
    return 2 * (length * width + height * length + width * height);
}

double PrismVolume(double length, double width, double height) {
    return length * width * height;
}

double CylinderArea(double radius, double height) {
    return 2 * (M_PI * radius * height) + 2 * (M_PI * pow(radius, 2));
}

double CylinderVolume(double radius, double height) {
    return M_PI * pow(radius,2) * height;
}

double ConeArea(double radius, double height) {
    return M_PI * radius * (radius + sqrt(pow(height,2)+pow(radius,2)));
}

double ConeVolume(double radius, double height) {
    return M_PI * pow(radius, 2) * height / 3;
}

string Line() { //Program that draws a line in the console to separate each calculation for UX improvement
    return "------------------------------------------\n";
}
