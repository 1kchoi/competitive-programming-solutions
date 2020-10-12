// CSES Problem Set - List Removals
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <array>
using namespace std;

int N;
set<array<int, 2>> S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        S.insert({i, a});
    }

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        set<array<int,2>>::iterator it = S.begin();
        advance(it, a-1);
        cout << (*it)[1] << " ";
        S.erase(it);
    }
    cout << endl;

    return 0;
}
