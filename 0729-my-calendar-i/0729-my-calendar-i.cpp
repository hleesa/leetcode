class MyCalendar {
    vector<pair<int, int>> bookings;
    
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (const auto& [s, e] : bookings) {
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }
        bookings.push_back({start, end});
        return true; 
    }
};

