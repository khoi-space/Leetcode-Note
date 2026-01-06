#include "../inc/global.h"
using namespace std;

// Turn off debug mode (uncomment to turn on)
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Merge Sort";
string time_cmplx = "m+n";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Binary Search + Recursive";
string time_cmplx = "log(m.n)";
string space_cmplx = "logm + logn";
#elif APR == 3
string apr_idea = "Optimal Binary Search";
string time_cmplx = "log(min(m,n))";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 4: Median of Two Sorted Arrays
 * LeetCode: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * @input: two sorted arrays nums1 (size m), nums2 (size n)
 * @output: the mediam of the two sorted arrays
*/
class Solution {
public:
    #if APR == 1
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int m = nums1.size(), n = nums2.size();

        auto getMin = [&](vector<int>& nums1, vector<int>& nums2) -> int {
            // Get the min(nums1[p1], nums2[p2]) and increment its pointer
            if (p1 < m && p2 < n) {
                return (nums1[p1] < nums2[p2]) ? nums1[p1++] : nums2[p2++];
            } else if (p1 < m) {
                return nums1[p1++];
            } else if (p2 < n) {
                return nums2[p2++];
            }
            return -1;
        };

        int total_size = m + n;
        if (total_size % 2 == 0) {
            for (int i = 0; i < total_size / 2 - 1; ++i) {
                getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < total_size / 2; ++i) {
                getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }
    }
    #elif APR == 2
private:
    int solve(
        vector<int>& A, vector<int>& B, int k,
        int a_start, int a_end,
        int b_start, int b_end
    ) {
        // If the segment of array is empty, it means we have passed all its elem
        if (a_end < a_start) {
            return B[k - a_start];
        }
        if (b_end < b_start) {
            return A[k - b_start];
        }

        // Get the mid elem of A and B
        int a_idx = (a_start + a_end) / 2, b_idx = (b_start + b_end) / 2;
        int a_val = A[a_idx], b_val = B[b_idx];

        if (a_idx + b_idx < k) { // If k is in the right half of A+B, rm the smaller left half
            if (a_val > b_val) {
                return solve(A, B, k, a_start, a_end, b_idx + 1, b_end);
            } else {
                return solve(A, B, k, a_idx + 1, a_end, b_start, b_end);
            }
        }
        else { // Otherise, rm the larger right half
            if (a_val > b_val) {
                return solve(A, B, k, a_start, a_idx - 1, b_start, b_end);
            } else {
                return solve(A, B, k, a_start, a_end, b_start, b_idx - 1);
            }
        }
        return -1;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total_size = n + m;
        if (total_size % 2) {
            return (double)(solve(nums1, nums2, total_size / 2, 0, m - 1, 0, n - 1));
        } else {
            return (double)(solve(nums1, nums2, total_size / 2 - 1, 0, m - 1, 0, n - 1)
                            + solve(nums1, nums2, total_size / 2, 0, m - 1, 0, n - 1))
                            / 2;
        }
        return -1;
    }
    #elif APR == 3
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }

        return 0.0;
    }
    #endif
};


void test4() {
    #ifdef INFO
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "FILE: " << __FILE__ << endl;
    cout << "APPROACH " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> nums1;
        vector<int> nums2;
        // Expect
        double exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,3}, {2}, 2.0},
        {{1,2}, {3,4}, 2.5},
        {{0,0}, {0,0}, 0.0},
        {{}, {1}, 1.0},
        {{2}, {}, 2.0},
        {{1,3,5}, {2,4,6}, 3.5},
        {{1}, {2,3,4,5,6}, 3.5},
        {{}, {2,3}, 2.5},
        {{1000000}, {1000001}, 1000000.5},
        {{1,2,3,4,5}, {6,7,8,9,10}, 5.5}
    };

    Solution sol = Solution();

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        // Inputs
        auto in1 = c.nums1;
        auto in2 = c.nums2;

        // Result
        auto res = sol.findMedianSortedArrays(c.nums1, c.nums2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
