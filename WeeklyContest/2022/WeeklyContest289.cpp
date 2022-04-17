/*
 * @Author: Radon
 * @Date: 2022-04-17 10:31:15
 * @LastEditors: Radon
 * @LastEditTime: 2022-04-17 10:58:39
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
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string ns;
            int cnt = 0, temp = 0;
            for (int i = 0; i < s.length(); i++) {
                cnt++;
                temp += s[i] - '0';
                if (cnt == k || i == s.length() - 1) {
                    ns += to_string(temp);
                    cnt = 0;
                    temp = 0;
                }
            }
            s = ns;
        }
        return s;
    }

    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> ump;
        for (auto task : tasks) {
            ump[task]++;
        }

        int res = 0;
        for (auto pii : ump) {
            if (pii.second < 2)
                return -1;
            res += ceil((double)pii.second / 3);
        }
        return res;
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {
        
    }
};

int main(int argc, char **argv) {
    Solution sol;
    sol.digitSum("11111222223", 3);
    return 0;
}