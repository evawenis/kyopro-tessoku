#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> x(h + 1, vector<int>(w + 1, 0)),
      y(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> x.at(i).at(j);
        }
    }
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j < w; ++j) {
            x.at(i).at(j + 1) += x.at(i).at(j);
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j <= w; ++j) {
            x.at(i + 1).at(j) += x.at(i).at(j);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << x.at(c).at(d) - x.at(a - 1).at(d) - x.at(c).at(b - 1) +
                  x.at(a - 1).at(b - 1)
             << "\n"s;
    }
    cout << flush;
}
