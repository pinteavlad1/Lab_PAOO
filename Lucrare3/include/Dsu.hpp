#pragma once
#include <vector>

using namespace std;


class Dsu {
    private:
        struct Node {
            Node* parent;
            int rank;
        };
        vector<Node*> nodes;  
};