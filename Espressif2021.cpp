/*
 * @Author: Radon
 * @Date: 2021-12-30 16:27:42
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-05 13:07:10
 * @Description: Hi, say something
 */
#include "headers/BinaryTree.h"
#include "headers/List.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// TODO: 格式化代码
class Solution {
public:
    double getAdmissionLine(int k, vector<double> &scores) {
        sort(scores.begin(), scores.end(), greater<double>());
        return scores[k - 1];
    }

    int adjustLevel(int cnt) {
        if (cnt <= 1)
            return cnt;
        double result = ceil(log(cnt) / log(2));
        return result - 1;
    }

    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0)
                sum += i;
        }
        if (sum == num)
            return true;
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.adjustLevel(4) << endl;
    return 0;
}