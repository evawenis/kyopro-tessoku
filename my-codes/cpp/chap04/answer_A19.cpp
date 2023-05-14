#include <bits/stdc++.h>
using namespace std;

template<typename T> void chmax(T &a, T b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    vector<int64_t> ww(n), vv(n);
    for (int i = 0; i < n; ++i) {
        cin >> ww.at(i) >> vv.at(i);
    }
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(w + 1, -1e15));
    dp.front().front() = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < ww.at(i); ++j) {
            chmax(dp.at(i + 1).at(j), dp.at(i).at(j));
        }
        for (int j = ww.at(i); j <= w; ++j) {
            chmax(dp.at(i + 1).at(j), dp.at(i).at(j));
            chmax(dp.at(i + 1).at(j), dp.at(i).at(j - ww.at(i)) + vv.at(i));
        }
    }
    cout << *max_element(dp.back().begin(), dp.back().end()) << endl;
}
