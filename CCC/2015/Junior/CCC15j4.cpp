// CCC '15 J4 - Wait Time
#include<cstdio>
#include <iostream>
using namespace std;

int current[101];
int total[101];
bool active[101];
int M;
int t;

string command; int num;

int main() {
    t = 0;
    cin >> M;

    // initialize
    for (int i = 0; i < 100; i++) {
        current[i] = -1;
        total[i] = 0;
    }

    // body
    for (int i = 0; i < M; i++) {
        cin >> command >> num;
        if (command == "R") { // receive
            active[num] = true;
            current[num] = t;
            t++;
        }
        else if (command == "S") { // send
            total[num] += t - current[num];
            current[num] = -1;
            t++;
        }
        else { // command is wait
            t += num-1;
        }
    }

    for (int i = 0; i < 101; i++) {
        if (active[i]) {
            if (current[i] == -1) {
                cout << i << " " << total[i] << endl;
            }
            else {
                cout << i << " " << -1 << endl;
            }
        }
    }
}
