/*
 * @Author: Radon
 * @Date: 2022-01-22 22:33:38
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-23 00:01:17
 * @Description: Hi, say something
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
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
     * @param cost
     * @return int
     */
    int minimumCost(vector<int> &cost) {
        int n = cost.size();
        int res = 0;
        sort(cost.begin(), cost.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (i % 3 == 2) {
                continue;
            } else {
                res += cost[i];
            }
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param differences
     * @param lower
     * @param upper
     * @return int
     */
    int numberOfArrays(vector<int> &differences, int lower, int upper) {
        typedef long long ll;
        int res = 0, n = differences.size();
        ll maxNum = INT_MIN, minNum = INT_MAX, num = lower;
        for (int i = 0; i < n + 1; i++) {
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
            if (i != n)
                num += differences[i];
        }
        if (upper - lower < maxNum - minNum)
            return 0;
        return (upper - lower) - (maxNum - minNum) + 1;
    }

    static bool itemsCmp(const vector<int> &a, const vector<int> &b) {
        if (a[2] < b[2]) //距离小的优先级高
            return true;
        else if (a[2] > b[2])
            return false;
        else {
            if (a[3] < b[3]) //距离相等的时候，价格低的优先级高
                return true;
            else if (a[3] < b[3])
                return false;
            else {
                if (a[0] < b[0]) //距离、价格相等的时候，行坐标小的优先级高
                    return true;
                else if (a[0] > b[0])
                    return false;
                else {
                    if (a[1] < b[1]) //距离、价格和行坐标相等的时候，列坐标小的优先级高
                        return true;
                }
            }
        }
        return false;
    }

    /**
     * @brief WA :(
     * 
     * @param grid 
     * @param pricing 
     * @param start 
     * @param k 
     * @return vector<vector<int>> 
     */
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k) {
        int m = grid.size(), n = grid[0].size();
        int distance = 0;
        vector<vector<int>> items;                                        //列长度为4: 行, 列, 距离, 价格
        vector<vector<int>> directs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //方向：上下左右
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            vector<int> oLoc = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                distance++;
                int nr = oLoc[0] + directs[i][0];
                int nc = oLoc[1] + directs[i][1];
                if (nr < m && nr >= 0 && nc < n && nc >= 0 && !visited[nr][nc]) {
                    if (grid[nr][nc] == 0)
                        continue;
                    if (grid[nr][nc] > 1) {
                        items.push_back({nr, nc, distance, grid[nr][nc]});
                        q.push({nr, nc});
                    }
                    visited[nr][nc] = true;
                }
            }
        }
        sort(items.begin(), items.end(), itemsCmp);

        vector<vector<int>> res;
        int nItems = items.size();
        k = min(k, nItems);
        for (int i = 0; i < k; i++) {
            res.push_back({items[i][0], items[i][1]});
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 0, 1}, {1, 3, 0, 1}, {0, 2, 5, 1}};
    vector<int> pricing = {2, 5}, start = {0, 0};
    int k = 3;
    sol.highestRankedKItems(grid, pricing, start, k);
    return 0;
}