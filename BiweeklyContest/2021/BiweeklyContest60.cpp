/*
 * @Author: Radon
 * @Date: 2021-11-26 16:43:25
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-26 17:34:41
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int> &nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < n; i++) {
            int right = sum - nums[i] - left;
            if (right == left)
                return i;
            left += nums[i];
        }
        return -1;
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        int rows = land.size(), cols = land[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (land[i][j] && (i - 1 < 0 || !land[i - 1][j]) && (j - 1 < 0 || !land[i][j - 1])) {
                    int x = i + 1, y = j + 1;
                    while (x < rows && land[x][j])
                        x++;
                    while (y < cols && land[i][y])
                        y++;
                    result.push_back({i, j, x - 1, y - 1});
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {2, 3, -1, 8, 4};
    s.findMiddleIndex(nums);
    return 0;
}