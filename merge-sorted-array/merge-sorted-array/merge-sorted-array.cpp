#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//正向双链表
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            }
            else if (p2 == n) {
                cur = nums1[p1++];
            }
            else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            }
            else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};

//逆向双链表
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            }
            else if (p2 == -1) {
                cur = nums1[p1--];
            }
            else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            }
            else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

