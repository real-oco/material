#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Declare friend function
    friend void printLength(Box b);
};

// Friend function definition (not a member of Box)
void printLength(Box b) {
    // Can access private member 'length'
    cout << "Length of the box is: " << b.length << endl;
}

int main() {
    Box box1(10);
    printLength(box1);  // Works because printLength is a friend
    return 0;
}
