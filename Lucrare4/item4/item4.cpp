#include <iostream>
#include <string>
#include "FileSystem.hpp"

using namespace std;

//Initialization list: members are constructed directly with the given values
//(instead of being default-constructed and then assigned in the constructor body)
class Student {
    private:
        string name;
        int age;
    public:
        Student(const string& name, int age) : name(name), age(age) {}
        void print() const { cout << "  " << name << ", " << age << " years old\n"; }
};

//Globals that use FileSystem before main()
//tfsGlobal may not be constructed yet at this point
int disksBad = tfsGlobal.numDisks();
//tfs() constructs the object on the first call, so it is always initialized
int disksGood = tfs().numDisks();

int main() {
    cout << "=== Built-in types ===\n";
    int x = 0;              //initialized manually (without "= 0" the value would be undefined)
    cout << "  x = " << x << "\n";

    cout << "\n=== Initialization list ===\n";
    Student st("Vlad", 21);
    st.print();

    cout << "\n=== Globals from different files ===\n";
    cout << "  global object:         " << disksBad << " disks (expected 4)\n";
    cout << "  local static function: " << disksGood << " disks (expected 4)\n";

    return 0;
}
