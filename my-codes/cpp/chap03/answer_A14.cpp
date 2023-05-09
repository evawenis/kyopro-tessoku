#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n), d(n);
    for (auto &&i: a) {
        cin >> i;
    }
    for (auto &&i: b) {
        cin >> i;
    }
    for (auto &&i: c) {
        cin >> i;
    }
    for (auto &&i: d) {
        cin >> i;
    }
    vector<int> ab(n * n), cd(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ab.at(n * i + j) = a.at(i) + b.at(j);
            cd.at(n * i + j) = c.at(i) + d.at(j);
        }
    }
    sort(cd.begin(), cd.end());
    for (auto &&i: ab) {
        int L = -1, R = n * n - 1;
        while (R - L > 1) {
            int M = (L + R) / 2;
            if (cd.at(M) + i < k) {
                L = M;
            } else {
                R = M;
            }
        }
        if (cd.at(R) + i == k) {
            cout << "Yes"s << endl;
            return 0;
        }
    }
    cout << "No"s << endl;
}
