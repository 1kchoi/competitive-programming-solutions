#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXSIZE 1005
using namespace std;
typedef pair<double, double> ii;
typedef vector<ii> vii;

int M, N;
int room[MAXSIZE][MAXSIZE];
bool discovered[MAXSIZE][MAXSIZE];
bool FINISHED = false;

void printRoom() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", room[i][j]);
        }
        printf("\n");
    }
}

void dfs(int r, int c) {
    if (r == M && c == N && !FINISHED) {
        //cout << "yes" << endl;
        FINISHED = true;
    }
    else {
        if (FINISHED) return;
        int value = room[r][c];
        for (int i = 1; i <= sqrt(value); i++) {
            if (value % i == 0) {
                if (i <= M && value/i <= N) {
                    if (!discovered[i][value/i]) {
                        discovered[i][value/i] = true;
                        dfs(i, value/i);
                    }
                }
                if (i <= N && value/i <= M) {
                    if (!discovered[value/i][i]) {
                        discovered[value/i][i] = true;
                        dfs(value/i, i);
                    }
                }
            }
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &room[i][j]);
        }
    }

    dfs(1,1);
    if (FINISHED) cout << "yes\n";
    else cout << "no\n";

    //printRoom();
}
