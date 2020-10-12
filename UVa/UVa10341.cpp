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
#define EPS 1e-15
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int p,q,r,s,t,u;
double lo, mid, hi, poly;
bool FINISHED;

int main() {

    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        FINISHED = false;
        lo = 0.0;
        hi = 1.0;
        for (int i = 0; i < 50; i++) {
            mid = (lo+hi)/2;
            poly = p*exp(mid*-1) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*mid*mid + u;
            //cout << mid << " " << poly << endl;
            if (fabs(poly) < EPS) {
                printf("%.4lf\n", mid);
                FINISHED = true;
                break;
            }
            else if (poly > 0) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        if (!FINISHED) {
            cout << "No solution" << endl;
        }
    }

    return 0;
}
