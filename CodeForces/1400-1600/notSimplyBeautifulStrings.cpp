#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
map<char, ll> occ;
ll dist;

int main() {
    cin >> s;

    ll ok = 0;
    for(ll i = 0 ; i < s.length(); ++i) {
        if(!occ[s[i]]) {
            dist++;
        }
        occ[s[i]]++;
        if(occ[s[i]] == 2) ok++;
    }

    if((dist == 3 && ok) || (dist == 4) || (dist == 2 && ok >= 2)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}