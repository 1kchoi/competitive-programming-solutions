// Now I am become Death, the destroyer of worlds.
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>
#include <climits>
#include <fstream>
using namespace std;
#define cout fout
#define cin fin
#define ll long long
#define NMAX (int)(1e5 + 5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("cereal.in");
ofstream fout("cereal.out");

int N, M, cnt;
int F[NMAX];
int S[NMAX];
int occ[NMAX];
int ans[NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    memset(occ,0,sizeof(occ));

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i];
    }

    cnt = 0;
    for (int i = N-1; i >= 0; i--) {
        int j = i;
        int pos = F[i];
        while (true) {
            if (occ[pos] == 0) { // if the spot is empty;
                occ[pos] = j;
                cnt++;
                break;
            }
            else if (occ[pos] > j) { // if i comes before the occupant of the spot
                int k = occ[pos];
                occ[pos] = j;
                if (S[k] == pos) {
                    break;
                }
                pos = S[k];
                j = k;
            }
            else { // if i comes after the occupant of the spot
                break;
            }
        }
        ans[i] = cnt;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}
