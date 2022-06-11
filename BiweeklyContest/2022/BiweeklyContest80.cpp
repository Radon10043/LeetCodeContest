/*
 * @Author: Radon
 * @Date: 2022-06-11 22:27:26
 * @LastEditors: Radon
 * @LastEditTime: 2022-06-12 01:13:22
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
    bool strongPasswordCheckerII(string password) {
        string special = "!@#$%^&*()-+";
        bool haveSmall = false, haveBig = false, haveNum = false, haveSpecial = false;

        int n = password.length();

        if (n < 8)
            return false;

        for (int i = 0; i < n; i++) {
            if (password[i] >= 'a' && password[i] <= 'z')
                haveSmall = true;
            else if (password[i] >= 'A' && password[i] <= 'Z')
                haveBig = true;
            else if (password[i] >= '0' && password[i] <= '9')
                haveNum = true;
            else if (special.find(password[i]) != string::npos)
                haveSpecial = true;
            if (i && password[i] == password[i - 1])
                return false;
        }

        if (haveSmall && haveBig && haveNum && haveSpecial)
            return true;
        return false;
    }

    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> res;
        sort(potions.begin(), potions.end());

        for (auto &&spell : spells) {
            long long tmp = ceil((double)success / (double)spell);
            if (tmp > potions[m - 1])
                res.emplace_back(0);
            else if (tmp < potions[0])
                res.emplace_back(m);
            else {
                int idx = lower_bound(potions.begin(), potions.end(), tmp) - potions.begin();
                res.emplace_back(m - idx);
            }
        }

        return res;
    }

    long long countSubarrays(vector<int> &nums, long long k) {
        int n = nums.size();
        long long subTotal = nums[0], res = 0;

        int i = 0, j = 0;
        while (i < n) {
            long long multi = subTotal * (j - i + 1);
            if (multi < k && j <= n - 1) {
                if (j == i)
                    res++;
                else
                    res += (j + i) * (j - i + 1) / 2;
                j++;
                subTotal += nums[j];
            } else {
                subTotal -= nums[i];
                i++;
            }
        }

        return res;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> res;
        for (auto &&word : words) {
            unordered_map<char, char> ump1, ump2;
            int n1 = word.size(), n2 = pattern.size();

            if (n1 != n2)
                continue;

            bool isPattern = true;
            for (int i = 0; i < n1; i++) {
                if (ump1.find(pattern[i]) != ump1.end() && ump1[pattern[i]] != word[i]) {
                    isPattern = false;
                    break;
                }

                if (ump2.find(word[i]) != ump2.end() && ump2[word[i]] != pattern[i]) {
                    isPattern = false;
                    break;
                }

                ump1[pattern[i]] = word[i];
                ump2[word[i]] = pattern[i];
            }

            if (isPattern)
                res.emplace_back(word);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums = {2, 1, 4, 3, 5};
    int k = 10;
    sol.countSubarrays(nums, k);
    return 0;
}