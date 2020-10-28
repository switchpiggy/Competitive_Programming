#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
map<ll, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, s);
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(isalpha(s[i])) occ[s[i]]++;
    }

    cout << (ll)occ.size() << '\n';
    return 0;
}