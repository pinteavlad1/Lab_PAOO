#include "Dsu.hpp"
#include <iostream>

using namespace std;

Dsu::Dsu(int n) : N(n) {
    cout << "Normal constructor called\n";
    nodes.resize(N);
    for (int i = 0; i < N; ++i) {
        nodes[i] = new Node{-1, 0};
    }
}

//Sterge nodurile pointate de elementele vectorului nodes
#ifndef NO_DESTRUCTOR
Dsu::~Dsu() {
    cout << "Destructor called\n";
    for (Node* node : nodes) {
        delete node;
    }
}
#endif

//Se copieza valorile din vectorul obiectului other in vectorul nodes 
//(Se creeaza new nodes deci sunt obiecte separate)
#ifndef NO_COPY_CONSTRUCTOR
Dsu::Dsu(const Dsu& other) : N(other.N) {
    cout << "Copy constructor called\n";
    for (Node* node : other.nodes) {
        nodes.push_back(new Node{node->parentIndex, node->rank});
    }
}
#endif

//Valorile(adresele) din vectorul obiectului temporar sunt mutate in vectorul nodes
//Folosim std::move
#ifndef NO_MOVE_CONSTRUCTOR
Dsu::Dsu(Dsu&& other) noexcept : N(other.N), nodes(move(other.nodes)) {
    //Cout slows down code
    //cout << "Move constructor called\n";
}
#endif

int Dsu::find(int x) {

    if (nodes[x]->parentIndex == -1) {
        return x;
    }
    nodes[x]->parentIndex = find(nodes[x]->parentIndex);
    return nodes[x]->parentIndex;
}

void Dsu::join(int x, int y) {

    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        return;
    }
    if (nodes[rootX]->rank < nodes[rootY]->rank) {
        nodes[rootX]->parentIndex = rootY;
    } 
    else if (nodes[rootX]->rank > nodes[rootY]->rank) {
        nodes[rootY]->parentIndex = rootX;
    } 
    else {
        nodes[rootY]->parentIndex = rootX;
        nodes[rootX]->rank++;
    }
}
