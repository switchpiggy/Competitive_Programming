#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        ll a = 0, b = 0;
        bool ok = 1;
        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(s[i] == '(') {
                a = i;
            } else if(s[i] == ')') {
                b = i;
            }
        }

        if((ll)s.length()%2 == 1 || b == 0 || a == (ll)s.length() - 1) cout << "NO\n"; 
        else cout << "YES\n";
    }
}