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
    vector<int> sum(n + 1);
    sum.front() = 0;
    for (int i = 0; i < n; ++i) {
        sum.at(i + 1) = sum.at(i) + a.at(i);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int t = r - l + 1, w = (sum.at(r) - sum.at(l - 1)) * 2;
        if (w > t) {
            cout << "win\n"s;
        } else if (w < t) {
            cout << "lose\n"s;
        } else {
            cout << "draw\n"s;
        }
    }
    cout << flush;
}
