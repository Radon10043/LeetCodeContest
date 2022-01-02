/*
 * @Author: Radon
 * @Date: 2022-01-02 10:35:16
 * @LastEditors: Radon
 * @LastEditTime: 2022-01-02 11:19:00
 * @Description: Hi, say something
 */
#include "headers/BinaryTree.h"
#include "headers/List.h"
#include <algorithm>
#include <iostream>
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
     * @param s
     * @return true
     * @return false
     */
    bool checkString(string s) {
        int last_a = -1, first_b = -1;
        int n = s.length();
        bool meet_b = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                last_a = i;
            if (s[i] == 'b' && !meet_b) {
                first_b = i;
                meet_b = true;
            }
        }

        if (last_a > first_b && last_a != -1 && first_b != -1)
            return false;
        return true;
    }

    /**
     * @brief Ac
     *
     * @param bank
     * @return int
     */
    int numberOfBeams(vector<string> &bank) {
        int result = 0, prev = 0, cur = 0;
        int n = bank.size();
        for (int i = 0; i < n; i++) {
            for (char c : bank[i]) {
                if (c == '1')
                    cur++;
            }

            if (!cur)
                continue;
            result += prev * cur;
            prev = cur;
            cur = 0;
        }
        return result;
    }

    /**
     * @brief Ac
     *
     * @param mass
     * @param asteroids
     * @return true
     * @return false
     */
    bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long massll = mass;
        for (int data : asteroids) {
            if (data <= massll)
                massll += data;
            else
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}