/*
 * @Author: Radon
 * @Date: 2022-02-06 10:32:02
 * @LastEditors: Radon
 * @LastEditTime: 2022-02-06 11:59:32
 * @Description: Hi, say something
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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
     * @param nums
     * @return vector<int>
     */
    vector<int> sortEvenOdd(vector<int> &nums) {
        int n = nums.size();
        vector<int> oddIdxVec, evenIdxVec;

        for (int i = 0; i < n; i++) {
            if (i % 2)
                oddIdxVec.push_back(nums[i]);
            else
                evenIdxVec.push_back(nums[i]);
        }

        sort(oddIdxVec.begin(), oddIdxVec.end(), greater<int>());
        sort(evenIdxVec.begin(), evenIdxVec.end());

        int j = 0, k = 0;
        for (int i = 0; i < n; i += 2) {
            nums[i] = evenIdxVec[j++];
            if (i + 1 < n)
                nums[i + 1] = oddIdxVec[k++];
        }
        return nums;
    }

    /**
     * @brief Ac
     *
     * @param num
     * @return long long
     */
    long long smallestNumber(long long num) {
        vector<int> vec;
        long long copy = num;

        while (copy) {
            vec.push_back(abs(copy % 10));
            copy /= 10;
        }

        int zeroNum = count(vec.begin(), vec.end(), 0);
        if (num > 0)
            sort(vec.begin(), vec.end());
        else
            sort(vec.begin(), vec.end(), greater<int>());

        long long res = 0;
        if (num > 0) {
            bool hasAddZero = false;
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == 0)
                    continue;
                if (res && !hasAddZero) {
                    res *= pow(10, zeroNum);
                    res = res * 10 + vec[i];
                    hasAddZero = true;
                } else
                    res = 10 * res + vec[i];
            }
            if (!hasAddZero)
                res *= pow(10, zeroNum);
        } else {
            for (int i = 0; i < vec.size(); i++) {
                res = 10 * res + vec[i];
            }
            res *= -1;
        }
        return res;
    }
};

class Bitset {
public:
    vector<int> v, vf;
    int v1num, vf1num;
    int size;

    Bitset(int size) {
        this->size = size;

        v = vector<int>(size, 0);
        v1num = 0;

        vf = vector<int>(size, 1);
        vf1num = size;
    }

    void fix(int idx) {
        if (v[idx] == 0)
            v1num++;
        v[idx] = 1;

        if (vf[idx] == 1)
            vf1num--;
        vf[idx] = 0;
    }

    void unfix(int idx) {
        if (v[idx] == 1)
            v1num--;
        v[idx] = 0;

        if (vf[idx] == 0)
            vf1num++;
        vf[idx] = 1;
    }

    void flip() {
        v.swap(vf);

        int tempI = v1num;
        v1num = vf1num;
        vf1num = tempI;
    }

    bool all() {
        if (v1num == size)
            return true;
        return false;
    }

    bool one() {
        if (v1num)
            return true;
        return false;
    }

    int count() {
        return v1num;
    }

    string toString() {
        string res;
        for (int bit : v) {
            res += to_string(bit);
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    string s = "1100101";
    return 0;
}