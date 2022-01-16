/*
 * @Author: Radon
 * @Date: 2021-12-11 22:37:17
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-12 00:08:12
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
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        vector<int> origin = nums;
        vector<int> result;
        unordered_map<int, int> umap;

        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < k; i++)
            umap[nums[i]]++;
        for (int num : origin) {
            if (umap[num]) {
                result.emplace_back(num);
                umap[num]--;
            }
        }
        return result;
    }

    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = security.size();
        vector<int> result;
        if (n < 2 * time + 1)
            return {};
        if (time == 0) {
            for (int i = 0; i < n; i++) {
                result.emplace_back(i);
            }
            return result;
        }

        vector<int> vec = {0}; // vec用于存储增减情况，-1表示与前一个数相比减少，0相等，1增加
        for (int i = 1; i < n; i++) {
            if (security[i] > security[i - 1])
                vec.emplace_back(1);
            else if (security[i] < security[i - 1])
                vec.emplace_back(-1);
            else
                vec.emplace_back(0);
        }

        unordered_map<int, int> left, right;
        for (int i = 1; i <= time; i++)
            left[vec[i]]++;
        for (int i = time + 1; i < 2 * time + 1; i++)
            right[vec[i]]++;
        for (int i = time; i < n - time; i++) {
            if (left[1] == 0 && right[-1] == 0)
                result.emplace_back(i);
            left[vec[i - time + 1]]--;
            left[vec[i + 1]]++;
            right[vec[i + 1]]--;
            if (i + time + 1 < n) {
                right[vec[i + time + 1]]++;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> security = {1, 2, 5, 4, 1, 0, 2, 4, 5, 3, 1, 2, 4, 3, 2, 4, 8};
    s.goodDaysToRobBank(security, 2);
    return 0;
}