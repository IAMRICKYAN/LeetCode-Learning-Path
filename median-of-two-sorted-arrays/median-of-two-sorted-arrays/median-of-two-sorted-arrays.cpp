#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();   // ȡԭʼ���鳤��
        int n = nums2.size();
        nums1.emplace_back(INT_MAX);    // ׷���ڱ�λ
        nums2.emplace_back(INT_MAX);
        int k = (m + n + 1) / 2;    // ��ȡ�м����ǵڼ�������ż��ȡǰһ������
        int idx1 = 0;     // ����ָ�룬ָ��ǰȡ�������Ԫ��
        int idx2 = 0;
        bool flag = false;  // ����м���ȡ���Ƿ�Ϊnums1��Ԫ��
        while (true) {
            // ����1Ԫ��ȫ��ȡ�꣬ʣ�µ�Ԫ ��������2�ṩ
            if (idx1 == m) {
                // [idx2, ?]�ṩk��Ԫ�أ���?-idx2+1=k => ? = idx2+k-1
                idx2 += k - 1;
                break;
            }
            // ����2Ԫ��ȫ��ȡ�꣬ʣ�µ�Ԫ��������1�ṩ
            if (idx2 == n) {
                idx1 += k - 1;
                flag = true;
                break;
            }
            // Ϊ��ʹָ��ͣ���м�����λ�ã����һ������������
            if (k == 1) {
                flag = nums1[idx1] < nums2[idx2];   // ָ�������ƶ���ֻ��Ҫ�ж�ȡ�ĸ������Ԫ��
                break;
            }
            // ÿ�������������k/2��Ԫ�أ�Ȼ��ȡ���ָ�С����һ��
            int half = k / 2;
            int mid1 = min(idx1 + half, m) - 1;     // [idx1, mid1] ��ΧԪ�أ�ȷ��mid1��Խ��
            int mid2 = min(idx2 + half, n) - 1;
            // mid1��С����ômid1һ�������ǵ�k�����������̭[idx1, mid1]�����ң�������̭[idx2, mid2]������
            // k���ٶ�Ӧ�����Ԫ�ظ��� idx-mid + 1
            if (nums1[mid1] < nums2[mid2]) {
                k -= mid1 - idx1 + 1;
                idx1 = mid1 + 1;
            }
            else {
                k -= mid2 - idx2 + 1;
                idx2 = mid2 + 1;
            }
        }
        // ��Ԫ�ظ���Ϊ������ֱ�ӷ����м���������flag�ж��м�������nums1������nums2
        if ((m + n) & 1)return (flag ? nums1[idx1] : nums2[idx2]) / 1.0;
        // ��Ԫ�ظ���Ϊż��������Ҫȡ�м�������Ҫȡ�м����ĺ�һλȡƽ��
        // ����flag�ж��м�������nums1������nums2���м�������һ����Ҫô���м���ͬ����ĺ�һλ��Ҫô����һ������ĵ�ǰָ��Ԫ��
        if (flag)return (nums1[idx1] + min(nums1[idx1 + 1], nums2[idx2])) / 2.0;
        return (nums2[idx2] + min(nums2[idx2 + 1], nums1[idx1])) / 2.0;
    }
};