/*
 * @Author: Radon
 * @Date: 2022-02-05 22:35:48
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-06 00:09:13
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
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
     * @param num
     * @return int
     */
    int minimumSum(int num) {
        vector<int> vec;
        int n = 0;
        while (num) {
            vec.emplace_back(num % 10);
            num /= 10;
            n++;
        }
        sort(vec.begin(), vec.end());
        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                n2 = n2 * 10 + vec[i];
            else
                n1 = n1 * 10 + vec[i];
        }
        return n1 + n2;
    }

    /**
     * @brief Ac
     *
     * @param nums
     * @param pivot
     * @return vector<int>
     */
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        int n = nums.size();
        vector<int> gNums, lNums, eNums;
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot)
                gNums.emplace_back(nums[i]);
            else if (nums[i] < pivot)
                lNums.emplace_back(nums[i]);
            else
                eNums.emplace_back(nums[i]);
        }
        nums.clear();
        nums.insert(nums.end(), lNums.begin(), lNums.end());
        nums.insert(nums.end(), eNums.begin(), eNums.end());
        nums.insert(nums.end(), gNums.begin(), gNums.end());
        return nums;
    }

    /**
     * @brief Ac
     *
     * @param startAt
     * @param moveCost
     * @param pushCost
     * @param targetSeconds
     * @return int
     */
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        vector<string> ways;
        string w;

        int m = targetSeconds / 60, s = targetSeconds % 60;
        if (m > 0)
            w = to_string(m);
        if (s < 10 && !w.empty())
            w += "0" + to_string(s);
        else
            w += to_string(s);
        ways.emplace_back(w);

        if (targetSeconds % 60 <= 39) { // 若<=39就证明有两种方式表示
            w.clear();
            m = targetSeconds / 60 - 1;
            if (m >= 0) {
                s = targetSeconds % 60 + 60;
            } else {
                s = targetSeconds % 60;
            }
            if (m > 0)
                w += to_string(m);
            w += to_string(s);
            ways.emplace_back(w);
        }

        int res = INT_MAX;
        for (auto way : ways) {
            if (way.length() > 4)
                continue;
            int nowRes = 0;
            int nowAt = startAt;
            for (auto c : way) {
                if (c - '0' != nowAt) {
                    nowRes += moveCost + pushCost;
                    nowAt = c - '0';
                } else {
                    nowRes += pushCost;
                }
            }
            res = min(res, nowRes);
        }
        return res;
    }

    long long minimumDifference(vector<int> &nums) {
        vector<int> numCopy = nums;
        int n = nums.size();
        sort(numCopy.begin(), numCopy.end());
    }
};

int main(int argc, char **argv) {
    Solution sol;
    cout << sol.minCostSetTime(1, 583, 18, 64) << endl;
    return 0;
}