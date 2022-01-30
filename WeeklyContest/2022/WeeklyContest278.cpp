/*
 * @Author: Radon
 * @Date: 2022-01-30 10:44:23
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-30 11:59:16
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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
     * @param nums
     * @param original
     * @return int
     */
    int findFinalValue(vector<int> &nums, int original) {
        set<int> numSet;
        for (auto num : nums) {
            numSet.insert(num);
        }

        bool found = numSet.count(original);
        while (found) {
            original *= 2;
            found = numSet.count(original);
        }

        return original;
    }

    /**
     * @brief Ac
     *
     * @param nums
     * @return vector<int>
     */
    vector<int> maxScoreIndices(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = count(nums.begin(), nums.end(), 1), maxScore = left + right;
        unordered_map<int, vector<int>> umap; // <分数, 下标数组>

        umap[left + right].push_back(0);
        for (int i = 0; i < n; i++) {
            if (!nums[i])
                left++;
            else
                right--;
            umap[left + right].push_back(i + 1);
            maxScore = max(maxScore, left + right);
        }

        return umap[maxScore];
    }

    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.length();
        if (n == k)
            return s;

        vector<long long> pValue(k, 1);
        long long val = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < i; j++)
                pValue[i] = pValue[i] * power % modulo;
            val += (s[i] - 'a' + 1) * pValue[i];
        }
        if (val % modulo == hashValue)
            return s.substr(0, k);

        for (int i = 1; i < n - k; i++) {
            val -= s[i - 1] - 'a' + 1;
            val /= power;
            val += (s[i + k - 1] - 'a' + 1) * pValue[k - 1];
            if (val % modulo == hashValue)
                return s.substr(i, k);
        }

        return s;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    sol.subStrHash("abxzaad", 31, 100, 3, 32);
    return 0;
}