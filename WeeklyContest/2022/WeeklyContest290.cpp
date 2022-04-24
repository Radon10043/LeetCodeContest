/*
 * @Author: Radon
 * @Date: 2022-04-24 10:26:26
 * @LastEditors: Radon
 * @LastEditTime: 2022-04-24 12:24:53
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
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> ump;

        for (auto num : nums) {
            for (auto data : num) {
                ump[data]++;
            }
        }

        for (auto pii : ump) {
            if (pii.second == n)
                res.emplace_back(pii.first);
        }
        sort(res.begin(), res.end());
        return res;
    }

    int countLatticePoints(vector<vector<int>> &circles) {
        int res = 0, xMax = 0, yMax = 0, xMin = INT_MAX, yMin = INT_MAX;
        for (auto &circle : circles) {
            xMax = max(xMax, circle[0] + circle[2]);
            yMax = max(yMax, circle[1] + circle[2]);
            xMin = min(xMin, circle[0] - circle[2]);
            yMin = min(yMin, circle[1] - circle[2]);
        }

        for (int i = xMin; i <= xMax; i++) {
            for (int j = yMin; j <= yMax; j++) {
                for (auto &circle : circles) {
                    if ((i - circle[0]) * (i - circle[0]) + (j - circle[1]) * (j - circle[1]) <= circle[2] * circle[2]) {
                        res++;
                        break;
                    }
                }
            }
        }

        return res;
    }

    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        vector<int> res;
        res.reserve(points.size());
        for (auto& point : points) {
            int cnt = 0;
            for (auto& rectangle : rectangles) {
                if (point[0] <= rectangle[0] && point[1] <= rectangle[1])
                    cnt++;
            }
            res.emplace_back(cnt);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<vector<int>> circles = {{100, 100, 1}};
    cout << sol.countLatticePoints(circles) << ",";
    return 0;
}