#pragma once
#include <vector>

using namespace std;


class Dsu {
    private:
        struct Node {
            int parentIndex;
            int rank;
        };
        vector<Node*> nodes;
        int N;
    public:
        Dsu(int n);
#ifndef NO_DESTRUCTOR
        ~Dsu();
#endif
#ifndef NO_COPY_CONSTRUCTOR
        Dsu(const Dsu& other);
#endif
#ifndef NO_MOVE_CONSTRUCTOR
        Dsu(Dsu&& other) noexcept;
#endif
        int find(int x);
        void join(int x, int y);
};