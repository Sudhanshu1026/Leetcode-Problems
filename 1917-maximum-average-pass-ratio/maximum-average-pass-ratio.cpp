#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator for max heap
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        priority_queue<pair<double, pair<int,int>>> pq;
        
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto [g, cls] = pq.top(); pq.pop();
            int p = cls.first, t = cls.second;
            p++, t++;
            pq.push({gain(p, t), {p, t}});
        }

        double total = 0.0;
        while (!pq.empty()) {
            auto [g, cls] = pq.top(); pq.pop();
            total += (double)cls.first / cls.second;
        }

        return total / classes.size();
    }
};
