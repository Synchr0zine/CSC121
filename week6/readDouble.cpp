/*
    In this assignment we are going to rewrite the ReadDimension function to make it more user-friendly.  Instead of
    reading a value into a double, read the users input into a string.  Using the functions found in cctype, parse the
    string to validate that the input is a valid real number.  It should use the following rules

    The first character can be a number, +, -, or a decimal point
    All other characters can be numeric, a comma or a decimal point
    Any commas must be in their proper location (ie, separating hundreds from thousands, from millions, etc.)
    No commas after the decimal point
    Only one decimal point in the number

Additionally, after verifying that the input is valid, the function should convert the string into a double and return
that value.
Create a main function where you will call the ReadDouble function and display the value that is returned.  Run this
program several times demonstrating its error checking functionality.
 */


#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

double ReadDouble(string prompt); //prototyping

int main() {
    //Calling the ReadDouble function (I added setprecision here because cout was throwing the rest of the
    //numbers away when it was longer than 7 digits)
    cout << setprecision(15)<< ReadDouble("Enter a number: ");
}

double ReadDouble(string prompt) {
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

        for (int i = 0; i < input.length(); i++) { //loop through the input string
            if (i == 0) { //check the first character
                if (!(isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '.')) {
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
                    noCommas+=input[i]; //only adds characters that are not commas
                }
            }
            returnValue = stod(noCommas); //convert the string to double
        }
    }
    return returnValue; //return the final value
}
