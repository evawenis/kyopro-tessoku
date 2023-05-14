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
    int64_t n, w;
    cin >> n >> w;
    vector<int64_t> ww(n), vv(n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ww.at(i) >> vv.at(i);
        k += vv.at(i);
    }
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k + 1, 1e15));
    dp.front().front() = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < vv.at(i); ++j) {
            chmin(dp.at(i + 1).at(j), dp.at(i).at(j));
        }
        for (int j = vv.at(i); j <= k; ++j) {
            chmin(dp.at(i + 1).at(j), dp.at(i).at(j));
            chmin(dp.at(i + 1).at(j), dp.at(i).at(j - vv.at(i)) + ww.at(i));
        }
    }
    for (int i = k; i >= 0; --i) {
        if (dp.back().at(i) <= w) {
            cout << i << endl;
            return 0;
        }
    }
}
