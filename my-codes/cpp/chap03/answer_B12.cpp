#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    double L = 0, R = n;
    for (int i = 0; i < 30; ++i) {
        double M = (L + R) / 2;
        if (M * M * M + M < n) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << R << endl;
}
