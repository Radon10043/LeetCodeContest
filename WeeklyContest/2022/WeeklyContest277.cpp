/*
 * @Author: Radon
 * @Date: 2022-01-23 10:39:49
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-23 11:29:03
 * @Description: Hi, say something
 */
#include <algorithm>
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
     * @return int
     */
    int countElements(vector<int> &nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[0] && nums[i] < nums[n - 1])
                res++;
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param nums
     * @return vector<int>
     */
    vector<int> rearrangeArray(vector<int> &nums) {
        int n = nums.size();
        queue<int> q1, q2;
        for (int num : nums) {
            if (num > 0)
                q1.push(num);
            else
                q2.push(num);
        }
        for (int i = 0; i < n; i += 2) {
            nums[i] = q1.front();
            nums[i + 1] = q2.front();
            q1.pop();
            q2.pop();
        }
        return nums;
    }

    /**
     * @brief Ac
     *
     * @param nums
     * @return vector<int>
     */
    vector<int> findLonely(vector<int> &nums) {
        map<int, int> umap;
        vector<int> res;
        for (int num : nums) {
            umap[num]++;
        }
        for (map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            if (it->second == 1 && !umap[it->first - 1] && !umap[it->first + 1])
                res.emplace_back(it->first);
        }
        return res;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums = {62, 35, 59, 55, 84, 61, 38, 87, 55, 82};
    sol.findLonely(nums);
    return 0;
}