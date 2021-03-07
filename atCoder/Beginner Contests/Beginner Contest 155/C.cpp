#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<string, ll> m;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m[s]++;
    }

    ll maxn = 0;
    for(auto i = m.begin(); i != m.end(); ++i) {
        if(i->second > maxn) maxn = i->second; 
    }

    for(auto i = m.begin(); i != m.end(); ++i) {
        if(maxn == i->second) cout << i->first << '\n';
    }

    return 0;
}