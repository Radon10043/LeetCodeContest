/*
 * @Author: Radon
 * @Date: 2022-04-23 14:25:54
 * @LastEditors: Radon
 * @LastEditTime: 2022-04-23 17:52:56
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
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit) {
        int res = 0;
        for (auto fruit : fruits) {
            res += ceil((double)fruit[1] / limit) * time[fruit[0]];
        }
        return res;
    }

    int res = INT_MAX;

    void backtrack(vector<string> matrix, vector<int> end, int x, int y, int times, set<vector<int>> visited) {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
            return;

        while (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size()) {
            if (x == end[0] && y == end[1]) {
                res = min(res, times);
                return;
            }
            if (visited.count({x, y}))
                break;
            visited.insert({x, y});
            if (matrix[x][y] == '^' && x - 1 >= 0 && !visited.count({x - 1, y}))
                x--;
            else if (matrix[x][y] == 'v' && x + 1 < matrix.size() && !visited.count({x + 1, y}))
                x++;
            else if (matrix[x][y] == '<' && y - 1 >= 0 && !visited.count({x, y - 1}))
                y--;
            else if (matrix[x][y] == '>' && y + 1 < matrix[0].size() && !visited.count({x, y + 1}))
                y++;
        }

        if (y < end[1] && y + 1 < matrix[0].size())
            backtrack(matrix, end, x, y + 1, times + (matrix[x][y] != '>'), visited); //向右, y++
        if (y > end[1] && y - 1 >= 0)
            backtrack(matrix, end, x, y - 1, times + (matrix[x][y] != '<'), visited); //向左, y--
        if (x > end[0] && x - 1 >= 0)
            backtrack(matrix, end, x - 1, y, times + (matrix[x][y] != '^'), visited); //向上, x--
        if (x < end[0] && x + 1 < matrix.size())
            backtrack(matrix, end, x + 1, y, times + (matrix[x][y] != 'v'), visited); //向下, x++
    }

    void dfs(vector<string> matrix, vector<int> end, int x, int y, int times, set<vector<int>> visited) {
        if (x == end[0] && y == end[1]) {
            res = min(res, times);
            return;
        }

        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
            return;

        if (!visited.insert({x, y}).second)
            return;

        dfs(matrix, end, x, y + 1, times + (matrix[x][y] != '>'), visited); //向右, y++
        dfs(matrix, end, x, y - 1, times + (matrix[x][y] != '<'), visited); //向左, y--
        dfs(matrix, end, x - 1, y, times + (matrix[x][y] != '^'), visited); //向上, x--
        dfs(matrix, end, x + 1, y, times + (matrix[x][y] != 'v'), visited); //向下, x++
    }

    int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end) {
        set<vector<int>> visited;
        // dfs(matrix, end, start[0], start[1], 0, visited);
        backtrack(matrix, end, start[0], start[1], 0, visited);
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;

    vector<string> matrix = {">>v", "v^<", "<><"};
    vector<int> start = {0, 1}, end = {2, 0};
    sol.conveyorBelt(matrix, start, end);

    return 0;
}