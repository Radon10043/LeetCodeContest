/*
 * @Author: Radon
 * @Date: 2022-02-01 18:35:03
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-01 19:30:17
 * @Description: Hi, say something
 */
#include "..\..\headers\BinaryTree.h"
#include "..\..\headers\List.h"
#include <algorithm>
#include <cmath>
#include <iostream>
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
    /**
     * @brief Ac
     *
     * @param s
     * @param words
     * @return true
     * @return false
     */
    bool isPrefixString(string s, vector<string> &words) {
        int n = s.length(), np = 0;
        string prefix;
        for (string word : words) {
            prefix += word;
            np += word.length();
            if (np > n)
                return false;
            if (np == n && !s.compare(prefix))
                return true;
        }
        return false;
    }

    /**
     * @brief Ac
     *
     * @param piles
     * @param k
     * @return int
     */
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        for (auto pile : piles)
            pq.push(pile);
        for (int i = 0; i < k; i++) {
            int num = pq.top();
            pq.pop();
            if (num % 2)
                num = (num + 1) / 2;
            else
                num /= 2;
            pq.push(num);
        }

        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }

    /**
     * @brief 看了答案
     *
     * @param s
     * @return int
     */
    int minSwaps(string s) {
        int n = s.length();
        int deep = 0, right = n - 1, step = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[')
                deep++;
            else {
                if (deep)
                    deep--;
                else {
                    step++;
                    while (s[right] != '[')
                        right--;
                    s[right] = ']';
                    deep++;
                }
            }
        }
        return step;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> piles = {5, 4, 9};
    sol.minStoneSum(piles, 2);
    return 0;
}