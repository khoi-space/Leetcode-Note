#ifndef CONVERT_H
#define CONVERT_H

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

#endif // CONVERT_H