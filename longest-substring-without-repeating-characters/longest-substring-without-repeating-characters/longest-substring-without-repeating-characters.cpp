#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int left = 0;
        int right = 0;
        int minstr = 1;
        
        if (s == "")
        {
            return 0;
        }

        unordered_map<int, char> sign;

        while (right < n)
        {
           
            if (++sign[s[right]] > 1)
            {
                left++;
                sign.clear();
                ++sign[s[left]];
                right = left;
            }
            minstr = max(minstr, (right - left + 1));
            right++;

            if (minstr > n - left)
                return minstr;
        }

        return minstr;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
        unordered_set<char> occ;
        int n = s.size();
        // ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
        int rk = -1, ans = 0;
        // ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // ��ָ�������ƶ�һ���Ƴ�һ���ַ�
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // ���ϵ��ƶ���ָ��
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

