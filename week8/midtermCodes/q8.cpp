#include <iostream>
#include <cctype>

using namespace std;

// Function to filter out non-alphabetic characters
string filterString(const string& input) {
    string filtered;
    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];
        if (isalpha(ch)) { // Check if the character is alphabetic
            filtered += tolower(ch); // Convert to lowercase and add to the filtered string
        }
    }
    return filtered;
}

// Function to check if the string is a palindrome
bool isPalindrome(const string& str) {
    string filteredStr = filterString(str);
    string reversedStr;

    // Manually reverse the filtered string
    for (int i = filteredStr.length() - 1; i >= 0; --i) {
        reversedStr += filteredStr[i]; // Add characters in reverse order
    }

    return filteredStr == reversedStr; // Check for palindrome
}

int main() {
    string input;

    // Prompt the user for a string
    cout << "Enter a string: ";
    getline(cin, input); // Read the entire line, (In here I first tried to use the cin, but it only reads until first space)

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}