/*
 * @Author: Radon
 * @Date: 2021-12-12 10:40:30
 * @LastEditors: Radon
 * @LastEditTime: 2021-12-12 12:05:37
 * @Description: Hi, say something
 */
#include "..\..\headers\BinaryTree.h"
#include "..\..\headers\List.h"
#include <algorithm>
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
     * @param {string} rings
     * @return {*}
     */
    int countPoints(string rings) {
        int n = rings.length();
        unordered_map<char, unordered_set<char>> umap;
        for (int i = 0; i < n; i += 2) {
            umap[rings[i + 1]].insert(rings[i]);
        }

        int result = 0;
        for (unordered_map<char, unordered_set<char>>::iterator it = umap.begin(); it != umap.end(); it++) {
            if (it->second.size() == 3)
                result++;
        }
        return result;
    }

    /**
     * @description: Accept
     * @param {vector<int>} &nums
     * @return {*}
     */
    long long subArrayRanges(vector<int> &nums) {
        long long result = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int maxNum = nums[i], minNum = nums[i];
            for (int j = i; j < n; j++) {
                maxNum = max(maxNum, nums[j]);
                minNum = min(minNum, nums[j]);
                result += maxNum - minNum;
            }
        }
        return result;
    }

    /**
     * @description: Accept
     * @param {vector<int>} &plants
     * @param {int} capacityA
     * @param {int} capacityB
     * @return {*}
     */
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
        int n = plants.size();
        int i = 0, j = n - 1, addTimes = 0;
        int waterA = capacityA, waterB = capacityB;
        while (i <= j) {
            if (i == j) {
                int water = max(waterA, waterB);
                if (water - plants[i] < 0)
                    addTimes++;
                break;
            }

            if (waterA - plants[i] < 0) {
                addTimes++;
                waterA = capacityA;
            }
            waterA -= plants[i];
            i++;

            if (waterB - plants[j] < 0) {
                addTimes++;
                waterB = capacityB;
            }
            waterB -= plants[j];
            j--;
        }
        return addTimes;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}