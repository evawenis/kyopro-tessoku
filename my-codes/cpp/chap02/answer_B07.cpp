#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t >> n;
    vector<int> sum(t + 1, 0);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ++sum.at(l);
        --sum.at(r);
    }
    for (int i = 0; i < t; ++i) {
        sum.at(i + 1) += sum.at(i);
    }
    for (int i = 0; i < t; ++i) {
        cout << sum.at(i) << "\n"s;
    }
    cout << flush;
}
