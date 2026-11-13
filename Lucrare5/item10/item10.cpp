#include <iostream>

using namespace std;

class Number {
    public:
        int value;
        Number(int value) : value(value) {}

        //Return a reference to *this so assignments can be chained
        Number& operator=(const Number& other) {
            value = other.value;
            return *this;
        }

        //Same convention for +=, -=, *=, etc.
        Number& operator+=(const Number& other) {
            value += other.value;
            return *this;
        }
};

//Assignment that returns void: works alone, but can't be chained
class BadNumber {
    public:
        int value;
        BadNumber(int value) : value(value) {}

        void operator=(const BadNumber& other) {
            value = other.value;
        }
};

int main() {
    Number a(1), b(2), c(3);

    a = b = c;              //b = c returns b, then a = b
    cout << "a = b = c:  a = " << a.value << ", b = " << b.value << "\n";

    (a += b) += c;          //a += b returns a, then a += c
    cout << "(a += b) += c:  a = " << a.value << "\n";

    BadNumber x(1), y(2), z(3);
    x = y;                  //works
    //x = y = z;            //error: y = z returns void, can't assign void to x
    cout << "BadNumber x = y:  x = " << x.value << "\n";

    return 0;
}
