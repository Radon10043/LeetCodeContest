/*
 * @Author: Radon
 * @Date: 2022-05-22 10:24:02
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-22 11:13:28
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

#include "../../headers/BinaryTree.h"
#include "../../headers/List.h"

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int x = 0, res = 0;
        for (auto &c : s) {
            if (c == letter)
                x++;
        }
        return 100 * x / s.length();
    }

    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        int n = capacity.size(), res = 0;
        vector<int> bags(n);
        for (int i = 0; i < n; i++)
            bags[i] = capacity[i] - rocks[i];
        sort(bags.begin(), bags.end());

        for (auto &bag : bags) {
            if (!bag) {
                res++;
                continue;
            }
            if (bag <= additionalRocks) {
                additionalRocks -= bag;
                res++;
            } else
                break;
        }
        return res;
    }

    int minimumLines(vector<vector<int>> &stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        int n = stockPrices.size(), res = 0;
        double k = 0;
        for (int i = 1; i < n; i++) {
            double nk = (double) (stockPrices[i][1] - stockPrices[i - 1][1]) / (double) (stockPrices[i][0] - stockPrices[i - 1][0]);
            if (fabs(k - nk) < 1e-20 && i > 1) {
                continue;
            } else {
                k = nk;
                res++;
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<vector<int>> stockPrices = {{1,1000000000},{1000000000,1000000000},{999999999,1},{2,999999999}};
    sol.minimumLines(stockPrices);
    return 0;
}