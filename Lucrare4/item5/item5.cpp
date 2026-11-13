#include <iostream>
#include <string>

using namespace std;

//1. Empty-looking class: the compiler writes a default constructor,
//   copy constructor, copy assignment operator and destructor for it
class Point {
    public:
        int x = 1;
        int y = 2;
};

//2. If we declare any constructor, the compiler no longer writes the default one
class Person {
    private:
        string name;
    public:
        Person(const string& name) : name(name) {}
};

//3. With a reference (or const) member, the compiler can't write copy assignment,
//   because a reference can't be made to refer to something else
class NamedValue {
    private:
        string& name;
    public:
        NamedValue(string& name) : name(name) {}
};

int main() {
    cout << "=== Generated functions ===\n";
    Point a;                //default constructor
    Point b(a);             //copy constructor
    Point c;
    c = a;                  //copy assignment
    cout << "  b = (" << b.x << ", " << b.y << "), c = (" << c.x << ", " << c.y << ")\n";
    //destructors for a, b, c are called at the end of main

    cout << "\n=== No default constructor ===\n";
    Person p("Vlad");
    //Person q;             //error: no default constructor
    cout << "  Person needs a name to be created\n";

    cout << "\n=== No copy assignment ===\n";
    string s1 = "first", s2 = "second";
    NamedValue n1(s1);
    NamedValue n2(n1);      //copy constructor still works
    //n2 = NamedValue(s2);  //error: copy assignment is deleted
    cout << "  NamedValue can be copied, but not assigned\n";

    return 0;
}
