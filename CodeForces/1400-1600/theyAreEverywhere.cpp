#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dist;
string s;
map<char, ll> occ;

bool check(ll k) {
    occ.clear();
    ll d = 0;
    for(ll i = 0; i < k; ++i) {
        occ[s[i]]++;
        if(occ[s[i]] == 1) d++;
    }

    //for(ll i = 0; i < n; ++i) cout << occ[s[i]] << ' ';
    //cout << endl;

    if(d == dist) return 1;

    for(ll i = 1; i < n - k + 1; ++i) {
        occ[s[i - 1]]--;
        if(occ[s[i - 1]] == 0) d--;

        occ[s[i + k - 1]]++;
        if(occ[s[i + k - 1]] == 1) d++; 

        //for(ll i = 0; i < n; ++i) cout << occ[s[i]] << ' ';
        //cout << d << endl;

        if(d == dist) {
            return 1;
        }
    }

    return 0; 
}

int main() {
    cin >> n >> s;
    for(ll i = 0; i < s.length(); ++i) {
        occ[s[i]]++;
        if(occ[s[i]] == 1) dist++;
    }

    ll l = 1, r = n, ans = n;
    while(l < r) {
        ll m = (l + r)/2;
        if(check(m)) {
            ans = m;
            r = m;
        } else l = m + 1;
    }

    cout << ans << endl;
    return 0;
}