/*
 * @Author: Radon
 * @Date: 2022-04-30 22:29:21
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-01 00:11:21
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
    /**
     * @brief WA2, AC
     *
     * @param words
     * @param s
     * @return int
     */
    int countPrefixes(vector<string> &words, string s) {
        int minAvg = 0;
        for (auto word : words) {
            if (s.find(word) == 0)
                minAvg++;
        }
        return minAvg;
    }

    /**
     * @brief WA2 AC
     *
     * @param nums
     * @return int
     */
    int minimumAverageDifference(vector<int> &nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long leftSum = 0, rightSum = sum - leftSum;
        long long n = nums.size();
        long long left = 0, right = n;
        long long minAvg = INT_MAX, res = 0;

        if (n == 1)
            return 0;

        for (int i = 0; i < n; i++) {
            leftSum += nums[i];
            left++;
            rightSum -= nums[i];
            right--;
            long long leftAvg = leftSum / left;
            long long rightAvg = right == 0 ? 0 : rightSum / right;
            long long nowAvg = abs(leftAvg - rightAvg);
            if (nowAvg < minAvg) {
                minAvg = nowAvg;
                res = i;
            }
        }

        return res;
    }

    /**
     * @brief AC
     *
     * @param m
     * @param n
     * @param guards
     * @param walls
     * @return int
     */
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        vector<vector<int>> area(m, (vector<int>(n, 1))); // -1: wall, 0: guard, 1: safe, 2: unsafe

        for (auto wall : walls)
            area[wall[0]][wall[1]] = -1;
        for (auto guard : guards)
            area[guard[0]][guard[1]] = 0;

        for (auto guard : guards) {
            int x = guard[0], y = guard[1];
            while (x - 1 >= 0 && area[x - 1][y] != 0 && area[x - 1][y] != -1) // up
                area[--x][y] = 2;

            x = guard[0], y = guard[1];
            while (x + 1 < m && area[x + 1][y] != 0 && area[x + 1][y] != -1) // down
                area[++x][y] = 2;

            x = guard[0], y = guard[1];
            while (y - 1 >= 0 && area[x][y - 1] != 0 && area[x][y - 1] != -1) // left
                area[x][--y] = 2;

            x = guard[0], y = guard[1];
            while (y + 1 < n && area[x][y + 1] != 0 && area[x][y + 1] != -1) // left
                area[x][++y] = 2;
        }

        int res = 0;
        for (auto r : area)
            for (auto c : r)
                if (c == 1)
                    res++;
        return res;
    }

    int maximumMinutes(vector<vector<int>> &grid) {
        typedef pair<int, int> pii;
        queue<pii> qf, qp;

        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    qf.emplace(i, j);

        int fireTime = 0;
        vector<vector<int>> copy = grid;
        set<pii> vf;
        bool canFireEnd = false;
        while (!qf.empty()) {
            int size = qf.size();
            while (size--) {
                int x = qf.front().first;
                int y = qf.front().second;
                copy[x][y] = 1;

                if (x == m - 1 && y == n - 1) {
                    fireTime++;
                    canFireEnd = true;
                    goto person;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && copy[nx][ny] == 0 && vf.insert({nx, ny}).second)
                        qf.emplace(nx, ny);
                }

                qf.pop();
            }

            fireTime++;
        }

        if (!canFireEnd)
            return 1000000000;

    person:
        qp.emplace(0, 0);
        int moveTime = 0;
        set<pii> vp;
        while (!qp.empty()) {
            int size = qp.size();
            while (size--) {
                int x = qp.front().first;
                int y = qp.front().second;

                if (x == m - 1 && y == n - 1) {
                    moveTime++;
                    goto calculate;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 && vp.insert({nx, ny}).second)
                        qp.emplace(nx, ny);
                }

                qp.pop();
            }
            moveTime++;
        }

    calculate:
        if (fireTime < moveTime)
            return 0;
        return fireTime - moveTime - 1;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<vector<int>> grid = {{0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 2, 2, 1, 0}, {0, 2, 0, 0, 1, 2, 0}, {0, 0, 2, 2, 2, 0, 2}, {0, 0, 0, 0, 0, 0, 0}};
    sol.maximumMinutes(grid);
    return 0;
}