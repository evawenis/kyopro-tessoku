#include <bits/stdc++.h>
using namespace std;

void conquer(int L, int M, int R, vector<int> &v) {
    vector<int> tmp(R - L);
    for (int i = 0, l = L, m = M; i < R - L; ++i) {
        if (m >= R || (l < M && v.at(l) <= v.at(m))) {
            tmp.at(i) = v.at(l);
            ++l;
        } else {
            tmp.at(i) = v.at(m);
            ++m;
        }
    }
    for (int i = L; i < R; ++i) {
        v.at(i) = tmp.at(i - L);
    }
}

void divide(int L, int R, vector<int> &v) {
    if (R - L < 2) {
        return;
    }
    int M = (L + R) / 2;
    divide(L, M, v);
    divide(M, R, v);
    conquer(L, M, R, v);
}

void mergesort(vector<int> &v) {
    int L = 0, R = v.size();
    divide(L, R, v);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i: a) {
        cin >> i;
    }
    mergesort(a);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        int L = -1, R = n;
        while (R - L > 1) {
            int M = (L + R) / 2;
            if (a.at(M) < x) {
                L = M;
            } else {
                R = M;
            }
        }
        cout << R << endl;
    }
}
