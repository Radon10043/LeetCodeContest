/*
 * @Author: Radon
 * @Date: 2023-07-26 16:53:31
 * @LastEditors: Radon
 * @LastEditTime: 2023-07-26 17:08:45
 * @Description: 并查集模板, 代码与思路来自 https://leetcode.cn/problems/path-with-minimum-effort/
 */
#include <numeric>
#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> size;
    vector<int> parent; /* 记录各元素祖先的数组 */
    int n;              /* 元素数量 */
    int setCount;       /* 连通分量数量 */

    UnionFind(int _n) : parent(_n), size(_n, 1), n(_n), setCount(_n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool united(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        setCount--;
        return true;
    }

    bool connect(int x, int y) {
        x = find(x);
        y = find(y);
        return x == y;
    }
};