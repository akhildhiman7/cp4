//
// Created by Akhil on 2025-02-08.
// Problem: https://onlinejudge.org/external/103/10388.pdf
//

#include "../stdc++.h"
#include "../utils.h"

using namespace std;

void transferCards(deque<char> &deck1, deque<char> &deck2) {
    while (!deck1.empty()) {
        char card = deck1.front();
        deck1.pop_front();
        deck2.push_back(card);
    }
}

void printDeque(deque<char> deq) {
    while (!deq.empty()) {
        printf("%c", deq.back());
        deq.pop_back();
    }
    cout << endl;
}

void shiftCards(deque<char> &janeDeque, deque<char> &janeDown) {
    if (janeDown.size() == 0) {
        while (!janeDeque.empty()) {
            janeDown.push_back(janeDeque.front());
            janeDeque.pop_front();
        }
    }
}

void simulateGame10388(string john, string jane) {
    deque<char> johnDeque, janeDeque;
    deque<char> johnDown, janeDown;

    int cardsToWin = john.size() * 2;

    for (int i = 0; i < john.length(); i++) {
        johnDown.push_back(john[i]);
        janeDown.push_back(jane[i]);
    }

    int iterations = 0;

    while (iterations < 1000 && (cardsToWin != johnDown.size() and cardsToWin != janeDown.size())) {
        char johnCard = johnDown.front();
        char janeCard = janeDown.front();

        johnDown.pop_front();
        janeDown.pop_front();

        // cout << "Iteration: " << iterations << endl;
        // cout << "John: " << johnCard << endl;
        // cout << "Jane: " << janeCard << endl;

        janeDeque.push_back(janeCard);
        johnDeque.push_back(johnCard);

        if (johnCard == janeCard) {
            if (random() / 141 % 2 == 0) {
                transferCards(johnDeque, janeDeque);
                printf("Snap! for Jane: ");
                printDeque(janeDeque);
            } else {
                transferCards(janeDeque, johnDeque);
                printf("Snap! for John: ");
                printDeque(johnDeque);
            }
        }
        iterations++;

        if (janeDown.size() == 0) {
            shiftCards(janeDeque, janeDown);
        }

        if (johnDown.size() == 0) {
            shiftCards(johnDeque, johnDown);
        }

    }

    if (iterations < 1000) {
        string winner = johnDown.size() == cardsToWin ? "John" : "Jane";
        cout << winner << " wins." << endl;
    } else {
        cout << "Keep going and going ..." << endl;
    }
}

/*
*
1

ABCDA
CBADC
 */

void solve10388() {
    int n;
    cin >> n;

    while (n--) {
        cin.ignore();

        string jane, john;

        getline(cin, jane);
        getline(cin, jane);
        getline(cin, john);

        simulateGame10388(john, jane);
    }


}