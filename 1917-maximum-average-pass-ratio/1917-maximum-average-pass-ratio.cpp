class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        auto delta = [](int pass, int total) {
            double current_ratio = pass / (double)total;
            double new_ratio = (pass + 1) / (double)(total + 1);
            return new_ratio - current_ratio;
        };

        priority_queue<pair<double, pair<int, int>>> pq;
        
        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            pq.push({delta(pass, total), {pass, total}});
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto [max_delta, cls] = pq.top();
            pq.pop();

            int pass = cls.first, total = cls.second;
            pq.push({delta(pass + 1, total + 1), {pass + 1, total + 1}});
        }

        double total_ratio = 0.0;
        while (!pq.empty()) {
            auto [_, cls] = pq.top();
            pq.pop();
            int pass = cls.first, total = cls.second;
            total_ratio += pass / (double)total;
        }

        return total_ratio / classes.size();
    }
};
