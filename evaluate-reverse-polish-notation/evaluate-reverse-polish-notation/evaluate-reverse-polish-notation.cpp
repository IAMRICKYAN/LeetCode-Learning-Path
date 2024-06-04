#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> num;

        for (auto& ch : tokens)
        {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
            {
                int a = num.top(); num.pop();
                int b = num.top(); num.pop();
                if (ch == "+") num.push(b + a);
                if (ch == "-")  num.push(b - a);
                if (ch == "*") num.push(b * a);
                if (ch == "/") num.push(b / a);
            }
            else
            {
                num.push(stoi(ch));
            }
        }

        return num.top();
    }
};