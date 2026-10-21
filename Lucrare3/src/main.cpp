#include <iostream>
#include <chrono> 
#include "Dsu.hpp"

using namespace std;

int main() {
    
    Dsu dsu(6);
    dsu.join(0, 1);

    //Exemplu copy constructor
    Dsu dsu2 = dsu;
    dsu2.join(1, 2);
    dsu.join(3, 2);
    cout << "In dsu2, 2 are root " << dsu2.find(2) << endl;
    cout << "In dsu, 2 are root " << dsu.find(2) << endl;
    cout << "Sunt obiecte distince\n\n";

    //Exemplu eficienta move constructor

    auto begin = chrono::high_resolution_clock::now();

    Dsu dsuMare = Dsu(1000000);

    auto end = chrono::high_resolution_clock::now();    
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    cout << "Timp: " << duration << " [ms]\n";

    //Destructor se apeleaza singur la final de main
    return 0;
}