#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<pair<int, int>> st; // pair<price, index>

    for (int i = 0; i < n; ++i) {

        
        while (!st.empty() && st.top().first <= prices[i]) {
            st.pop();
        }


        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top().second;
        }

        st.push({prices[i], i});
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(prices);

    cout << "Stock spans: ";
    for (int s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
