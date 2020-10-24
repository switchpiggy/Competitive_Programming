#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<char, ll> occ;
ll n;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(ll i = 0; i < n; ++i) 
        for(ll j = 0; j < (ll)v[i].length(); ++j) occ[v[i][j]]++;

    for(char i = 'a'; i <= 'z'; ++i) {
        if(!occ[i]) {
            cout << i << '\n';
            return 0;
        } 
    }

    
    for(char fst = 'a'; fst <= 'z'; ++fst) {
        for(char scd = 'a'; scd <= 'z'; ++ scd) {
            bool ok = 1;
            string cur;
            cur += fst;
            cur += scd;
            for(ll i = 0; i < n; ++i) {
                for(ll j = 0; j < (ll)v[i].length() - 1; ++j) {
                    if(v[i].substr(j, 2) == cur) {
                        ok = 0;
                        break;
                    } 
                }

                if(!ok) break;
            }

            if(ok) {
                cout << cur << '\n';
                return 0;
            }
        }
    }
    return 0;
}