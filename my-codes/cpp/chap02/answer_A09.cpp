#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> z(h + 1, vector<int>(w + 1, 0));
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        ++z.at(a).at(b);
        --z.at(a).at(d);
        --z.at(c).at(b);
        ++z.at(c).at(d);
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j <= w; ++j) {
            z.at(i + 1).at(j) += z.at(i).at(j);
        }
    }
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j < w; ++j) {
            z.at(i).at(j + 1) += z.at(i).at(j);
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << " "s << z.at(i).at(j);
        }
        cout << "\n"s;
    }
    cout << flush;
}
