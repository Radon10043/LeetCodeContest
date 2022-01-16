/*
 * @Author: Radon
 * @Date: 2022-01-16 10:37:47
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-16 12:05:02
 * @Description: Hi, say something
 */
#include "headers\BinaryTree.h"
#include "headers\List.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /* Ac */
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> result;
        string temp;
        for (int i = 0; i < n; i += k) {
            temp.clear();
            for (int j = i; j < i + k && j < n; j++) {
                temp += s[j];
            }
            while (temp.length() < k)
                temp.push_back(fill);
            result.emplace_back(temp);
        }
        return result;
    }

    /**
     * @brief Ac
     *
     * @param target
     * @param maxDoubles
     * @return int
     */
    int minMoves(int target, int maxDoubles) {
        int result = 0;
        while (target != 1) {
            if (maxDoubles) {
                if (target % 2)
                    result += 2;
                else
                    result++;
                target /= 2;
                maxDoubles--;
            } else {
                result += target - 1;
                target = 1;
            }
        }
        return result;
    }

    long long mostPoints(vector<vector<int>> &questions) {
        return -1;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}