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
    for (int i = 0; i < n; ++i) {
        if (i - 1 >= 0) {
            chmin(dp.at(i), dp.at(i - 1) + a.at(i - 1));
        }
        if (i - 2 >= 0) {
            chmin(dp.at(i), dp.at(i - 2) + b.at(i - 2));
        }
    }
    vector<int> p(1, n);
    for (int i = n - 1; i >= 1; --i) {
        if (dp.at(i) - dp.at(i - 1) == a.at(i - 1)) {
            p.emplace_back(i);
        } else {
            p.emplace_back(i - 1);
            --i;
        }
    }
    cout << p.size() << endl;
    for (int i = p.size() - 1; i >= 0; --i) {
        cout << " "s << p.at(i);
    }
    cout << endl;
}
