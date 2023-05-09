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
    int64_t ans = 0, pos = 0, sum = 0;
    for (int64_t i = 0; i < n; ++i) {
        while (pos < n && sum - a.at(i) <= k) {
            sum += a.at(pos);
            ++pos;
        }
        if (pos >= i) {
            sum -= a.at(i);
        }
        ans += max(0L, pos - i);
        --pos;
    }
    cout << ans << endl;
}
