class MyCalendarTwo {
private:
    vector<pair<int, int>> single_bookings;
    vector<pair<int, int>> double_bookings;

public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for (auto &db : double_bookings) {
            if (max(start, db.first) < min(end, db.second)) {
                return false;
            }
        }
        
        for (auto &sb : single_bookings) {
            int overlap_start = max(start, sb.first);
            int overlap_end = min(end, sb.second);
            if (overlap_start < overlap_end) {
                double_bookings.push_back({overlap_start, overlap_end});
            }
        }
        
        single_bookings.push_back({start, end});
        return true;
    }
};