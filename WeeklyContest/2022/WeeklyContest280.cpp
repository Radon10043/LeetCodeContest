/*
 * @Author: Radon
 * @Date: 2022-02-13 10:32:21
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-20 12:21:52
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
     * @param num1
     * @param num2
     * @return int
     */
    int countOperations(int num1, int num2) {
        int res = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 > num2)
                num1 -= num2;
            else
                num2 -= num1;
            res++;
        }
        return res;
    }

    static bool myCmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }

    /**
     * @brief TODO: WA
     *
     * @param nums
     * @return int
     */
    int minimumOperations(vector<int> &nums) {
        int n = nums.size(), res = 0;
        map<int, int> mp1, mp2;

        if (n == 1)
            return 0;

        for (int i = 0; i < n; i++) {
            if (i % 2)
                mp1[nums[i]]++;
            else
                mp2[nums[i]]++;
        }

        vector<pair<int, int>> vec1(mp1.begin(), mp1.end()), vec2(mp2.begin(), mp2.end());
        sort(vec1.begin(), vec1.end(), myCmp);
        sort(vec2.begin(), vec2.end(), myCmp);

        if (vec1.size() == 1 && vec2.size() == 1) {
            if (vec1[0].first == vec2[0].first)
                return min(vec1[0].second, vec2[0].second);
            else
                return 0;
        }

        int i = 0, j = 0;
        if (vec1[i].first == vec2[j].first) {
            if (vec1[i].second > vec2[j].second) {
                if (j + 1 < vec2.size())
                    j++;
                else
                    i++;
            } else {
                if (i + 1 < vec1.size())
                    i++;
                else
                    j++;
            }
        }
        for (int a = 0; a < vec1.size(); a++) {
            if (a == i)
                continue;
            res += vec1[a].second;
        }
        for (int b = 0; b < vec2.size(); b++) {
            if (b == j)
                continue;
            res += vec2[b].second;
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param beans
     * @return long long
     */
    long long minimumRemoval(vector<int> &beans) {
        int n = beans.size();
        long long res = LLONG_MAX, outBeans = 0;
        long long sum = accumulate(beans.begin(), beans.end(), 0ll);
        sort(beans.begin(), beans.end());

        for (int i = 0; i < n; i++) {
            long long nSum = (long long)beans[i] * (long long)(n - i);
            res = min(res, sum - nSum + outBeans);
            sum -= beans[i];
            outBeans += beans[i];
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums = {2, 3, 4, 1, 4, 2, 2, 2};
    sol.minimumOperations(nums);
    return 0;
}