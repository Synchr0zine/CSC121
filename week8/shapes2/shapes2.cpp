#include <iostream>
#include <cmath>

using namespace std;

// Function that validates the inputs from the user
double ReadDimension(const string &prompt) {
    double returnValue = 0.0;
    cout << prompt; // Display the required prompt to the user
    cin >> returnValue; // Get the value from the user

    // Input validation loop
    while (cin.fail() || returnValue < 0.0) {
        // If the input is below zero or if cin enters a failure state, clear the buffer and re-prompt
        cout << "Invalid input, please enter a valid value." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << prompt;
        cin >> returnValue;
    }

    return returnValue; // Return the validated input
}

// Cube Class
class Cube {
private:
    double length;

public:
    // Constructor with default value
    Cube(double l = 0) : length(l) {}

    // Setter for length
    void setLength(double l) {
        length = l;
    }

    // Getter for length
    double getLength() const { return length; }

    // Calculate and return volume
    double volume() const { return pow(length, 3); }

    // Calculate and return surface area
    double surfaceArea() const { return 6 * pow(length, 2); }

    // Input method to get length from user
    void input() {
        setLength(ReadDimension("Enter cube length: "));
    }

    // Display method to show volume and surface area
    void display() const {
        cout << "Cube Volume: " << volume() << endl;
        cout << "Cube Surface Area: " << surfaceArea() << endl;
    }
};

// Sphere Class
class Sphere {
private:
    double radius;

public:
    // Constructor with default value
    Sphere(double r = 0) : radius(r) {}

    // Setter for radius
    void setRadius(double r) {
        radius = r;
    }

    // Getter for radius
    double getRadius() const { return radius; }

    // Calculate and return volume
    double volume() const { return (4.0 / 3) * M_PI * pow(radius, 3); }

    // Calculate and return surface area
    double surfaceArea() const { return 4 * M_PI * pow(radius, 2); }

    // Input method to get radius from user
    void input() {
        setRadius(ReadDimension("Enter sphere radius: "));
    }

    // Display method to show volume and surface area
    void display() const {
        cout << "Sphere Volume: " << volume() << endl;
        cout << "Sphere Surface Area: " << surfaceArea() << endl;
    }
};

// Prism Class
class Prism {
private:
    double length, width, height;

public:
    // Constructor with default values
    Prism(double l = 0, double w = 0, double h = 0) : length(l), width(w), height(h) {}

    // Setter for all dimensions
    void setDimensions(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    // Getters for each dimension
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    // Calculate and return volume
    double volume() const { return length * width * height; }

    // Calculate and return surface area
    double surfaceArea() const { return 2 * (length * width + width * height + height * length); }

    // Input method to get all dimensions from user
    void input() {
        setDimensions(
            ReadDimension("Enter prism length: "),
            ReadDimension("Enter prism width: "),
            ReadDimension("Enter prism height: ")
        );
    }

    // Display method to show volume and surface area
    void display() const {
        cout << "Prism Volume: " << volume() << endl;
        cout << "Prism Surface Area: " << surfaceArea() << endl;
    }
};

// Cylinder Class
class Cylinder {
private:
    double radius, height;

public:
    // Constructor with default values
    Cylinder(double r = 0, double h = 0) : radius(r), height(h) {}

    // Setter for both dimensions
    void setDimensions(double r, double h) {
        radius = r;
        height = h;
    }

    // Getters for each dimension
    double getRadius() const { return radius; }
    double getHeight() const { return height; }

    // Calculate and return volume
    double volume() const { return M_PI * pow(radius, 2) * height; }

    // Calculate and return surface area
    double surfaceArea() const { return 2 * M_PI * radius * (radius + height); }

    // Input method to get both dimensions from user
    void input() {
        setDimensions(
            ReadDimension("Enter cylinder radius: "),
            ReadDimension("Enter cylinder height: ")
        );
    }

    // Display method to show volume and surface area
    void display() const {
        cout << "Cylinder Volume: " << volume() << endl;
        cout << "Cylinder Surface Area: " << surfaceArea() << endl;
    }
};

// Cone Class
class Cone {
private:
    double radius, height;

public:
    // Constructor with default values
    Cone(double r = 0, double h = 0) : radius(r), height(h) {}

    // Setter for both dimensions
    void setDimensions(double r, double h) {
        radius = r;
        height = h;
    }

    // Getters for each dimension
    double getRadius() const { return radius; }
    double getHeight() const { return height; }

    // Calculate and return volume
    double volume() const { return (M_PI * pow(radius, 2) * height) / 3; }

    // Calculate and return surface area
    double surfaceArea() const { return M_PI * radius * (radius + sqrt(pow(height, 2) + pow(radius, 2))); }

    // Input method to get both dimensions from user
    void input() {
        setDimensions(
            ReadDimension("Enter cone radius: "),
            ReadDimension("Enter cone height: ")
        );
    }

    // Display method to show volume and surface area
    void display() const {
        cout << "Cone Volume: " << volume() << endl;
        cout << "Cone Surface Area: " << surfaceArea() << endl;
    }
};

// Function to display menu and get user choice
int displayMenu() {
    int choice;
    cout << "\n1. Cube\n2. Sphere\n3. Prism (Right Rectangular)\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice: ";
    cin >> choice;

    // Input validation loop
    while (cin.fail() || choice < 1 || choice > 6) {
        cout << "Invalid input. Enter a choice between 1 and 6: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> choice;
    }
    return choice;
}

int main() {
    int choice = displayMenu();

    // Main program loop, I made it switch instead of if else's in the first program
    while (choice != 6) {
        switch (choice) {
            case 1: {
                Cube cube;
                cube.input();
                cube.display();
                break;
            }
            case 2: {
                Sphere sphere;
                sphere.input();
                sphere.display();
                break;
            }
            case 3: {
                Prism prism;
                prism.input();
                prism.display();
                break;
            }
            case 4: {
                Cylinder cylinder;
                cylinder.input();
                cylinder.display();
                break;
            }
            case 5: {
                Cone cone;
                cone.input();
                cone.display();
                break;
            }
        }
        choice = displayMenu();
    }

    cout << "Thanks for using the shapes program!\n";
    return 0;
}
