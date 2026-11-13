#include "FileSystem.hpp"

FileSystem tfsGlobal;

FileSystem& tfs() {
    static FileSystem fs;
    return fs;
}
