/*
 * @Author: Radon
 * @Date: 2022-05-14 22:29:58
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-14 23:39:13
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
    int divisorSubstrings(int num, int k) {
        string sn = to_string(num);
        int n = sn.length(), res = 0;

        for (int i = 0; i < n - k + 1; i++) {
            string now = sn.substr(i, k);
            int inow = atoi(now.c_str());
            if (inow && num % inow == 0)
                res++;
        }

        return res;
    }

    int waysToSplitArray(vector<int> &nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long left = 0, right = sum;
        int n = nums.size(), res = 0;

        for (int i = 0; i < n - 1; i++) {
            left += nums[i];
            right -= nums[i];

            if (left >= right)
                res++;
        }

        return res;
    }

    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size(), res = 0;
        int start = tiles[0][0], end = tiles[n - 1][1];
        int floorLen = tiles[n - 1][1];

        if (end - start <= carpetLen) {
            for (auto &&tile : tiles) {
                res += tile[1] - tile[0] + 1;
            }
            return res;
        }

        vector<bool> floor(floorLen + 1);
        for (auto &&tile : tiles) {
            for (int i = tile[0]; i <= tile[1]; i++)
                floor[i] = true;
        }

        int left = start, right = start + carpetLen - 1, now = 0;
        for (int i = left; i <= right; i++) {
            now += floor[i];
        }

        while (right <= floorLen) {
            if (floor[left++])
                now--;
            if (floor[++right])
                now++;
            res = max(res, now);
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<vector<int>> tiles = {{5802,5819},{5512,5532},{5749,5749},{5538,5555},{5771,5777},{5856,5873},{5778,5794},{5570,5589},{5751,5763},{5649,5658},{5605,5608},{5641,5641},{5837,5841},{5699,5712},{5485,5487},{5724,5735},{5620,5638},{5493,5494},{5677,5682}};
    int carpetLen = 2327;
    sol.maximumWhiteTiles(tiles, carpetLen);
    return 0;
}