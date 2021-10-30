/*
 * @Author: Radon
 * @Date: 2021-10-16 22:37:19
 * @LastEditors: Radon
 * @LastEditTime: 2021-10-16 23:51:51
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
    int minMovesToSeat(vector<int> &seats, vector<int> &students) {
        int result = 0, n = seats.size();
        sort(students.begin(), students.end());
        sort(seats.begin(), seats.end());
        for (int i = 0; i < n; i++) {
            result += abs(seats[i] - students[i]);
        }
        return result;
    }

    bool winnerOfGame(string colors) {
        int n = colors.length();
        int turn = 0;
        if (n <= 2)
            return false; // n<=2时, Bob win

        int Alice = 0, Bob = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
                Alice++;
            else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
                Bob++;
        }
        if (Alice > Bob)
            return true;
        return false;
    }

    void getMinDistance(vector<vector<int>> edgesArr, unordered_map<int, int> &umap, int nodeNum) {
        unordered_set<int> nodeSet;
        queue<int> nodeQueue;
        int node, distance;
        for (int i = 1; i <= nodeNum; i++) {
            nodeSet.insert(i);
            nodeQueue.push(i);
            distance = 0;
            while (!nodeQueue.empty()) {
                node = nodeQueue.front();
                nodeQueue.pop();
            }
            umap[i] = distance;
        }
    }

    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) { return 0; }

    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long pq_size = 0;
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                pq.push((long long)num1 * num2);
                pq_size++;
            }
        }

        for (int i = 0; i < k - 1; i++)
            pq.pop();
        return pq.top();
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.winnerOfGame("ABBBBBBBAAA") << endl;
    return 0;
}