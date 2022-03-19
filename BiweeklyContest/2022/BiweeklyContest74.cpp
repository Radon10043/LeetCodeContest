/*
 * @Author: Radon
 * @Date: 2022-03-19 22:26:57
 * @LastEditors: Radon
 * @LastEditTime: 2022-03-20 00:07:13
 * @Description: Hi, say something
 */
/*
 * @Author: Radon
 * @Date: 2022-03-05 22:34:47
 * @LastEditors: Radon
 * @LastEditTime: 2022-03-06 00:04:58
 * @Description: Hi, say something
 */
#include <algorithm>
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
     * @brief Ac
     *
     * @param nums
     * @return true
     * @return false
     */
    bool divideArray(vector<int> &nums) {
        unordered_map<int, int> ump;
        for (auto num : nums) {
            ump[num]++;
        }
        for (auto pii : ump) {
            if (pii.second % 2)
                return false;
        }
        return true;
    }

    /**
     * @brief Ac
     *
     * @param text
     * @param pattern
     * @return long long
     */
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0, p0Nums = 0, p1Nums = 0;
        for (auto c : text) {
            if (c == pattern[0])
                p0Nums++;
            if (c == pattern[1]) {
                res += p0Nums;
                p1Nums++;
            }
        }
        if (pattern[0] != pattern[1])
            res += max(p0Nums, p1Nums);
        return res;
    }

    /**
     * @brief Ac
     *
     * @param nums
     * @return int
     */
    int halveArray(vector<int> &nums) {
        priority_queue<double, vector<double>> pq;
        int res = 0;
        double sum = 0, now = 0;
        for (auto num : nums) {
            pq.push((double)num);
            sum += (double)num;
        }
        now = sum;
        while (now > sum / 2) {
            double maxNum = pq.top();
            pq.pop();
            now -= maxNum / 2;
            maxNum /= 2;
            pq.push(maxNum);
            res++;
        }
        return res;
    }

    /**
     * @brief 2697 / 2698
     *
     * @param floor
     * @param numCarpets
     * @param carpetLen
     * @return int
     */
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.length();
        int black = count(floor.begin(), floor.end(), '0'), white = n - black;
        int len = carpetLen;

        string instead(carpetLen, '0');

        while (numCarpets > 0 && white > 0) {
            int l = 0, r = carpetLen - 1, b = 0, w = 0;
            for (int i = 0; i <= r; i++) {
                if (floor[i] == '0')
                    b++;
                else
                    w++;
            }

            while (r < n) {
                if (w == len) {
                    floor = floor.replace(floor.begin() + l, floor.begin() + r + 1, instead);
                    white -= len;
                    black += len;
                    w -= len;
                    b += len;
                    if (--numCarpets == 0)
                        break;
                }
                if (floor[l++] == '0')
                    b--;
                else
                    w--;
                if (++r > n - 1)
                    break;
                if (floor[r] == '0')
                    b++;
                else
                    w++;
            }
            len--;
        }

        return max(0, white);
    }
};

int main(int argc, char **argv) {
    Solution sol;
    string floor = "101111";
    sol.minimumWhiteTiles(floor, 2, 3);
    return 0;
}