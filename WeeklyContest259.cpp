/*
 * @Author: Radon
 * @Date: 2021-11-12 15:48:37
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-12 17:13:57
 * @Description: 虚拟竞赛 - 周赛259
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
     * @param {vector<string>} &operations
     * @return {*}
     */
    int finalValueAfterOperations(vector<string> &operations) {
        int result = 0;
        for (string op : operations) {
            if (find(op.begin(), op.end(), '+') != op.end())
                result++;
            else
                result--;
        }
        return result;
    }

    /**
     * @description: 三次遍历
     * @param {vector<int>} &nums
     * @return {*}
     */
    int sumOfBeauties(vector<int> &nums) {
        int result = 0;
        int n = nums.size();
        vector<int> maxNum(n, nums[0]), minNum(n, nums[n - 1]);
        for (int i = 1; i < n - 1; i++)
            maxNum[i] = max(maxNum[i - 1], nums[i - 1]);
        for (int i = n - 2; i >= 1; i--)
            minNum[i] = min(minNum[i + 1], nums[i + 1]);
        for (int i = 1; i < n - 1; i++) {
            if (maxNum[i] < nums[i] && nums[i] < minNum[i])
                result += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                result++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {2, 4, 6, 4};
    s.sumOfBeauties(nums);
    return 0;
}