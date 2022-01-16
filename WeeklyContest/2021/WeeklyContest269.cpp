/*
 * @Author: Radon
 * @Date: 2021-11-28 10:37:14
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-28 12:03:42
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
     * @param {int} target
     * @return {*}
     */
    vector<int> targetIndices(vector<int> &nums, int target) {
        vector<int> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                result.emplace_back(i);
        }
        return result;
    }

    /**
     * @description: Accept, 注意溢出
     * @param {vector<int>} &nums
     * @param {int} k
     * @return {*}
     */
    vector<int> getAverages(vector<int> &nums, int k) {
        int len = 2 * k + 1, n = nums.size();
        long long subtotal = 0;
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            subtotal += nums[i];
            if (i - len + 1 < 0)
                continue;
            result[i - k] = subtotal / len;
            subtotal -= nums[i - len + 1];
        }
        return result;
    }

    int minimumDeletions(vector<int> &nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end()), minNum = *min_element(nums.begin(), nums.end());
        int maxId, minId;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxNum)
                maxId = i;
            if (nums[i] == minNum)
                minId = i;
        }

        int begin = -1, end = n, result = 0;
        vector<int> vec = {minId, maxId};
        int first = 0;
        int tempMin = min(vec[first] - begin, end - vec[first]);
        if (min(vec[1] - begin, end - vec[1]) < tempMin)
            first = 1;
        if (vec[first] - begin < end - vec[first]) {
            result += vec[first] - begin;
            begin = vec[first];
        } else {
            result += end - vec[first];
            end = vec[first];
        }
        result += min(vec[!first] - begin, end - vec[!first]);

        return result;
    }

    /**
     * @description: BFS :(
     * @param {int} n
     * @param {int} firstPerson
     * @return {*}
     */
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> known = {0, firstPerson};
        return known;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> meetings = {{3,1,3},{1,2,2},{0,3,3}};
    s.findAllPeople(4, meetings, 3);
    return 0;
}