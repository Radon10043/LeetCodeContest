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
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                int cnt0 = 0, cnt1 = 0;
                for (auto &c : sub) {
                    if (c == '0') {
                        cnt0++;
                    } else {
                        cnt1++;
                    }
                }
                if (cnt0 <= k || cnt1 <= k) {
                    res++;
                }
            }
        }
        return res;
    }

    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB) {
        int n = energyDrinkA.size();
        long long res = 0;
        vector<vector<long long>> dp(n, vector<long long>(2, 0));

        dp[0][0] = energyDrinkA[0];
        dp[0][1] = energyDrinkB[0];
        dp[1][0] = energyDrinkA[1] + energyDrinkA[0];
        dp[1][1] = energyDrinkB[1] + energyDrinkB[0];
        for (int i = 2; i < n; i++) {
            dp[i][0] = max((long long)dp[i - 1][0] + energyDrinkA[i], (long long)dp[i - 2][1] + energyDrinkB[i]);
            dp[i][1] = max((long long)dp[i - 1][1] + energyDrinkB[i], (long long)dp[i - 2][0] + energyDrinkA[i]);
        }
        res = max(dp[n - 1][0], dp[n - 1][1]);
        res = max(res, dp[n - 2][0]);
        res = max(res, dp[n - 2][1]);
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}