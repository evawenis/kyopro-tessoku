#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, false));
    dp.front().front() = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (dp.at(i).at(j)) {
                dp.at(i + 1).at(j) = true;
            }
            if (j - a.at(i) >= 0 && dp.at(i).at(j - a.at(i))) {
                dp.at(i + 1).at(j) = true;
            }
        }
    }
    vector<int> ans;
    for (int i = n - 1, cur = s; i >= 0; --i) {
        if (dp.at(i + 1).at(cur) && dp.at(i).at(cur)) {
            continue;
        }
        if (dp.at(i + 1).at(cur) && dp.at(i).at(cur - a.at(i))) {
            ans.emplace_back(i + 1);
            cur -= a.at(i);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << (ans.size() ? (int64_t)ans.size() : -1) << endl;
    for (auto &&i: ans) {
        cout << " "s << i;
    }
    cout << endl;
}
