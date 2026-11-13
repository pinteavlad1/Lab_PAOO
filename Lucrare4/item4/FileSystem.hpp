#pragma once

class FileSystem {
    private:
        int disks;
    public:
        FileSystem() : disks(4) {}
        int numDisks() const { return disks; }
};

//Problem: global object defined in another file (.cpp)
//The initialization order of globals across different files is NOT defined
extern FileSystem tfsGlobal;

//Solution: a function that returns a local static object,
//initialized the first time the function is called
FileSystem& tfs();
