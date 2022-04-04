/*
 * @Author: Radon
 * @Date: 2022-04-03 10:26:07
 * @LastEditors: Radon
 * @LastEditTime: 2022-04-04 15:55:09
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
     * @param current
     * @param correct
     * @return int
     */
    int convertTime(string current, string correct) {
        string curH, curM, corH, corM;
        curH = current.substr(0, 2);
        curM = current.substr(3, 2);
        corH = correct.substr(0, 2);
        corM = correct.substr(3, 2);

        int h1 = atoi(curH.c_str()), h2 = atoi(corH.c_str());
        int m1 = atoi(curM.c_str()), m2 = atoi(corM.c_str());
        int distance = (h2 - h1) * 60 + m2 - m1;
        int res = 0;

        while (distance) {
            if (distance >= 60)
                distance -= 60;
            else if (distance >= 15)
                distance -= 15;
            else if (distance >= 5)
                distance -= 5;
            else
                distance -= 1;
            res++;
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param matches
     * @return vector<vector<int>>
     */
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        map<int, int> mpw, mpl;
        for (auto match : matches) {
            mpw[match[0]]++;
            mpl[match[1]]++;
        }

        vector<vector<int>> res(2);
        for (auto pii : mpw) {
            if (!mpl[pii.first])
                res[0].emplace_back(pii.first);
        }
        for (auto pii : mpl) {
            if (pii.second == 1)
                res[1].emplace_back(pii.first);
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}