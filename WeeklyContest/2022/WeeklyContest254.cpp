/*
 * @Author: Radon
 * @Date: 2022-02-01 18:06:58
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-01 18:33:29
 * @Description: Hi, say something
 */
#include "..\..\headers\BinaryTree.h"
#include "..\..\headers\List.h"
#include <algorithm>
#include <iostream>
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
     * @param patterns
     * @param word
     * @return int
     */
    int numOfStrings(vector<string> &patterns, string word) {
        int res = 0;
        for (string pattern : patterns) {
            if (word.find(pattern) != string::npos)
                res++;
        }
        return res;
    }

    /**
     * @brief 看了答案
     *
     * @param nums
     * @return vector<int>
     */
    vector<int> rearrangeArray(vector<int> &nums) {
        int n = nums.size(), ptr = 0;
        vector<int> res(n);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2)
            res[i] = nums[ptr++];
        for (int i = 1; i < n; i += 2)
            res[i] = nums[ptr++];
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<string> patterns = {"cj"};
    string word = "j";
    sol.numOfStrings(patterns, word);
    return 0;
}