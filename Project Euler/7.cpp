#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<ll> p;
bool composite[105000];

void sieve() {
    for(ll i = 2; i <= 105000; ++i) {
        if(composite[i]) continue;
        else {
            for(ll j = 2 * i; j <= 105000; j += i) composite[j] = 1;
        }
    }

    for(ll i = 2; i <= 105000; ++i) {
        if(!composite[i]) p.push_back(i);
    }
}

int main() {
    cin >> t;
    sieve();
    sort(p.begin(), p.end());
    while(t--) {
        cin >> n;
        cout << p[n - 1] << endl;
    }

    return 0;
}