/*
 * @Author: Radon
 * @Date: 2022-03-13 10:28:26
 * @LastEditors: Radon
 * @LastEditTime: 2022-03-13 12:05:25
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
    /**
     * @brief Ac
     *
     * @param nums
     * @param key
     * @param k
     * @return vector<int>
     */
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(i - j) <= k && nums[j] == key) {
                    res.emplace_back(i);
                    break;
                }
            }
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param n
     * @param artifacts
     * @param dig
     * @return int
     */
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig) {
        vector<vector<int>> grid(n, vector<int>(n));
        int res = 0;
        for (auto d : dig) {
            grid[d[0]][d[1]] = 1;
        }
        for (auto a : artifacts) {
            vector<vector<int>> locs;
            if (a[0] == a[2] && a[1] == a[3])
                locs.push_back({a[0], a[1]});
            else if (a[0] == a[2]) {
                for (int y = a[1]; y <= a[3]; y++) {
                    locs.push_back({a[0], y});
                }
            } else if (a[1] == a[3]) {
                for (int x = a[0]; x <= a[2]; x++) {
                    locs.push_back({x, a[1]});
                }
            } else {
                locs.push_back({a[0], a[1]});
                locs.push_back({a[0] + 1, a[1]});
                locs.push_back({a[0], a[1] + 1});
                locs.push_back({a[0] + 1, a[1] + 1});
            }

            bool isDig = true;
            for (auto l : locs) {
                if (grid[l[0]][l[1]] == 0) {
                    isDig = false;
                    break;
                }
            }
            if (isDig)
                res++;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}