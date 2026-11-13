#include <iostream>

using namespace std;

//1. Old way: declare copy functions private and don't define them
//   - outside code gets a compile error (private)
//   - members/friends get a link error (no definition)
class HomeForSale {
    public:
        HomeForSale() {}
    private:
        HomeForSale(const HomeForSale&);
        HomeForSale& operator=(const HomeForSale&);
};

//2. Base class that does the same thing once, so other classes can reuse it
//   The error now always appears at compile time
class Uncopyable {
    protected:
        Uncopyable() {}
        ~Uncopyable() {}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class Apartment : private Uncopyable {
};

//3. Modern way (C++11): mark the functions as deleted
class House {
    public:
        House() {}
        House(const House&) = delete;
        House& operator=(const House&) = delete;
};

int main() {
    cout << "=== Private and not defined ===\n";
    HomeForSale h1;
    //HomeForSale h2(h1);   //error: copy constructor is private
    cout << "  HomeForSale can't be copied\n";

    cout << "\n=== Uncopyable base class ===\n";
    Apartment a1;
    //Apartment a2(a1);     //error: base class copy constructor is private
    cout << "  Apartment can't be copied\n";

    cout << "\n=== = delete ===\n";
    House house1, house2;
    //house1 = house2;      //error: copy assignment is deleted
    cout << "  House can't be copied\n";

    return 0;
}
