#include <vector>
#include <queue>

using namespace std;


class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> A; // С���ѣ�����ϴ��һ��
    priority_queue<int, vector<int>, less<int>> B; // �󶥶ѣ������С��һ��
    MedianFinder() { }
    void addNum(int num) {
        if (A.size() != B.size()) {
            A.push(num);
            B.push(A.top());
            A.pop();
        }
        else {
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }
    double findMedian() {
        return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */