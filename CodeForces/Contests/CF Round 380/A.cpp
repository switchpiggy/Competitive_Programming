#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(ll i = 0; i < (ll)s.length() - 2; ++i) {
        if(s[i] == 'o' && s[i] == s[i + 2] && s[i + 1] == 'g') {
            ll j = i + 3;
            while(j + 1 < (ll)s.length() && s[j] == 'g' && s[j + 1] == 'o') j += 2;
            if(j > i + 3 && j <= (ll)s.length()) s.erase(s.begin() + i + 3, s.begin() + j);
            s[i] = s[i + 1] = s[i + 2] = '*';
            //cout << j << '\n';
            i += 2;
        }
    }

    cout << s << '\n';
    return 0;
}