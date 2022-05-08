/*
 * @Author: Radon
 * @Date: 2022-05-08 10:20:48
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-08 12:12:14
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
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../../headers/BinaryTree.h"

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string res;
        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                string temp;
                temp.append(1, num[i]);
                temp.append(1, num[i + 1]);
                temp.append(1, num[i + 2]);
                res = max(res, temp);
            }
        }
        return res;
    }

    int sum = 0, num = 1, res = 0;

    void postTraverse(TreeNode *root) {
        int beforeNum = num;
        int beforeSum = sum;
        sum += root->val;
        num++;

        if (root->left)
            postTraverse(root->left);
        if (root->right)
            postTraverse(root->right);

        int afterNum = num;
        int afterSum = sum;

        if (root->val == (afterSum - beforeSum) / (afterNum - beforeNum))
            res++;
    }

    int averageOfSubtree(TreeNode *root) {
        postTraverse(root);
        return res;
    }

    int countTexts(string pressedKeys) {
        // 斐波那契数列?
    }
};

int main(int argc, char **argv) {
    Solution sol;
    string pressedKeys = "355577777788899";
    sol.countTexts(pressedKeys);
    return 0;
}