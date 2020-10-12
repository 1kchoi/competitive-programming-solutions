#include <cstring>
#include <iostream>
using namespace std;

bool b[50][50];

int main() {
    b[0][0] = true;
    //memset(b, false, sizeof(b));
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }
}
