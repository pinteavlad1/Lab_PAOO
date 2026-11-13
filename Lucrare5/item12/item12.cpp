#include <iostream>
#include <string>

using namespace std;

class Customer {
    public:
        string name;
        Customer(const string& name = "none") : name(name) {}
};

//Bad: the copy functions forget the base class part
class BadPriorityCustomer : public Customer {
    public:
        int priority;
        BadPriorityCustomer(const string& name, int priority) : Customer(name), priority(priority) {}

        BadPriorityCustomer(const BadPriorityCustomer& other) : priority(other.priority) {}  //Customer() is called, name = "none"

        BadPriorityCustomer& operator=(const BadPriorityCustomer& other) {
            priority = other.priority;      //name is not copied
            return *this;
        }
};

//Good: the copy functions also copy the base class part
class PriorityCustomer : public Customer {
    public:
        int priority;
        PriorityCustomer(const string& name, int priority) : Customer(name), priority(priority) {}

        PriorityCustomer(const PriorityCustomer& other) : Customer(other), priority(other.priority) {}

        PriorityCustomer& operator=(const PriorityCustomer& other) {
            Customer::operator=(other);
            priority = other.priority;
            return *this;
        }
};

int main() {
    BadPriorityCustomer bad1("Vlad", 1);
    BadPriorityCustomer bad2(bad1);
    cout << "Bad copy:  name = " << bad2.name << ", priority = " << bad2.priority << "\n";

    PriorityCustomer good1("Vlad", 1);
    PriorityCustomer good2(good1);
    cout << "Good copy: name = " << good2.name << ", priority = " << good2.priority << "\n";

    return 0;
}
