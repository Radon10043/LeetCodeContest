/*
 * @Author: Radon
 * @Date: 2022-03-05 22:34:47
 * @LastEditors: Radon
 * @LastEditTime: 2022-03-06 00:04:58
 * @Description: Hi, say something
 */
#include <algorithm>
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
    /**
     * @brief Ac
     *
     * @param nums
     * @param key
     * @return int
     */
    int mostFrequent(vector<int> &nums, int key) {
        int n = nums.size(), res = 0, times = 0;
        map<int, int> mp;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == key)
                mp[nums[i + 1]]++;
        }
        for (auto pii : mp) {
            if (pii.second > times) {
                times = pii.second;
                res = pii.first;
            }
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param mapping
     * @param nums
     * @return vector<int>
     */
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        int nm = mapping.size(), nn = nums.size();

        function<bool(const int, const int)> myCmp = [&](const int &a, const int &b) {
            int ma = 0, mb = 0;
            int temp = a, cnt = 1;
            if (a == 0)
                ma = mapping[0];
            while (temp) {
                int digit = temp % 10;
                if (digit < mapping.size())
                    ma += mapping[digit] * cnt;
                else
                    ma += digit * cnt;
                cnt *= 10;
                temp /= 10;
            }
            temp = b, cnt = 1;
            if (b == 0)
                mb = mapping[0];
            while (temp) {
                int digit = temp % 10;
                if (digit < mapping.size())
                    mb += mapping[digit] * cnt;
                else
                    mb += digit * cnt;
                cnt *= 10;
                temp /= 10;
            }
            return ma < mb;
        };

        sort(nums.begin(), nums.end(), myCmp);
        return nums;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}