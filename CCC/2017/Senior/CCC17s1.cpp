// CCC '17 S1 - Sum Game
#include <cstdio>
#include <iostream>
#define MAX 100000
using namespace std;


int N, x;
bool found = false;
int a[MAX];
int b[MAX];

int main() {
    cin >> N;
    cin >> x; a[0] = x;
    for (int i = 1; i < N; i++) {
        cin >> x;
        a[i] = a[i-1] + x;
    }
    cin >> x; b[0] = x;
    for (int i = 1; i < N; i++) {
        cin >> x;
        b[i] = b[i-1] + x;
    }
    for (int i = N-1; i >= 0; i--) {
        if (a[i] == b[i]) {
            cout << i+1 << endl;;
            found = true;
            break;
        }
    }
    if (!found) cout << 0 << endl;;
    return 0;
}
