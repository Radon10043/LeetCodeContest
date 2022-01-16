/*
 * @Author: Radon
 * @Date: 2021-11-19 16:09:24
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-22 09:35:06
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
     * @return {*}
     */
    int countQuadruplets(vector<int> &nums) {
        int n = nums.size(), result = 0;
        int a, b, c, d;
        for (a = 0; a < n - 3; a++)
            for (b = a + 1; b < n - 2; b++)
                for (c = b + 1; c < n - 1; c++)
                    for (d = c + 1; d < n; d++)
                        if (nums[a] + nums[b] + nums[c] == nums[d])
                            result++;
        return result;
    }

    static bool myCmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] > b[0])
            return true;
        if (a[0] == b[0] && a[1] < b[1])
            return true;
        return false;
    }

    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        int n = properties.size(), result = 0, maxDef = -1;
        sort(properties.begin(), properties.end(), myCmp);
        for (int i = 0; i < n; i++) {
            if (properties[i][1] < maxDef)
                result++;
            maxDef = max(maxDef, properties[i][1]);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> properties = {{1, 1}, {2, 1}, {2, 2}, {1, 2}};
    s.numberOfWeakCharacters(properties);
    return 0;
}