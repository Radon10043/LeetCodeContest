/*
 * @Author: Radon
 * @Date: 2021-12-01 16:56:20
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-01 17:37:48
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
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
     * @param {int} k
     * @return {*}
     */
    int minimumDifference(vector<int> &nums, int k) {
        if (k == 1)
            return 0;

        int n = nums.size(), result = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - k + 1; i++) {
            int high = *max_element(nums.begin() + i, nums.begin() + i + k);
            int low = *min_element(nums.begin() + i, nums.begin() + i + k);
            if (result == -1)
                result = high - low;
            else
                result = min(result, high - low);
        }
        return result;
    }

    /**
     * @description: 第二题的自定义排序方式
     * @param {string} &a
     * @param {string} &b
     * @return {*}
     */
    static bool myCmp(const string &a, const string &b) {
        int n1=a.length(), n2=b.length();
        if (n1 > n2)
            return true;
        if (n1 < n2)
            return false;
        for (int i = 0; i < n1; i++) {
            if (a[i] > b[i])
                return true;
            if (a[i] < b[i])
                return false;
        }
        return false;
    }

    /**
     * @description: Accept, 排序
     * @param {vector<string>} &nums
     * @param {int} k
     * @return {*}
     */
    string kthLargestNumber(vector<string> &nums, int k) {
        sort(nums.begin(), nums.end(), myCmp);
        return nums[k - 1];
    }

    /**
     * @description: WA
     * @param {int} sessionTime
     * @return {*}
     */
    int minSessions(vector<int>& tasks, int sessionTime) {
        int workTime = sessionTime, cnt = 1;
        sort(tasks.begin(), tasks.end());
        for (int task : tasks) {
            if (workTime < task) {
                cnt++;
                workTime = sessionTime - task;
            }
            else workTime -= task;
        }
        return cnt;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> tasks = {7,4,3,8,10};
    s.minSessions(tasks, 12);
    return 0;
}