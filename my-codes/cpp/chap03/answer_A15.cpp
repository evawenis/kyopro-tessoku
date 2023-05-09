// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int n;
//     cin >> n;
//     vector<pair<int, int>> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a.at(i).first;
//         a.at(i).second = i;
//     }
//     sort(a.begin(), a.end());
//     vector<int> b(n);
//     b.at(a.front().second) = 1;
//     for (int i = 1; i < n; ++i) {
//         if (a.at(i).first == a.at(i - 1).first) {
//             b.at(a.at(i).second) = b.at(a.at(i - 1).second);
//         } else {
//             b.at(a.at(i).second) = b.at(a.at(i - 1).second) + 1;
//         }
//     }
//     for (auto &&i: b) {
//         cout << " "s << i << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int upper(int value, vector<int> &a) {
    int L = -1, R = a.size();
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (a.at(M) <= value) {
            L = M;
        } else {
            R = M;
        }
    }
    return R;
}

int lower(int value, vector<int> &a) {
    int L = -1, R = a.size() - 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (a.at(M) < value) {
            L = M;
        } else {
            R = M;
        }
    }
    return R;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a.at(i);
        b.at(i) = a.at(i);
    }
    sort(b.begin(), b.end());
    vector<int> uniq;
    int cur = 0;
    while (cur < n) {
        uniq.emplace_back(b.at(cur));
        cur = upper(b.at(cur), b);
    }
    for (auto &&i: a) {
        cout << " "s << lower(i, uniq) + 1;
    }
    cout << endl;
}
