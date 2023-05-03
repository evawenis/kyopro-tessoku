#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);
    for (auto &&i: p) {
        cin >> i;
    }
    for (auto &&i: q) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p.at(i) + q.at(j) == k) {
                cout << "Yes"s << endl;
                return 0;
            }
        }
    }
    cout << "No"s << endl;
}
