#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <vector>
#include <sstream>
#include "../inc/listnode.h"
using namespace std;

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

inline std::ostream& operator<<(ostream& os, ListNode* head) {
    os << "[" << head->list2Str() << "]";
    return os;
}

#endif // CONVERT_H