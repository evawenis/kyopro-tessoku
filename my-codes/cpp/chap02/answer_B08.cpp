#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> g(1501, vector<int>(1501, 0));
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++g.at(y).at(x);
    }
    for (int i = 0; i < 1500; ++i) {
        for (int j = 0; j <= 1500; ++j) {
            g.at(i + 1).at(j) += g.at(i).at(j);
        }
    }
    for (int i = 0; i <= 1500; ++i) {
        for (int j = 0; j < 1500; ++j) {
            g.at(i).at(j + 1) += g.at(i).at(j);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        cout << g.at(d).at(c) - g.at(b).at(c) - g.at(d).at(a) + g.at(b).at(a)
             << "\n"s;
    }
    cout << flush;
}
