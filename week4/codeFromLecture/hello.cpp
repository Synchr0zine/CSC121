#include <iostream>
#include <string>

using namespace std;

int main() {
    /*
    char letter1 = 'H';
    char letter2 = 'e';
    char letter3 = 'l';
    char letter4 = 'l';
    char letter5 = 'o';
    char letter6 = '!';

    std::cout << letter1 << letter2 << letter3 << letter4 << letter5 << letter6 << std::endl;
    */

    /*
    std::string output = "Hello!";
    std::cout << output << std::endl;
    return 0;
    */

    /*
    //cin will read until it encounters the first whitespace character (space, return, tab)
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello " << name <<endl;
    */

    /*
    //getline reads until it encounters an enter key
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!\n";
    */

    /*
    string firstName, lastName;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Your initials are " << firstName[0] << lastName[0] << endl;
    */

    string input;
    cout << "Please enter a string: ";
    getline(cin, input);

    string output = input;
    long stringLength = output.length();
    long index = 0;
    while (index < stringLength) {
        if (output[index] == ' ') {
            output[index] = '_';
        }
        index++;
    }


        cout << "Original: " << input << endl;
        cout << "Modified: " << output << endl;


        return 0;

}
