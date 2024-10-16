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

using namespace std;

double ReadDouble(string prompt) {
    string input;
    bool validNumber = false;
    double returnValue = 0.0;

    while (!validNumber) {
        cout << prompt; //Display the required prompt to the user
        cin >> input; //Get the value from the user

        bool hasDecimal = false;
        bool hasComma = false;
        bool isNegative = false;

        int commaCount = 0;
        int decimalCount = 0;
        int digitsAfterComma = 0;

        validNumber = true; //change

        for (int i = 0; i < input.length(); i++) {
            if (i == 0) {
                if (!(isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '.')) {
                    validNumber = false;
                    break;
                }
                if (input[i] == '-') isNegative = true;
            } else {
                if (!isdigit(input[i]) && input[i] != '.' && input[i] != ',') {
                    validNumber = false;
                    break;
                }
            }

            if (input[i] == '.') {
                decimalCount++;
                if (decimalCount == 1) {
                    validNumber = false;
                    break;
                }
                hasDecimal = true;
            }

            if (input[i] == ',') {
                hasComma = true;

            }
        }
    }
