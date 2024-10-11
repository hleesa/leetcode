class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
            int n = times.size();
    vector<pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
        events.push_back({times[i][0], i});
    }
    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> availableChairs;
    for (int i = 0; i < n; ++i) {
        availableChairs.push(i);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

    for (const auto& event : events) {
        int arrivalTime = event.first;
        int friendIndex = event.second;

        while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrivalTime) {
            int chairToFree = occupiedChairs.top().second;
            occupiedChairs.pop();
            availableChairs.push(chairToFree);
        }

        int assignedChair = availableChairs.top();
        availableChairs.pop();

        if (friendIndex == targetFriend) {
            return assignedChair;
        }

        occupiedChairs.push({times[friendIndex][1], assignedChair});
    }
    return -1;
    }
};
