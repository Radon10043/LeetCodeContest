/*
 * @Author: Radon
 * @Date: 2022-03-06 10:29:54
 * @LastEditors: Radon
 * @LastEditTime: 2022-03-07 12:10:54
 * @Description: Hi, say something
 */
#include "../../headers/BinaryTree.h"
#include "../../headers/List.h"

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
    vector<string> cellsInRange(string s) {
        char sc = s[0], ec = s[3];
        char sn = s[1], en = s[4];
        vector<string> res;

        for (char c = sc; c <= ec; c++) {
            for (char in = sn; in <= en; in++) {
                string node("");
                node += c;
                node += in;
                res.emplace_back(node);
            }
        }
        return res;
    }

    long long minimalKSum(vector<int> &nums, int k) {
        set<int> st(nums.begin(), nums.end());
        long long res = (long long)(1 + k) * k / 2;
        for (auto num : st) {
            if (num <= k) {
                res -= (long long)num;
                res += (long long)++k;
            }
        }
        return res;
    }

    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int, TreeNode *> ump;
        for (auto desc : descriptions) {
            ump[desc[1]] = new TreeNode(desc[1]);
        }
        TreeNode *root;
        for (auto desc : descriptions) {
            if (ump[desc[0]] == nullptr) {
                ump[desc[0]] = new TreeNode(desc[0]);
                root = ump[desc[0]];
            }
        }
        for (auto desc : descriptions) {
            if (desc[2] == 1) {
                ump[desc[0]]->left = ump[desc[1]];
            } else {
                ump[desc[0]]->right = ump[desc[1]];
            }
        }
        return root;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums = {53, 41, 90, 33, 84, 26, 50, 32, 63, 47, 66, 43, 29, 88, 71, 28, 83};
    sol.minimalKSum(nums, 76);
    return 0;
}