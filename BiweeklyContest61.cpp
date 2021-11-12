/*
 * @Author: Radon
 * @Date: 2021-11-04 16:09:51
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-04 17:16:09
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int> &nums, int k) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[j] - nums[i]) == k)
                    result++;
            }
        }
        return result;
    }

    /**
     * @description: 排序+队列
     * @param {vector<int>} &changed
     * @return {*}
     */
    vector<int> findOriginalArray(vector<int> &changed) {
        int n = changed.size();
        if (n % 2)
            return {};

        queue<int> q;
        vector<int> original;
        sort(changed.begin(), changed.end());
        for (int num : changed) {
            if (!q.empty() && q.front() * 2 == num) {
                original.emplace_back(q.front());
                q.pop();
            } else
                q.push(num);
        }

        if (original.size() != n / 2)
            return {};
        return original;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> changed = {4, 4, 16, 20, 8, 8, 2, 10};
    //[4,4,16,20,8,8,2,10]
    //[4,4,8,8,2,10]
    // 6,9,5,3,5,6
    s.findOriginalArray(changed);
    return 0;
}