/*
 * @Author: Radon
 * @Date: 2022-05-15 10:34:30
 * @LastEditors: Radon
 * @LastEditTime: 2022-05-15 11:02:02
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
    vector<string> removeAnagrams(vector<string> &words) {
        int n = words.size();
        vector<string> res;

        for (int i = 0; i < n;) {
            string word1 = words[i];
            sort(word1.begin(), word1.end());

            int j = i + 1;
            for (; j < n; j++) {
                string word2 = words[j];
                sort(word2.begin(), word2.end());

                if (word1.compare(word2) != 0) {
                    break;
                }
            }

            res.emplace_back(words[i]);
            i = j;
        }

        return res;
    }

    int maxConsecutive(int bottom, int top, vector<int> &special) {
        int res = 0, n = special.size();
        sort(special.begin(), special.end());
        res = max(special[0] - bottom, top - *(special.end() - 1));

        for (int i = 1; i < n; i++) {
            res = max(res, special[i] - special[i - 1] - 1);
        }
        return res;
    }

    int largestCombination(vector<int> &candidates) {
        unordered_map<int, int> ump;

        for (auto &&candidate : candidates) {
            for (int i = 0; i < 31; i++) {
                if (candidate & (1 << i))
                    ump[i]++;
            }
        }

        int res = 0;
        for (auto &&pii : ump) {
            res = max(res, pii.second);
        }
        return res;
    }
};

class CountIntervals {
private:
    unordered_set<int> ust;

public:
    CountIntervals() {}

    void add(int left, int right) {
        for (int i = left; i <= right; i++) {
            ust.insert(i);
        }
    }

    int count() {
        return ust.size();
    }
};

int main(int argc, char **argv) {
    Solution sol;
    return 0;
}