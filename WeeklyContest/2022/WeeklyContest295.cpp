/*
 * @Author: Radon
 * @Date: 2022-05-29 10:18:10
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-29 11:29:19
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
#include "../../headers/List.h"

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> ump;
        for (auto &&c : s)
            ump[c]++;

        int res = 0;
        while (true) {
            for (auto &&c : target) {
                if (!ump[c])
                    return res;
                ump[c]--;
            }
            res++;
        }

        return 0;
    }

    string discountPrices(string sentence, int discount) {
        vector<string> words;
        string word;

        for (auto &&c : sentence) {
            if (c == ' ') {
                words.emplace_back(word);
                word.clear();
                continue;
            }
            word += c;
        }
        words.emplace_back(word);

        for (auto &&w : words) {
            if (w.length() < 2 || w[0] != '$')
                continue;

            bool isMoney = true;
            for (int i = 1; i < w.length(); i++) {
                if (w[i] < '0' || w[i] > '9') {
                    isMoney = false;
                    break;
                }
            }

            if (isMoney) {
                w.erase(w.begin());
                double money = atof(w.c_str());
                money -= money * discount / 100.0;
                money = money * 100 + 0.5;
                money /= 100;
                string after = to_string(money);
                size_t found = after.find('.');
                after = after.substr(0, found + 3);
                w = "$" + after;
            }
        }

        string res;
        for (auto &&w : words) {
            res += w + " ";
        }
        res.erase(res.end() - 1);
        return res;
    }

    int totalSteps(vector<int> &nums) {
        int n = nums.size(), res = 0;

        int loc = 0, l = 1, r = 1;
        while (r < n) {
            if (nums[r] >= nums[loc]) {
                loc = r;
                r++;
                l = r;
                continue;
            } else {
                if (nums[r] >= nums[r - 1])
                    res = max(res, r - l + 1);
                else {
                    l = r;
                    res = max(res, 1);
                }
                r++;
            }
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;

    vector<int> nums = {10, 6, 5, 10, 15};

    sol.totalSteps(nums);

    return 0;
}