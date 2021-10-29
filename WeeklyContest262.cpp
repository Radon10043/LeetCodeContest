/*
 * @Author: Radon
 * @Date: 2021-10-10 10:36:04
 * @LastEditors: Radon
 * @LastEditTime: 2021-10-10 12:11:35
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
        vector<int> result;
        int n1 = nums1.size(), n2 = nums2.size(), n3 = nums3.size();

        for (int data1 : nums1)
            for (int data2 : nums2)
                if (data1 == data2 && find(result.begin(), result.end(), data1) == result.end())
                    result.emplace_back(data1);

        for (int data1 : nums1)
            for (int data3 : nums3)
                if (data1 == data3 && find(result.begin(), result.end(), data1) == result.end())
                    result.emplace_back(data1);

        for (int data2 : nums2)
            for (int data3 : nums3)
                if (data2 == data3 && find(result.begin(), result.end(), data2) == result.end())
                    result.emplace_back(data2);

        return result;
    }

    int minOperations(vector<vector<int>> &grid, int x) {
        int r = grid.size(), c = grid[0].size();
        int sum = 0, diff = 0;
        map<int, int> cntMap;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                sum += grid[i][j];
                if (abs(grid[i][j] - grid[0][0]) % x != 0)
                    return -1;
            }
        }

        int avg = sum / (r + c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                diff += abs(avg - grid[i][j]);
            }
        }
        return diff / x;
    }
};

class StockPrice {
private:
    map<int, int> priceMap;
    pair<int, int> currentPrice;

public:
    StockPrice() {
        this->currentPrice.first = -1;
        this->currentPrice.second = -1;
    }

    void update(int timestamp, int price) {
        priceMap[timestamp] = price;
        if (timestamp >= this->currentPrice.first) {
            this->currentPrice.first = timestamp;
            this->currentPrice.second = price;
        }
    }

    int current() { return this->currentPrice.second; }

    int maximum() {
        int maxPrice = -1;
        for (pair<int, int> data : this->priceMap) {
            maxPrice = max(maxPrice, data.second);
        }
        return maxPrice;
    }

    int minimum() {
        int minPrice = -1;
        for (pair<int, int> data : this->priceMap) {
            if (minPrice < 0) {
                minPrice = data.second;
            } else {
                minPrice = min(minPrice, data.second);
            }
        }
        return minPrice;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> grid = {{931, 128}, {639, 712}};
    // 329+474+37+110
    s.minOperations(grid, 73);
    return 0;
}