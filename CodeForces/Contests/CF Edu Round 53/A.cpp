#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n;
map<char, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        occ.clear();
        string t;
        for(ll j = i; j < n; ++j) {
            t += s[j];
            occ[s[j]]++;
            bool ok = 1;
            for(char a = 'a'; a <= 'z'; ++a) {
                if(occ[a] > (j - i + 1)/2) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                cout << "YES\n" << t << '\n';
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}