/*
 * @Author: Radon
 * @Date: 2022-02-27 10:30:45
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-27 11:56:58
 * @Description: Hi, say something
 */
#include "../../headers/List.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
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
     * @param words
     * @param pref
     * @return int
     */
    int prefixCount(vector<string> &words, string pref) {
        int n = pref.length(), res = 0;
        for (auto word : words) {
            int len = word.length();
            if (len < n)
                continue;
            bool isPrefix = true;
            for (int i = 0; i < n; i++) {
                if (word[i] != pref[i]) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) {
                res++;
            }
        }
        return res;
    }

    /**
     * @brief Ac
     *
     * @param s
     * @param t
     * @return int
     */
    int minSteps(string s, string t) {
        vector<int> sv(26), tv(26);
        int res = 0;
        for (auto c : s)
            sv[c - 'a']++;
        for (auto c : t)
            tv[c - 'a']++;
        for (int i = 0; i < 26; i++)
            res += abs(sv[i] - tv[i]);
        return res;
    }

    /**
     * @brief overflow...
     *
     * @param time
     * @param totalTrips
     * @return long long
     */
    long long minimumTime(vector<int> &time, int totalTrips) {
        long long n = time.size(), denominator = 0, timeProd = 1, minTime = LLONG_MAX, res = 0;
        for (auto t : time) {
            timeProd = timeProd * (long long)t / (__gcd(timeProd, (long long)t));
        }
        for (auto t : time)
            denominator += timeProd / t;
        res = (timeProd * (long long)totalTrips - 1) / denominator + 1;

        while (true) {
            long long trips = 0;
            for (auto t : time) {
                trips += res / t;
            }
            if (trips >= (long long)totalTrips)
                break;
            res++;
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> time = {3, 3, 8};
    int totalTrips = 6;
    sol.minimumTime(time, totalTrips);
    return 0;
}