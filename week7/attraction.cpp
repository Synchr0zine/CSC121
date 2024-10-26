#include <iostream>
#include <cmath>
#include <iomanip> //required for setprecision and setw

using namespace std;

constexpr double G = 6.67408e-11; //initialize the G constant

// I used the ReadDouble from the previous assignment and changed it up to only accept positive values
double ReadPositiveDouble(const string &prompt) {
    string input; //user's input
    bool validNumber = false; //boolean to check if input is valid or not
    double returnValue = 0.0; //the final double value that is returned
    string noCommas; //placeholder string to hold the number before conversion to double

    while (!validNumber) {
        cout << prompt; //Display the required prompt to the user
        cin >> input; //Get the value from the user

        //setting flags to false before checking
        bool hasDecimal = false;
        bool hasInvalidComma = false;

        //counters for comma, decimals and digits after comma
        int commaCount = 0;
        int decimalCount = 0;
        int digitsAfterComma = 0;

        //assume number is valid for the loop
        validNumber = true;

        for (int i = 0; i < input.length(); i++) {
            //loop through the input string
            if (i == 0) {
                //check the first character
                if (!(isdigit(input[i]) || input[i] == '+' || input[i] == '.')) {
                    validNumber = false; //if first character is not a digit, +, -, or . ,it is invalid
                    break; //break out of loop if input is invalid
                }
            } else {
                //For the characters after the first one, only digits, '.' and ',' are allowed
                if (!isdigit(input[i]) && input[i] != '.' && input[i] != ',') {
                    validNumber = false;
                    break; //break out of loop if invalid character found
                }
            }

            //handle the decimal point
            if (input[i] == '.') {
                decimalCount++; //if there is a decimal point, increase the decimal point count
                if (decimalCount > 1) {
                    validNumber = false; //if there are more than 1 point, it is invalid
                    break; //break out of loop if input is invalid
                }
                hasDecimal = true; //set the boolean to true if decimal point exists
            }

            //handle commas
            if (input[i] == ',') {
                commaCount++; //if there is a comma, increase the commacount
                //Check if the comma has invalid placement
                if (digitsAfterComma == 0 || digitsAfterComma > 3 || hasDecimal) {
                    hasInvalidComma = true; //flag the invalid comma
                    break; //break out of loop
                }
                digitsAfterComma = 0; //reset the digit counter after comma
            } else if (isdigit(input[i])) {
                digitsAfterComma++; //counting the digits between the commas of after the decimal point
            }
        }

        //Handling the invalid input
        if (!validNumber || hasInvalidComma) {
            cout << "Invalid input! Please Enter a Valid Number: " << endl;
            validNumber = false; //reset the flag to retry the loop
        } else {
            //If it is valid, remove the commas from the input string to be able to transform it into a double
            for (int i = 0; i < input.length(); i++) {
                if (input[i] != ',') {
                    noCommas += input[i]; //only adds characters that are not commas
                }
            }
            returnValue = stod(noCommas); //convert the string to double

            // Check if the number is positive
            if (returnValue <= 0) {
                cout << "Invalid input! Please enter a positive number greater than zero: " << endl;
                validNumber = false;
            }
        }
    }
    return returnValue; //return the final value
}

//Function to calculate and display results in a table
void calculateResults(double &radius1, double &radius2, double &mass1, double &mass2, double &distance) {
    //Display the headers of the table
    cout << "Distance (m)   Force (N)" << endl;
    cout << "------------------------" << endl;

    double initialDistance = distance; //assign the distance to initial distance since we are going to be changing it
    while (distance > 0) { //loop to get all the force calculations as distance gets closer
        double distanceBetweenCores = distance + radius1 + radius2; //d = x + r1 + r2
        double force = (G * mass1 * mass2) / pow(distanceBetweenCores, 2); // F = (m1 * m2 / d^2) * G

        //output the current distance and force in a table format
        cout << fixed << setprecision(2) << setw(10) << distance <<
            "   " << scientific << setprecision(4) << force << endl;

        //reduce distance to by 1/100th of itself
        distance -= initialDistance / 100.0;
    }
}

int main() {

    //Get the values from the user while validating them with the ReadPositiveDouble function.
    double radius1 = ReadPositiveDouble("Enter radius of the first planet (m): ");
    double radius2 = ReadPositiveDouble("Enter radius of the second planet (m): ");
    double mass1 = ReadPositiveDouble("Enter mass of the first planet (kg): ");
    double mass2 = ReadPositiveDouble("Enter mass of the second planet (kg): ");
    double distance = ReadPositiveDouble("Enter edge distance (m): ");

    //Pass the values to the calculateResults method
    calculateResults(radius1, radius2, mass1, mass2, distance);

    return 0;
}
