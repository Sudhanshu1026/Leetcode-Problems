#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1, 0) {}
    void reset(int n_) { n = n_; bit.assign(n+1,0); }
    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }
    int sumPrefix(int idx) const {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    int rangeSum(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l-1);
    }
};

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 2) return 0;

        // convert to pairs
        vector<pair<int,int>> pts;
        pts.reserve(n);
        for (auto &p : points) pts.emplace_back(p[0], p[1]);

        // SORT: x asc, and for equal x -> y DESC (important)
        sort(pts.begin(), pts.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        // coordinate compress y
        vector<int> ys;
        ys.reserve(n);
        for (auto &p : pts) ys.push_back(p.second);
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        auto getY = [&](int y) {
            return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1; // 1-indexed
        };

        long long ans = 0;
        int m = (int)ys.size();

        for (int i = 0; i < n; ++i) {
            Fenwick bit(m);
            for (int j = i; j < n; ++j) {
                bit.add(getY(pts[j].second), 1);
                if (j == i) continue;

                // allow equality on x or y (fence can be a line)
                if (pts[i].first <= pts[j].first && pts[i].second >= pts[j].second) {
                    int l = getY(pts[j].second);
                    int r = getY(pts[i].second);
                    int cnt = bit.rangeSum(l, r);
                    if (cnt == 2) ++ans; // only A and B are present in/on rectangle
                }
            }
        }

        return (int)ans;
    }
};
