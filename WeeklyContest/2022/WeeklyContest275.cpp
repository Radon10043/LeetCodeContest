/*
 * @Author: Radon
 * @Date: 2022-01-09 10:44:43
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-16 10:37:22
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
    /**
     * @brief Ac
     *
     * @param matrix
     * @return true
     * @return false
     */
    bool checkValid(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> uset;
            for (int j = 0; j < n; j++) {
                uset.insert(matrix[i][j]);
            }
            if (uset.size() != n)
                return false;
        }
        for (int i = 0; i < n; i++) {
            unordered_set<int> uset;
            for (int j = 0; j < n; j++) {
                uset.insert(matrix[j][i]);
            }
            if (uset.size() != n)
                return false;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<string> startWords = {"ant", "act", "tack"}, targetWords = {"tack", "act", "acti"};
    return 0;
}