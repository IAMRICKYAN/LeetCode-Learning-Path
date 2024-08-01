#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();   // 取原始数组长度
        int n = nums2.size();
        nums1.emplace_back(INT_MAX);    // 追加哨兵位
        nums2.emplace_back(INT_MAX);
        int k = (m + n + 1) / 2;    // 获取中间数是第几个数（偶数取前一个数）
        int idx1 = 0;     // 遍历指针，指向当前取得数组的元素
        int idx2 = 0;
        bool flag = false;  // 标记中间数取的是否为nums1的元素
        while (true) {
            // 数组1元素全部取完，剩下的元 素由数组2提供
            if (idx1 == m) {
                // [idx2, ?]提供k个元素，即?-idx2+1=k => ? = idx2+k-1
                idx2 += k - 1;
                break;
            }
            // 数组2元素全部取完，剩下的元素由数组1提供
            if (idx2 == n) {
                idx1 += k - 1;
                flag = true;
                break;
            }
            // 为了使指针停在中间数的位置，最后一个数单独处理
            if (k == 1) {
                flag = nums1[idx1] < nums2[idx2];   // 指针无需移动，只需要判断取哪个数组的元素
                break;
            }
            // 每次两个数组各出k/2的元素，然后取数字更小的那一组
            int half = k / 2;
            int mid1 = min(idx1 + half, m) - 1;     // [idx1, mid1] 范围元素，确保mid1不越界
            int mid2 = min(idx2 + half, n) - 1;
            // mid1更小，那么mid1一定不会是第k个数，因此淘汰[idx1, mid1]往后找；否则淘汰[idx2, mid2]往后找
            // k减少对应区间的元素个数 idx-mid + 1
            if (nums1[mid1] < nums2[mid2]) {
                k -= mid1 - idx1 + 1;
                idx1 = mid1 + 1;
            }
            else {
                k -= mid2 - idx2 + 1;
                idx2 = mid2 + 1;
            }
        }
        // 总元素个数为奇数，直接返回中间数，根据flag判断中间数是在nums1还是在nums2
        if ((m + n) & 1)return (flag ? nums1[idx1] : nums2[idx2]) / 1.0;
        // 总元素个数为偶数，不仅要取中间数，还要取中间数的后一位取平均
        // 根据flag判断中间数是在nums1还是在nums2，中间数的下一个数要么是中间数同数组的后一位，要么是另一个数组的当前指向元素
        if (flag)return (nums1[idx1] + min(nums1[idx1 + 1], nums2[idx2])) / 2.0;
        return (nums2[idx2] + min(nums2[idx2 + 1], nums1[idx1])) / 2.0;
    }
};