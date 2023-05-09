#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    int64_t L = 0, R = 1e9;
    while (R - L > 1) {
        int64_t M = (L + R) / 2, tmp = 0;
        for (auto &&i: a) {
            tmp += M / i;
        }
        if (tmp < k) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << R << endl;
}
