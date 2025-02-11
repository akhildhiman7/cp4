//
// Created by Akhil on 2025-02-11.
//

#include "../stdc++.h"
#include "../utils.h"

using namespace std;

/***
2 S
TH
9C
KS
QS
JS
TD
AD
JH
 */

void bela() {
    int n;
    char c;

    cin >> n >> c;
    cin.ignore();

    int points = 0;
    for (int i = 0; i < 4*n; i++) {
        string line;
        getline(cin, line);

        if (line[0] == 'A') {
            points += 11;
        } else if (line[0] == 'K') {
            points += 4;
        } else if (line[0] == 'Q') {
            points += 3;
        } else if (line[0] == 'J') {
            points += line[1] == c ? 20 : 2;
        } else if (line[0] == 'T') {
            points += 10;
        } else if (line[0] == '9') {
            points += line[1] == c ? 14 : 0;
        }
    }

    cout << points << endl;
}