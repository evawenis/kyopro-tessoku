// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);
//     for (auto &&i: a) {
//         cin >> i;
//     }
//     vector<int> left, right;
//     for (int i = 0; i < (1 << (n / 2)); ++i) {
//         int64_t tmp = 0;
//         for (int j = 0; j < n / 2; ++j) {
//             if (i & (1 << j)) {
//                 tmp += a.at(j);
//             }
//         }
//         if (tmp <= k) {
//             left.emplace_back(tmp);
//         }
//     }
//     for (int i = 0; i < (1 << ((n + 1) / 2)); ++i) {
//         int64_t tmp = 0;
//         for (int j = 0; j < (n + 1) / 2; ++j) {
//             if (i & (1 << j)) {
//                 tmp += a.at(j + n / 2);
//             }
//         }
//         if (tmp <= k) {
//             right.emplace_back(tmp);
//         }
//     }
//     sort(right.begin(), right.end());
//     for (auto &&i: left) {
//         int ans = k - i, L = 0, R = right.size() - 1;
//         while (R - L > 1) {
//             int M = (L + R) / 2;
//             if (right.at(M) < ans) {
//                 L = M;
//             } else {
//                 R = M;
//             }
//         }
//         if (right.at(R) == ans) {
//             cout << "Yes"s << endl;
//             return 0;
//         }
//     }
//     cout << "No"s << endl;
// }

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, lefta, righta;

void dig(int cur, int limit, int64_t sum) {
    if (sum > k) {
        return;
    }
    if (cur == limit) {
        if (limit == n) {
            righta.emplace_back(sum);
        } else {
            lefta.emplace_back(sum);
        }
        return;
    }
    dig(cur + 1, limit, sum + a.at(cur));
    dig(cur + 1, limit, sum);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    for (auto &&i: a) {
        cin >> i;
    }
    dig(0, n / 2, 0);
    dig(n / 2, n, 0);
    sort(righta.begin(), righta.end());
    for (auto &&i: lefta) {
        int L = -1, R = righta.size() - 1, ans = k - i;
        while (R - L > 1) {
            int M = (L + R) / 2;
            if (righta.at(M) < ans) {
                L = M;
            } else {
                R = M;
            }
        }
        if (righta.at(R) == ans) {
            cout << "Yes"s << endl;
            return 0;
        }
    }
    cout << "No"s << endl;
}
