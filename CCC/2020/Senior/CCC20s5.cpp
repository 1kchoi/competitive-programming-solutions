#include <cstdio>
#include <iostream>
#include <vector>
#define MAXN 1000005
#define MAXM 500005
using namespace std;
typedef vector<int> vi;

int N, invar;
int line[MAXN];
int burgers[MAXM] = {0};

void printLine() {
    for (int i = 1; i <= N; i++) {
        cout << line[i] << " ";
    }
    cout << endl;
}
void printBurgers() {
    for (int i = 1; i <= N; i++) {
        cout << burgers[i] << " ";
        i++;
    }
    cout << endl;
}

double odds(int i, int burger, int burgerList[MAXM]) {
    burgerList[burger]--;
    while (burgerList[line[++i]] > 0 || i < N) {
        burgerList[line[i]]--;
    }
    if (i == N) {

    }

    burgerList[burger]++;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> invar;
        line[i] = invar;
        burgers[invar]++;
    }

}
