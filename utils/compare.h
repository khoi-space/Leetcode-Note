#include <vector>
#include "listnode.h"

// Compare basic types
template<typename T>
inline bool isEqual(const T& lhs, const T& rhs) {
    return lhs == rhs;
}

// Compare vectors
template<typename T>
inline bool isEqual(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (!isEqual(lhs[i], rhs[i])) return false;
    }
    return true;
}

// Compare linked lists
inline bool isEqual(ListNode *lhs, ListNode* rhs) {
    while (lhs && rhs) {
        if (lhs->val != rhs->val) return false;
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return !lhs && !rhs;
}

// // Compare vectors unordered
// template<typename T>
// inline bool isEqualUnordered(const std::vector<T> lhs, const std::vector<T> rhs) {
//     if (lhs.size() != rhs.size()) return false;

//     sort(lhs.begin(), lhs.end());
//     sort(rhs.begin(), lhs.end());
// }