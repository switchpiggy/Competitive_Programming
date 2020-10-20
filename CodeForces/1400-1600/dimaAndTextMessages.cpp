#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<string> v;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.push_back("<3");
    for(ll i = 0; i < n; ++i) {
        string t;
        cin >> t;
        t += '<';
        t += '3';
        v.push_back(t);
    }

    cin >> s;

    ll j = 0, cur = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == v[j][cur]) {
            cur++;
            if(cur == (ll)v[j].length()) {
                cur = 0;
                j++;
            }
        }

        if(j == n + 1) {
            cout << "yes\n";
            return 0;
        }
    }

    cout << "no\n";
    return 0;
}