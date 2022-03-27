/*
 * @Author: Radon
 * @Date: 2022-03-27 10:39:26
 * @LastEditors: Radon
 * @LastEditTime: 2022-03-27 11:48:12
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
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> res(2);
        unordered_map<int, int> ump1, ump2;
        for (auto num : nums1)
            ump1[num]++;
        for (auto num : nums2)
            ump2[num]++;
        set<int> st1, st2;
        for (auto num : nums1) {
            if (!ump2[num])
                st1.insert(num);
        }
        for (auto num : nums2) {
            if (!ump1[num])
                st2.insert(num);
        }
        res[0] = vector<int>(st1.begin(), st1.end());
        res[1] = vector<int>(st2.begin(), st2.end());
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}