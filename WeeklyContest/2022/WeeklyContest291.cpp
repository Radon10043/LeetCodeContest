/*
 * @Author: Radon
 * @Date: 2022-05-01 10:29:48
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-01 11:58:51
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
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> nums;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                string copy = number;
                copy.erase(copy.begin() + i);
                nums.emplace_back(copy);
            }
        }
        sort(nums.begin(), nums.end());
        return *(nums.end() - 1);
    }

    int minimumCardPickup(vector<int> &cards) {
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < cards.size(); i++) {
            ump[cards[i]].emplace_back(i);
        }

        int res = INT_MAX;
        for (auto piv : ump) {
            if (piv.second.size() < 2)
                continue;
            for (int i = 1; i < piv.second.size(); i++) {
                res = min(res, piv.second[i] - piv.second[i - 1] + 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }

    int countDistinct(vector<int> &nums, int k, int p) {
        set<vector<int>> st;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int cnt = nums[i] % p == 0 ? 1 : 0;
            for (int j = i; j < nums.size(); j++) {
                if (j > i && nums[j] % p == 0)
                    if (++cnt > k)
                        break;
                vector<int> tmp(nums.begin() + i, nums.begin() + j + 1);
                if (st.insert(tmp).second)
                    res++;
            }
        }

        return res;
    }

    long long appealSum(string s) {
        long long res = 0;
        vector<long long> nums = {1};
        unordered_set<char> ust;
        ust.insert(s[0]);
        for (int i = 0; i < s.size(); i++) {
            if (ust.insert(s[i]).second) {
            } else {
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums = {14, 19, 9};
    sol.countDistinct(nums, 1, 11);
    return 0;
}