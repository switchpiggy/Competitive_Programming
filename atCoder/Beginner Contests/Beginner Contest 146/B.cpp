#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        ll k = n;
        while(k--) {
            if(s[i] == 'Z') s[i] = 'A';
            else s[i]++;
        }
    }

    cout << s << '\n';
}