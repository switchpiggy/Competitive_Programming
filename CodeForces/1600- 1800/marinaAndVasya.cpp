#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t >> s1 >> s2;
    ll same = 0, diff = 0;
    for(ll i = 0; i < (ll)s1.length(); ++i) {
        if(s1[i] == s2[i]) same++;
        else diff++;
    }

    if(n - t > same + diff/2) {
        cout << "-1\n";
        return 0;
    } 

    if(n - t < same) {
        ll d = n - t;
        for(ll i = 0; i < n; ++i) {
            if(s1[i] == s2[i] && d) {
                d--;
                cout << s1[i];
            } else {
                for(char a = 'a';  a <= 'z'; ++a) {
                    if(a != s1[i] && a != s2[i]) {
                        cout << a;
                        break;
                    }
                }
            }
        }

        return 0;
    }

    ll d = (n - t) - same;
    ll prev = 0;

    for(ll i = 0; i < n; ++i) {
        if(!d && (s1[i] != s2[i])) {
            for(char a = 'a'; a <= 'z'; ++a) {
                if(a != s1[i] && a != s2[i]) {
                    cout << a;
                    break;
                }
            }
        } else if(s1[i] == s2[i]) {
            cout << s1[i];
        } else {
            if(prev%2 == 0) cout << s1[i];
            else cout << s2[i];
            prev++;
            if(prev%2 == 0) d--;
        }
    }

    cout << '\n';
    return 0;
}