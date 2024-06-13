//不推荐这个方法，但是可以熟悉static和构造函数
class Temp {
public:
    // 构造函数
    Temp() {
        N++;
        sum += N;
    }
    // 返回值（静态函数）
    static unsigned int getSum() {
        return sum;
    }
    // 重置静态变量
    static void reset() {
        N = 0;
        sum = 0;
    }
private:
    // 静态变量的声明式
    static unsigned int N;
    static unsigned int sum;
};
// 定义式
unsigned int Temp::N = 0;
unsigned int Temp::sum = 0;

class Solution {
public:
    int sumNums(int n) {
        Temp::reset();
        Temp* p = new Temp[n];
        delete[] p;
        p = nullptr;
        return Temp::getSum();
    }
};