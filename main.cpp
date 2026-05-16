#include <bits/stdc++.h>

using namespace std;

const int _max = 1e4;
const int sz = 9;
const int steps = 4;

int current = 1;
int c[steps+1];

int A[sz] = {132, 422, 481, 536, 1044, 1101, 1161, 1452, 1581};
bool B[_max] = {false};

void step() {
    for ( int i = _max - 1; i >= 0; i-- ) {
        for ( int j = 0; j < sz; j++ ) {
            if ( i - A[j] >= 0 && B[i - A[j]] ) {
                B[i] = true;
                break;
            }
        }
    }

    int ans = 0;

    for (int d = 0; d < _max; d++) {
        for ( int start = 0; start < d; ++start) {
            int cur = start;
            int length = -1;

            while (cur < _max) {
                if (B[cur]) { length++; }
                else { length = -1;}

                if ( length > ans ) { ans = length; }

                cur += d;
            }
        }
    }

    c[current] = ans;
    current++;
}

int main() {
    for ( int i = 0; i < _max; i++) {
        B[i] = false;
    }

    B[0] = true;

    for ( int i = 0; i < steps; i++) {
        step();
    }

    for (int i = 1; i <= steps; i++) {
        cout << i << " " << c[i] << " " << (float)c[i] / i << endl;
    }

    bool flag = true;
    for ( int i = 1; i < steps; i++ ) {
        flag = flag && (c[i+1] * i >= c[i] * (i+1));
    }
    
    if ( flag ) {
        cout << "The sequence is non-decreasing." << endl;
    } else {
        cout << "The sequence is not non-decreasing." << endl;
    }

    return 0;
}