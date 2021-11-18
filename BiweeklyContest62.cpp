/*
 * @Author: Radon
 * @Date: 2021-11-13 16:32:48
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-14 12:58:51
 * @Description: 虚拟竞赛 - 双周赛62
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: Accept
     * @param {vector<int>} &original
     * @param {int} m
     * @param {int} n
     * @return {*}
     */
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        if (m * n != original.size())
            return {};

        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[i * n + j];
            }
        }
        return result;
    }

    /**
     * @description: Accept
     * @param {vector<string>} &nums
     * @param {string} target
     * @return {*}
     */
    int numOfPairs(vector<string> &nums, string target) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (nums[i] + nums[j] == target)
                    result++;
            }
        }
        return result;
    }

    /**
     * @description: 滑动窗口, Accept
     * @param {string} answerKey
     * @param {int} k
     * @return {*}
     */
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j = 0, numT = 0, numF = 0, result = 0;
        int n = answerKey.length();
        while (i <= j) {
            while (numT <= k || numF <= k) {
                result = max(result, j - i);
                if (j == n)
                    break;
                if (answerKey[j] == 'T')
                    numT++;
                else
                    numF++;
                j++;
            }
            if (answerKey[i] == 'T')
                numT--;
            else
                numF--;
            i++;
        }
        return result;
    }
};

class MapSum {
public:
    unordered_map<string, int> umap;
    MapSum() {}

    void insert(string key, int val) { umap[key] = val; }

    int sum(string prefix) {
        int result = 0;
        for (unordered_map<string, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            int n = prefix.length();
            if (n > it->first.length())
                continue;

            bool isPrefix = true;
            for (int i = 0; i < prefix.length(); i++) {
                if (prefix[i] != it->first[i]) {
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix) {
                result += it->second;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    string answerKey = "TTFF";
    s.maxConsecutiveAnswers(answerKey, 2);
    return 0;
}