#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int d, n;
    cin >> d >> n;
    vector<int> c(d + 1, 0);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ++c.at(l - 1);
        --c.at(r);
    }
    for (int i = 0; i < d; ++i) {
        c.at(i + 1) += c.at(i);
    }
    for (int i = 0; i < d; ++i) {
        cout << c.at(i) << "\n"s;
    }
    cout << flush;
}
