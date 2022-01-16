/*
 * @Author: Radon
 * @Date: 2021-10-03 10:37:13
 * @LastEditors: Radon
 * @LastEditTime: 2021-10-03 11:32:53
 * @Description: Hi, say something
 */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int result = 0;
        int continous = 0;
        for (char c : s) {
            if (c == 'X' && !continous) {
                result++;
                continous++;
            } else if (continous) {
                continous++;
            }
            if (continous == 3) {
                continous = 0;
            }
        }
        return result;
    }

    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int sum, sum1;
        int m = 0, sum2 = 0;
        for (int num : rolls) {
            m++;
            sum2 += num;
        }
        sum = mean * (m + n);
        sum1 = sum - sum2;
        if (sum1 > n * 6 || sum1 <= 0 || sum1 / n <= 0)
            return {};

        int nMean;
        int originN = n;
        vector<int> result(originN, 0);
        for (int i = 0; i < originN; i++) {
            nMean = sum1 / n;
            result[i] = nMean;
            sum1 -= nMean;
            n--;
        }
        return result;
    }

    bool stoneGameIX(vector<int> &stones) {
        int delStonesSumVal = 0, turn = 0; //偶数alice, 奇数bob
        int n = stones.size();
        while (!stones.empty()) {
            int i = 0;
            bool isDeleted = false;
            for (; i < n; i++) {
                if ((delStonesSumVal + stones[i]) % 3) {
                    delStonesSumVal += stones[i];
                    stones.erase(stones.begin() + i, stones.begin() + i + 1);
                    n--;
                    isDeleted = true;
                    break;
                }
            }
            turn++;
            if (!isDeleted) {
                if (turn % 2)
                    return false;
                else
                    return true;
            }
        }
        if (!(delStonesSumVal % 3)) {
            if (turn % 2)
                return false;
            else
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> stones = {1, 1, 7, 10, 8, 17, 10, 20, 2, 10};
    cout << s.stoneGameIX(stones) << endl;
    return 0;
}