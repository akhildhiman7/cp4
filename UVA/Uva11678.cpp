//
// Created by Akhil on 2025-02-08.
// Problem Statement: https://onlinejudge.org/external/116/11678.pdf
//

#include "../stdc++.h"
#include "../utils.h"

using namespace std;

int simulate11678(vector<int> &alice, vector<int> &betty) {
    set<int> aliceSet, bettySet;

    for (int i = 0; i < alice.size(); i++) {
        aliceSet.insert(alice[i]);
    }
    for (int i = 0; i < betty.size(); i++) {
        bettySet.insert(betty[i]);
    }

    int aliceCount = 0, bettyCount = 0;

    for (auto el: aliceSet) {
        if (bettySet.find(el) == bettySet.end()) {
            aliceCount++;
        }
    }

    for (auto el: bettySet) {
        if (aliceSet.find(el) == aliceSet.end()) {
            bettyCount++;
        }
    }

    return min(aliceCount, bettyCount);
}

/***
1 1
1000
1000
3 4
1 3 5
2 4 6 8
10 9
1 1 2 3 5 7 8 8 9 15
2 2 2 3 4 6 10 11 11
0 0
 */

void solve11678() {
    int a, b;
    cin >> a;
    cin >> b;
    while (a != 0 && b != 0) {

        vector<int> alice(a, 0), betty(b, 0);

        for (int i = 0; i < a; i++) {
            cin >> alice[i];
        }

        for (int i = 0; i < b; i++) {
            cin >> betty[i];
        }

        int result = simulate11678(alice, betty);
        cout << result << endl;

        cin >> a;
        cin >> b;
    }
}