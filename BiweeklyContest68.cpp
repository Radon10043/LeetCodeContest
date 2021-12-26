/*
 * @Author: Radon
 * @Date: 2021-12-25 22:35:42
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-25 22:48:56
 * @Description: Hi, say something
 */
#include "headers/BinaryTree.h"
#include "headers/List.h"
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
    int mostWordsFound(vector<string> &sentences) {
        int result = 1;
        for (string s : sentences) {
            int wordNum = 1;
            for (char c : s) {
                if (c == ' ')
                    wordNum++;
            }
            result = max(result, wordNum);
        }
        return result;
    }

    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
        int n = recipes.size();
        vector<string> result;
        for (int i = 0; i < n; i++) {
            bool cooking = true;
            for (string data : ingredients[i]) {
                if (find(supplies.begin(), supplies.end(), data) == supplies.end() && find(result.begin(), result.end(), data) == result.end()) {
                    cooking = false;
                    break;
                }
            }
            if (cooking)
                result.emplace_back(recipes[i]);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    s.findAllRecipes({"abc"}, {{"abc"}}, {"abc"});
    return 0;
}