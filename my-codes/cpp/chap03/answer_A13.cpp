#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    int64_t ans = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
        while (pos < n && a.at(pos) - a.at(i) <= k) {
            ++pos;
        }
        --pos;
        ans += pos - i;
    }
    cout << ans << endl;
}
