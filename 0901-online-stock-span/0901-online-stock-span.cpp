class StockSpanner {
public:
    stack<pair<int,int>> st;
    int length = 1;
    StockSpanner() {
       // Little steps each day can take you place which you could never have imagined in your life. 
    }
    
    int next(int price) {
        if (st.empty()) {st.push({price, length++}); return 1;}
        
        while(!st.empty() && st.top().first<=price){st.pop();}
        int res; 
        if (st.empty()) res = length;
        else res = length - st.top().second; st.push({price, length++});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */