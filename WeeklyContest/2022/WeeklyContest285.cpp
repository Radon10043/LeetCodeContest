/*
 * @Author: Radon
 * @Date: 2022-03-20 10:37:50
 * @LastEditors: Radon
 * @LastEditTime: 2022-03-27 10:39:54
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int> &nums) {
        int n = nums.size(), res = 0;
        for (int i = 1; i < n - 1; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && nums[l] == nums[i])
                l--;
            while (r < n && nums[r] == nums[i])
                r++;
            if (l < 0 || r > n - 1)
                continue;
            if (nums[l] > nums[i] && nums[r] > nums[i] || nums[l] < nums[i] && nums[r] < nums[i]) {
                res++;
                i = r - 1;
            }
        }
        return res;
    }

    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = 0, res = 0;
        while (r < n) {
            if (r + 1 < n && directions[r + 1] == directions[l])
                r++;
            else {
                if (directions[l] == 'L' && l > 0)
                    res += r - l + 1;
                else if (directions[l] == 'R' && r < n - 1)
                    res += r - l + 1;
                l = r + 1;
                r = l;
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    string directions = "RLRSLL";
    sol.countCollisions(directions);
    return 0;
}