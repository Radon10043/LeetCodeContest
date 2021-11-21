/*
 * @Author: Radon
 * @Date: 2021-11-21 10:35:38
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-21 12:23:54
 * @Description: Hi, say something
 */
#include "headers\List.h"
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
    int maxDistance(vector<int> &colors) {
        int n = colors.size();
        vector<int> distance(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j])
                    distance[i] = max(distance[i], abs(j - i));
            }
        }
        return *max_element(distance.begin(), distance.end());
    }

    int wateringPlants(vector<int> &plants, int capacity) {
        int n = plants.size(), steps = 0, water = capacity;
        for (int i = 0; i < n; i++) {
            if (water < plants[i]) {
                steps += 2 * i + 1;
                water = capacity;
            } else
                steps++;
            water -= plants[i];
        }
        return steps;
    }

    /**
     * @description: Timeout
     * @param {int} k
     * @param {int} n
     * @return {*}
     */
    long long kMirror(int k, int n) {
        long long result = 0;
        int cnt = 0;
        for (int i = 1; cnt < n; i++) {
            string str1, str2;
            str1 = to_string(i);
            str2 = str1;
            reverse(str2.begin(), str2.end());
            if (str1 != str2)
                continue;
            str1.clear();
            str2.clear();

            int num = i;
            while (num) {
                str1 += to_string(num % k);
                num /= k;
            }
            str2 = str1;
            reverse(str2.begin(), str2.end());
            if (str1 == str2) {
                result += i;
                cnt++;
            }
        }
        return result;
    }
};

/*
 * Timeout
 * 用map的话value是排好序的，所以可以用二分查找，比赛时没想到
 */
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> cntMap;
    RangeFreqQuery(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            this->cntMap[arr[i]].emplace_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (cntMap.find(value) == cntMap.end())
            return 0;

        vector<int> &v = cntMap[value];
        int l = upper_bound(v.begin(), v.end(), left - 1) - v.begin();
        int r = upper_bound(v.begin(), v.end(), right) - v.begin();
        return r - l;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    s.kMirror(3, 7);
    vector<int> plants = {3, 2, 4, 2, 1};
    s.wateringPlants(plants, 6);
    return 0;
}