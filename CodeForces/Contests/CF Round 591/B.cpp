#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q;
string s, t;
map<char, ll> occ;

int main() {
    cin >> q;
    while(q--) {
        cin >> s >> t;
        occ.clear();
        for(ll i = 0; i < s.length(); ++i) occ[s[i]]++;

        bool ok = 0;
        for(ll i = 0; i < t.length(); ++i) {
            if(occ[t[i]]) {
                ok = 1;
                break;
            }
        }

        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}