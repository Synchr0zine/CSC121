#include <iostream>
#include <cctype>

using namespace std;

string numberConverter(string input) { //function to convert numbers to '#' sign
    for (int i = 0; i < input.length(); i++) { //loop through the characters on the string
        if (isdigit(input[i])) { // if the current digit is a number,
            input[i] = '#'; // replace it with a #
        }
    }
    return input; //return the converted string
}

int main() {

    string input;

    cout << "Please enter a string: ";
    cin >> input;

    cout << "Converted string: " <<numberConverter(input);

}