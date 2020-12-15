#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s = "2020";
string v;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> v;
        if(v == "2020") {
            cout << "YES\n";
            continue;
        }

        if((ll)v.size() < 4) {
            cout << "NO\n";
            continue;
        }

        ll pref = 0, suff = 0;
        for(ll i = 1; i <= 4; ++i) {
            if(v.substr(0, i) == s.substr(0, i)) pref = i;
        }

        for(ll i = 1; i <= 4; ++i) {
            if(v.substr((ll)v.length() - i) == s.substr((ll)s.length() - i)) suff = i;
            
        }

        cout << (pref + suff >= 4 ? "YES\n" : "NO\n");
        //cout << pref << ' ' << suff << '\n';
    }
}