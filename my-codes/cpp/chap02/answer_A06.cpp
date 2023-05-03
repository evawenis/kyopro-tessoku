#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    vector<int> sum(n + 1);
    sum.front() = 0;
    for (int i = 0; i < n; ++i) {
        sum.at(i + 1) = sum.at(i) + a.at(i);
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << sum.at(r) - sum.at(l - 1) << "\n"s;
    }
    cout << flush;
}
