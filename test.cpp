#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {1,2,3,4};

    cout << (nums1 == nums2) << endl;
    return 0;
}