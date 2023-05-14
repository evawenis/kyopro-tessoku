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
    vector<int> a(n - 1), b(n - 2);
    for (auto &&i: a) {
        cin >> i;
    }
    for (auto &&i: b) {
        cin >> i;
    }
    vector<int> dp(n, 1e9);
    dp.front() = 0;
    for (int i = 1; i < n; ++i) {
        chmin(dp.at(i), dp.at(i - 1) + a.at(i - 1));
        if (i >= 2) {
            chmin(dp.at(i), dp.at(i - 2) + b.at(i - 2));
        }
    }
    cout << dp.back() << endl;
}
