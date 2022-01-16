/*
 * @Author: Radon
 * @Date: 2021-12-16 16:46:20
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-21 17:05:47
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
    int minTimeToType(string word) {
        int result = 0;
        char p = 'a';
        for (char c : word) {
            int step1, step2;
            step1 = abs(c - p);
            step2 = min(p - 'a' + 'z' - c + 1, 'z' - p + c - 'a' + 1);
            result += min(step1, step2) + 1;
            p = c;
        }
        return result;
    }

    long long maxMatrixSum(vector<vector<int>> &matrix) {
        vector<long long> vec;
        for (auto row : matrix)
            for (auto data : row)
                vec.emplace_back(data);
        sort(vec.begin(), vec.end());

        long long sum = accumulate(vec.begin(), vec.end(), 0LL);
        int n = vec.size();
        for (int i = 0; i < n - 1; i += 2) {
            long long temp = sum - 2 * vec[i] - 2 * vec[i + 1];
            if (temp < sum)
                return sum;
            sum = temp;
        }
        return sum;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> matrix = {{-100, -100}, {-1, -1}, {-1, -1}};
    s.maxMatrixSum(matrix);
    return 0;
}