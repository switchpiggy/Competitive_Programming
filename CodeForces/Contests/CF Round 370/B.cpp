#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll u = 0, d = 0, r = 0, l = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'U') u++;
        else if(s[i] == 'D') d++;
        else if(s[i] == 'R') r++;
        else l++;
    }

    if(abs(l - r)%2 == abs(d - u)%2) cout << abs(l - r)/2 + abs(d - u)/2 + abs(l - r)%2 << '\n';
    else cout << "-1\n";
    return 0; 
}