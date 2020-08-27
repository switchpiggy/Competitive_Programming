#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y;

int main() {
    for(ll i = 0; i < 5; ++i) {
        for(ll j = 0; j < 5; ++j) {
            ll temp;
            cin >> temp;
            if(temp == 1) {
                x = i;
                y = j;
                break;
            }
        }
    }

    cout << abs(x - 2) + abs(y - 2);
    return 0;
}