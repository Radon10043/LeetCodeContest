/*
 * @Author: Radon
 * @Date: 2021-11-13 22:35:53
 * @LastEditors: Radon
 * @LastEditTime: 2021-11-14 00:06:18
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: Accept
     * @param {string} word1
     * @param {string} word2
     * @return {*}
     */
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.length();
        unordered_map<char, int> word1Map, word2Map;
        for (int i = 0; i < n; i++) {
            word1Map[word1[i]]++;
            word2Map[word2[i]]++;
        }

        for (unordered_map<char, int>::iterator it = word1Map.begin(); it != word1Map.end(); it++) {
            if (abs(it->second - word2Map[it->first]) > 3)
                return false;
        }
        for (unordered_map<char, int>::iterator it = word2Map.begin(); it != word2Map.end(); it++) {
            if (abs(it->second - word1Map[it->first]) > 3)
                return false;
        }
        return true;
    }
};

/**
 * 第二题，Accept
 */
class Robot {
public:
    int cycle, cnt, loc, w, h;
    Robot(int width, int height) {
        cycle = (width + height) * 2 - 4;
        cnt = 0;
        loc = 0;
        w = width;
        h = height;
    }

    void move(int num) {
        cnt++;
        loc = (loc + num) % cycle;
    }

    vector<int> getPos() {
        if (!cnt)
            return {0, 0};
        if (loc < w)
            return {loc, 0};
        if (loc < w + h - 1)
            return {w - 1, loc - w + 1};
        if (loc < 2 * w + h - 2)
            return {w - loc % (w + h - 2) - 1, h - 1};
        return {0, h - loc % (2 * w + h - 2) - 2};
    }

    string getDir() {
        if (!cnt)
            return "East";
        if (!loc)
            return "South";
        if (loc < w && loc)
            return "East";
        if (loc < w + h - 1)
            return "North";
        if (loc < 2 * w + h - 2)
            return "West";
        return "South";
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}