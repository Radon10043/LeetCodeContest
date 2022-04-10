/*
 * @Author: Radon
 * @Date: 2022-04-10 10:32:11
 * @LastEditors: Radon
 * @LastEditTime: 2022-04-10 11:41:49
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        vector<int> num_o, num_j;
        int copy = num;
        while (copy) {
            if (copy % 10 % 2) {
                num_j.emplace_back(copy % 10);
            } else {
                num_o.emplace_back(copy % 10);
            }
            copy /= 10;
        }

        string temp = to_string(num), resStr;
        sort(num_o.begin(), num_o.end(), greater<int>());
        sort(num_j.begin(), num_j.end(), greater<int>());

        int idx_o = 0, idx_j = 0;
        for (auto c : temp) {
            if ((c - '0') % 2) {
                char now = '0' + num_j[idx_j++];
                resStr += now;
            } else {
                char now = '0' + num_o[idx_o++];
                resStr += now;
            }
        }

        return atoi(resStr.c_str());
    }

    string minimizeResult(string expression) {
        int n = expression.size();
        int minNum = INT_MAX;
        string res;

        int plus = expression.find('+');
        for (int i = 0; i < plus; i++) {
            for (int j = plus + 1; j < n; j++) {
                string num1_s = expression.substr(0, i);
                string num2_s = expression.substr(i, plus - i);
                string num3_s = expression.substr(plus + 1, j - plus);
                string num4_s = expression.substr(j + 1, n - j - 1);

                int num1 = num1_s == "" ? 1 : stoi(num1_s);
                int num2 = stoi(num2_s);
                int num3 = stoi(num3_s);
                int num4 = num4_s == "" ? 1 : stoi(num4_s);

                int nowNum = num1 * (num2 + num3) * num4;
                if (nowNum < minNum) {
                    res = num1_s + "(" + num2_s + "+" + num3_s + ")" + num4_s;
                    minNum = nowNum;
                }
            }
        }
        return res;
    }

    int maximumProduct(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
        }

        while (k--) {
            int num = pq.top();
            pq.pop();
            pq.push(++num);
        }

        const int mod = 1000000007;
        long long res = 1;

        while (!pq.empty()) {
            res *= pq.top();
            res %= mod;
            pq.pop();
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums = {92, 36, 15, 84, 57, 60, 72, 86, 70, 43, 16};
    sol.maximumProduct(nums, 62);
    return 0;
}