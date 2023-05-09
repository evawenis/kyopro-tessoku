#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    int L = -1, R = n - 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (a.at(M) < x) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << R + 1 << endl;
}
