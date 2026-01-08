#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <vector>
#include <sstream>
#include "../inc/listnode.h"
#include "../inc/treenode.h"
using namespace std;

template<typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

inline ostream& operator<<(ostream& os, ListNode* head) {
    os << "[" << head->list2Str() << "]";
    return os;
}

inline ostream& operator<<(ostream& os, TreeNode* root) {
    os << "[" << TreeNode::tree2Str(root) << "]";
    return os;
}

/* Using to print info of solution */
inline void printInfo(const string &file, const int APR, const string &apr_idea, const string &time_cmplx, const string &space_cmplx) {
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "FILE: " << file << endl;
    cout << "APPROACH " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
}

#endif // CONVERT_H