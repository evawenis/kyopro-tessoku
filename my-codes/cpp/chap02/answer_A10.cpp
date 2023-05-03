#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    vector<int> L(n + 1), R(n + 1);
    L.front() = R.back() = 0;
    for (int i = 0; i < n; ++i) {
        L.at(i + 1) = max(L.at(i), a.at(i));
        R.at(n - i - 1) = max(R.at(n - i), a.at(n - i - 1));
    }
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i) {
        int l, r;
        cin >> l >> r;
        cout << max(L.at(l - 1), R.at(r)) << "\n"s;
    }
    cout << flush;
}
