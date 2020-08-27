#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, composite[1000001], pref[1000001];

void sieve() {
    composite[1] = 1;
    for(ll i = 2; i <= 1e6; ++i) {
        if(composite[i]) continue;
        for(ll j = 2 * i; j <= 1e6; j += i) composite[j] = 1;
    }

    for(ll i = 1; i <= 1e6; ++i) {
        pref[i] += pref[i - 1];
        if(!composite[i]) pref[i] += i;
    }

    return;
}

int main() {
    cin >> t;
    sieve();
    while(t--) {
        cin >> n;
        cout << pref[n] << endl;
    }

    return 0;
}