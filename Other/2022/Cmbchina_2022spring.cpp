/*
 * @Author: Radon
 * @Date: 2022-04-10 16:56:56
 * @LastEditors: Radon
 * @LastEditTime: 2022-04-10 18:19:30
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
    string deleteText(string article, int index) {
        int n = article.length();
        int l = index, r = index;

        if (article[index] == ' ')
            return article;

        while (l >= 0 && article[l] != ' ')
            l--;
        while (r < n && article[r] != ' ')
            r++;

        string res;
        if (l >= 0)
            res += article.substr(0, l);
        if (r < n)
            res += article.substr(r, n);

        if (res[0] == ' ')
            res.erase(res.begin());
        if (*(res.end() - 1) == ' ')
            res.erase(res.end() - 1);

        return res;
    }

    int numFlowers(vector<vector<int>> &roads) {
        map<int, vector<int>> mp;
        for (auto road : roads) {
            mp[road[0]].emplace_back(road[1]);
            mp[road[1]].emplace_back(road[0]);
        }

        int maxDegree = 0;
        for (auto piv : mp) {
            int newDegree = piv.second.size();
            maxDegree = max(maxDegree, newDegree);
        }

        return maxDegree + 1;
    }

    vector<int> lightSticks(int height, int width, vector<int> indices) {
        for (auto indice : indices) {
            int t = indice / (2 * width + 1);
            int cnt = indice % (2 * width + 1);
            int ps, pe;
            if (cnt < width) {
                ps = (width + 1) * t + cnt;
                pe = ps + 1;
            } else {
                ps = (width + 1) * t + (cnt - width);
                pe = ps + width + 1;
            }
            cout << ps << "," << pe << endl;
        }
        return {};
    }
};

int main(int argc, char **argv) {
    Solution sol;
    sol.lightSticks(1, 2, {3});
    return 0;
}