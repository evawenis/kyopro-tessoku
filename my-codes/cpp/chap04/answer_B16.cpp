#include <bits/stdc++.h>
using namespace std;

template<typename T> void chmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &&i: h) {
        cin >> i;
    }
    vector<int> dp(n, 1e9 + 1);
    dp.front() = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n) {
            chmin(dp.at(i + 1), dp.at(i) + abs(h.at(i) - h.at(i + 1)));
        }
        if (i + 2 < n) {
            chmin(dp.at(i + 2), dp.at(i) + abs(h.at(i) - h.at(i + 2)));
        }
    }
    cout << dp.back() << endl;
}
