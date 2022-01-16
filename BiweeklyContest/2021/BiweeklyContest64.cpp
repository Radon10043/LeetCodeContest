/*
 * @Author: Radon
 * @Date: 2021-10-30 22:35:45
 * @LastEditors: Radon
 * @LastEditTime: 2021-10-31 00:08:31
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @description: Accept
     * @param {vector<string>} &arr
     * @param {int} k
     * @return {*}
     */
    string kthDistinct(vector<string> &arr, int k) {
        map<string, int> cntMap;
        for (string data : arr) {
            if (cntMap.find(data) != cntMap.end())
                cntMap[data]++;
            else
                cntMap[data] = 1;
        }

        int idx = 0;
        for (string data : arr) {
            if (cntMap[data] == 1)
                idx++;
            if (idx == k)
                return data;
        }
        return "";
    }

    /**
     * @description: Timeout
     * @param {vector<vector<int>>} &events
     * @return {*}
     */
    int maxTwoEvents(vector<vector<int>> &events) {
        int n = events.size();
        unsigned long long maxValue = 0;
        for (int i = 0; i < n; i++) {
            maxValue = maxValue > events[i][2] ? maxValue : events[i][2]; //如果只选择一个活动
            for (int j = i; j < n; j++) {                                 //如果选择两个活动
                if (events[i][0] >= events[j][0] && events[i][0] <= events[j][1] || events[i][1] >= events[j][0] && events[i][1] <= events[j][1] ||
                    events[j][0] >= events[i][0] && events[j][0] <= events[i][1] || events[j][1] >= events[i][0] && events[j][1] <= events[i][1])
                    continue; //两个活动时间冲突
                else
                    maxValue = maxValue > events[i][2] + events[j][2] ? maxValue : events[i][2] + events[j][2];
            }
        }
        return maxValue;
    }

    /**
     * @description: Timeout
     * @param {string} s
     * @param {vector<vector<int>>} &queries
     * @return {*}
     */
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        int n = s.length();
        vector<int> candleLocVector, result;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                candleLocVector.emplace_back(i);
        }
        int candleLocVectorSize = candleLocVector.size();

        for (vector<int> q : queries) {
            int left = -1, right = -1, candleNum = 0;
            for (int i = 0; i < candleLocVectorSize && candleLocVector[i] <= q[1]; i++) {
                if (candleLocVector[i] >= q[0]) {
                    candleNum++;
                    right = candleLocVector[i];
                    if (left == -1)
                        left = candleLocVector[i];
                }
            }
            if (left == right)
                result.emplace_back(0);
            else
                result.emplace_back(right - left - candleNum + 1);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    string str = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {{1,17},{4,5},{14,17},{5,11},{15,16}};
    // cout << s.maxTwoEvents(events) << endl;
    s.platesBetweenCandles(str, queries);
    return 0;
}