// CCC '13 S3 - Chances of Winning
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int T, G;
int a, b, sa, sb;
int t[5] = {0};
int dp[7][11][11][11][11]; // dp[i][a][b][c][d]
bool discovered[7][11][11][11][11];
vii games;

int teamWon() {
    for (int i = 1; i <= 4; i++) {
        if (i != T && t[T] <= t[i]) {
            return 0;
        }
    }
    return 1;
}

void printState(int i) {
    printf("%d: %d %d %d %d\n", i, t[1],t[2],t[3],t[4]);
}

int solve(int i) {
    //printState(i);
    if (!discovered[i][t[1]][t[2]][t[3]][t[4]]) {
        discovered[i][t[1]][t[2]][t[3]][t[4]] = true;
        if (i == 6) {
            int point = teamWon();
            dp[i][t[1]][t[2]][t[3]][t[4]] = point;
            //if (point == 1) cout << "bazinga" << endl;
        }
        else {
            int x = games[i-G].first;
            int y = games[i-G].second;
            //cout << x << " vs " << y << endl;
            int sum = 0;

            t[x] += 3;
            sum += solve(i+1);
            t[x] -= 3;

            t[y] += 3;
            sum += solve(i+1);
            t[y] -= 3;

            t[x] += 1; t[y] += 1;
            sum += solve(i+1);
            t[x] -= 1; t[y] -= 1;

            dp[i][t[1]][t[2]][t[3]][t[4]] = sum;
        }
    }
    return dp[i][t[1]][t[2]][t[3]][t[4]];
}

void initialize() {
    for (int i = 0; i < 6; i++)
        for (int a = 0; a < 5; a++)
            for (int b = 0; b < 5; b++)
                for (int c = 0; c < 5; c++)
                    for (int d = 0; d < 5; d++) {
                        discovered[i][a][b][c][d] = false;
                        dp[i][a][b][c][d] = 0;
                    }
}

void makeGames() {
    ii p;
    for (int i = 1; i <= 3; i++)
        for (int j = i+1; j <= 4; j++)
            games.push_back(make_pair(i,j));
}

int main() {
    cin >> T >> G;
    makeGames();
    initialize();
    for (int i = 0; i < G; i++) {
        cin>>a>>b>>sa>>sb;
        for (int j = 0; j < games.size(); j++) {
            if ((a == games[j].first && b == games[j].second) || (b == games[j].first && a == games[j].second)) {
                games.erase(games.begin()+j);
                break;
            }
        }

        if (sa > sb) t[a] += 3;
        else if (sa < sb) t[b] += 3;
        else {
            t[a] += 1;
            t[b] += 1;
        }
    }

    cout << solve(G) << endl;

    return 0;
}
