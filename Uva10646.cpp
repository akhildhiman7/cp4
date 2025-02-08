//
// Created by Akhil on 2025-02-08.
//

#include "stdc++.h"
#include "utils.h"
using namespace std;

vector<string> split(string s, char del) {
    stringstream ss(s);
    string token;
    vector<string> tokens;

    while (getline(ss, token, del)) {
        tokens.push_back(token);
    }

    return tokens;
}

int getCardVal(string card) {
    if (card[0] >= 'A' && card[0] <= 'Z') {
        return 10;
    }

    return card[0] - '0';
}

string whereIsTheCard(vector<string> &cards) {
    stack<string> cardsStack;

    for (int i = 0; i < cards.size(); i++) {
        cout << i << ":" << cards[i] << ", ";
    }

    for (int i = 0; i < 25; i++) {
        cardsStack.push(cards[i]);
    }

    int rounds = 3;
    int ix = 25;
    int y = 0;

    while (rounds--) {
        int cardVal = getCardVal(cards[ix]);

        y += cardVal;

        ix += 1 + 10 - cardVal;
    }

    while (ix < cards.size()) {
        cardsStack.push(cards[ix]);
        ix++;
    }

    while (y > 1 && cardsStack.size() > 1) {
        cardsStack.pop();
        y--;
    }

    cout << cardsStack.size() << endl;

    return cardsStack.top();
}


/*
AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S

AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S
 */

void solve10646() {
    int t;
    cin >> t;

    while (t--) {
        string val;
        cin.ignore();
        getline(cin, val);

        vector<string> cards = split(val, ' ');

        for (int i = 0; i < cards.size() / 2; i++) {
            swap(cards[i], cards[cards.size() - i - 1]);
        }

        string ans = whereIsTheCard(cards);

        printf("Case %d: %s", t + 1, ans.c_str());
    }

    return;
}