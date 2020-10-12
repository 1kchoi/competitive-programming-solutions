#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXTIME 1000000005
using namespace std;
typedef pair<double, double> ii;
typedef vector<ii> vii;

int N, x, y;
vii pos;
ii p;
double ans = 0;

void printPos() {
    for (int i = 0; i < N; i++) {
        cout << pos[i].first << " " << pos[i].second << endl;
    }
}

bool sortFunc(ii a, ii b) {
    return a.first < b.first;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        p.first = x; p.second = y;
        pos.push_back(p);
    }

    sort(pos.begin(), pos.end(), sortFunc);

    for (int i = 1; i < N; i++) {
        double speed = abs((pos[i].second - pos[i-1].second)/(pos[i].first - pos[i-1].first));
        if (speed > ans) ans = speed;
    }

    printf("%.6f\n", ans);

    //printPos();

}
