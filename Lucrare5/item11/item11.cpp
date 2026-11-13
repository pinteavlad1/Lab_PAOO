#include <iostream>

using namespace std;

//Without a self-assignment check: on a = a, delete frees the data
//we are about to copy, so we read freed memory (undefined behavior)
class BadHolder {
    public:
        int* data;
        BadHolder(int value) : data(new int(value)) {}
        ~BadHolder() { delete data; }

        BadHolder& operator=(const BadHolder& other) {
            delete data;
            data = new int(*other.data);    //other.data was just deleted if other is *this
            return *this;
        }
};

//With a self-assignment check: a = a does nothing
class Holder {
    public:
        int* data;
        Holder(int value) : data(new int(value)) {}
        ~Holder() { delete data; }

        Holder& operator=(const Holder& other) {
            if (this == &other) return *this;
            delete data;
            data = new int(*other.data);
            return *this;
        }
};

int main() {
    BadHolder bad(42);
    bad = bad;
    cout << "BadHolder after self-assignment: " << *bad.data << " (expected 42)\n";

    Holder good(42);
    good = good;
    cout << "Holder after self-assignment:    " << *good.data << " (expected 42)\n";

    return 0;
}
