// CCC '17 S2 - High Tide, Low Tide
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100
using namespace std;

int N, x;
vector<int> tides;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        tides.push_back(x);
    }

    sort(tides.begin(), tides.end());

    for (int i = (N-1)/2; i >= 0; i--) {
        if (i == 0 && N%2==1) {
            printf("%d", tides[i]);
            break;
        }
        printf("%d %d ", tides[i], tides[N-i-1+(N%2)]);
    }

}
