/*
 * @Author: Radon
 * @Date: 2022-02-19 22:29:50
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-20 00:20:29
 * @Description: Hi, say something
 */
#include <algorithm>
#include <functional>
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
     * @param nums
     * @param k
     * @return int
     */
    int countPairs(vector<int> &nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    res++;
            }
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param num
     * @return vector<long long>
     */
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        if (num % 3 == 0) {
            res.emplace_back(num / 3 - 1);
            res.emplace_back(num / 3);
            res.emplace_back(num / 3 + 1);
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param finalSum
     * @return vector<long long>
     */
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2)
            return {};

        vector<long long> res;
        long long i = 2;
        for (; finalSum >= i; i += 2) {
            res.emplace_back(i);
            finalSum -= i;
        }

        if (finalSum < i) {
            *(res.end() - 1) += finalSum;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    sol.maximumEvenSplit(28);
    return 0;
}