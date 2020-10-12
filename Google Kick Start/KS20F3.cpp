// Google Kick Start 2020 Round F Question 3 - Painter's Duel
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, S, pos[2][2], C, G[8][13], score, ans;
// G: -1 = empty, 0 = p0, 1 = p1, 2 = construction

int floodfill(int p) {
    int f = 0;
    queue<ii> Q;
    bool discovered[8][13];
    Q.push(ii(pos[p][0], pos[p][1]));
    discovered[pos[p][0]][pos[p][1]] = true;
    while (!Q.empty()) {
        ii v = Q.front(); Q.pop();
        int a = v.first, b = v.second;
        if (b > 1 && G[a][b-1] == -1 && !discovered[a][b-1]) { // move left
            Q.push(ii(a, b-1));
            discovered[a][b-1] = true;
            f++;
        }
        if (b < 2*a-1 && G[a][b+1] == -1 && !discovered[a][b+1]) { // move right
            Q.push(ii(a, b+1));
            discovered[a][b+1] = true;
            f++;
        }
        if ((b & 1) && a < S && G[a+1][b+1] == -1 && !discovered[a+1][b+1]) { // if pos is odd, move down
            Q.push(ii(a+1, b+1));
            discovered[a+1][b+1] = true;
            f++;
        }
        if (!(b & 1) && a > 1 && G[a-1][b-1] == -1 && !discovered[a-1][b-1]) { // if pos is odd, move down
            Q.push(ii(a-1, b-1));
            discovered[a-1][b-1] = true;
            f++;
        }
    }
    if (p) return -f;
    return f;
}

void move(int p);

void moveShell(int p) {
    G[pos[p][0]][pos[p][1]] = p;
    if (p) score--; else score++;
    //cout << "hi!" << endl;
    move(1-p);
    if (p) score++; else score--;
    G[pos[p][0]][pos[p][1]] = -1;
}

void move(int p) {
    cout << p << " " << pos[p][0] << " " << pos[p][1] << endl;
    bool stuck = true;
    if (pos[p][1] > 1 && G[pos[p][0]][pos[p][1]-1] == -1) { // move left
        pos[p][1]--;
        cout << p << " left to " << pos[p][0] << " " << pos[p][1] << endl;
        moveShell(p);
        pos[p][1]++;
        stuck = false;
    }
    if (pos[p][1] < 2*pos[p][0]-1 && G[pos[p][0]][pos[p][1]+1] == -1) { // move right
        pos[p][1]++;
        cout << p << " right to " << pos[p][0] << " " << pos[p][1] << endl;
        moveShell(p);
        pos[p][1]--;
        stuck = false;
    }
    if ((pos[p][1] & 1) && pos[p][0] < S && G[pos[p][0]+1][pos[p][1]+1] == -1) { // if pos is odd, move down
        pos[p][0]++;
        pos[p][1]++;
        cout << p << " down to " << pos[p][0] << " " << pos[p][1] << endl;
        moveShell(p);
        pos[p][0]--;
        pos[p][1]--;
        stuck = false;
    }
    if (!(pos[p][1] & 1) && pos[p][0] > 1 && G[pos[p][0]-1][pos[p][1]-1] == -1) { // if pos is even, move up
        pos[p][0]--;
        pos[p][1]--;
        cout << p << " up to " << pos[p][0] << " " << pos[p][1] << endl;
        moveShell(p);
        pos[p][0]++;
        pos[p][1]++;
        stuck = false;
    }

    if (stuck) { // if p is stuck perform flood fill
        int newscore = score + floodfill(1-p);
        cout << p << " is stuck! new score of " << newscore << endl;
        ans = max(ans, newscore);
        //cout << 5 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        score = ans = 0;
        memset(G, -1, sizeof(G));

        cin >> S >> pos[0][0] >> pos[0][1] >> pos[1][0] >> pos[1][1] >> C;
        for (int i = 0; i < 2; i++) {
            G[pos[i][0]][pos[i][1]] = i;
        }
        for (int i = 0; i < C; i++) {
            int x, y; cin >> x >> y;
            G[x][y] = 2;
        }

        move(0);

        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
