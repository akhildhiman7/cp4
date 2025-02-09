//
// Created by Akhil on 2025-02-08.
// Problem Statement: https://onlinejudge.org/external/122/12247.pdf
//

#include "../stdc++.h"
#include "../utils.h"

// #include<bits/stdc++.h>

using namespace std;

int getLowest(const set<int> &st, const int start) {
    for (int i = start; i < 53; i++) {
        if (st.find(i) == st.end()) {
            return i;
        }
    }
    return -1;
}

int canWin(const int x, const int y) {
    return x < y;
}

bool simulate12247(const int a, const int b, const int c, const int x, const int y, const int z) {
    const int case1 = canWin(a, x) + canWin(b, y) + canWin(c, z);
    const int case2 = canWin(a, x) + canWin(b, z) + canWin(c, y);
    const int case3 = canWin(b, x) + canWin(a, y) + canWin(c, z);
    const int case4 = canWin(b, x) + canWin(a, z) + canWin(c, y);
    const int case5 = canWin(c, x) + canWin(b, y) + canWin(a, z);
    const int case6 = canWin(c, x) + canWin(b, z) + canWin(a, y);

    return case1 >= 2 && case2 >= 2 && case3 >= 2 && case4 >= 2 && case5 >= 2 && case6 >= 2;
}

int canWin(int a, int b, int c, int x, int y) {
    const set<int> st = {a, b, c, x, y};

    for (int i = 1; i <= 52; i++) {
        const int card = getLowest(st, i);

        if (simulate12247(a, b, c, x, y, card)) {
            return card;
        }
    }

    return -1;
}

/**
28 51 29 50 52
50 26 19 10 27
10 20 30 24 26
46 48 49 47 50
0 0 0 0 0
 */
void solve12247() {
    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    while (a != 0 && b != 0 && c != 0 && x != 0 && y != 0) {
        cout << canWin(a, b, c, x, y) << endl;
        cin >> a >> b >> c >> x >> y;
    }

    return;
}