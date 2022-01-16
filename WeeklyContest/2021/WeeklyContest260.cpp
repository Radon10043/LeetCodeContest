/*
 * @Author: Radon
 * @Date: 2021-11-09 16:54:59
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-09 17:29:58
 * @Description: Hi, say something
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
     * @param {vector<int>} &nums
     * @return {*}
     */
    int maximumDifference(vector<int> &nums) {
        int n = nums.size(), maxDiff = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i])
                    maxDiff = max(maxDiff, nums[j] - nums[i]);
            }
        }
        return maxDiff;
    }

    long long gridGame(vector<vector<int>> &grid) {
        int n = grid[0].size();
        long long leftDown = 0;
        long long rightUp = 0;
        for (int i = 1; i < n; i++)
            rightUp += grid[0][i];
        long long result = rightUp;
        for (int i = 1; i < n; i++) {
            leftDown += grid[1][i - 1];
            rightUp -= grid[0][i];
            long long temp = leftDown > rightUp ? leftDown : rightUp;
            result = result < temp ? result : temp;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};
    s.gridGame(grid);
    return 0;
}