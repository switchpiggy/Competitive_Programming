#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> p;
bool sieve[2000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 2; i <= 2000000; ++i) {
        if(sieve[i]) continue;
        p.push_back(i);
        for(ll j = i * 2; j <= 2000000; j += i) sieve[j] = 1;
    }

    for(ll i = 0; i < n; ++i) cout << p[i] << ' ';
}