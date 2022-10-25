class MyCalendarThree {
private:
    map<int, int> m_;

public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++m_[start];
        --m_[end];
        
        int ans = 0;
        int sum = 0;
        for (auto [k, v] : m_) {
            sum += v;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */