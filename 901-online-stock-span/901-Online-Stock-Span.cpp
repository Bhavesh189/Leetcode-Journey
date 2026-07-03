class StockSpanner {
public:
    StockSpanner() {
        
    }

    stack<pair<int, int>> st;
    
    int next(int price) {
        if(st.empty()) {
            st.push({price, 1});
            return 1;
        } else {
            int a = 1;
            while(!st.empty() && st.top().first <= price) {
                a += st.top().second;
                st.pop();
            }

            st.push({price, a});

            return a;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */