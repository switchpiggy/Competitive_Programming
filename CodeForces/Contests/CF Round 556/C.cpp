#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ones, twos, temp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> temp;
        if(temp == 1) ones++;
        else twos++;
    }

    if(twos) {
        cout << 2 << ' ';
        for(ll i = 0; i < ones - (ones%2 == 0); ++i) cout << 1 << ' ';
        for(ll i = 0; i < twos - 1; ++i) cout << 2 << ' ';
        if(ones%2 == 0 && ones) cout << 1 << '\n';
    } else for(ll i = 0; i < ones; ++i) cout << 1 << ' ';

    return 0;
}