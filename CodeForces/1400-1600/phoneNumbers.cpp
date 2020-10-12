#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
bool occ[26];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;
    for(ll i = 0; i < n; ++i) {
        //cout << s[i] - 'a' << '\n';
        occ[s[i] - 'a'] = 1;
    }

    char last, first = '.';
    for(ll i = 0; i < 26; ++i) {
        if(occ[i]) last = i + 'a';
        if(occ[i] && first == '.') first = i + 'a';
    }

    //cout << last << ' ' << first << '\n';

    if(k - 1 >= (ll)s.length()) {
        cout << s;
        for(ll i = 0; i < k - (ll)s.length(); ++i) cout << first;
        cout << '\n';

        return 0;
    }

    bool ok = 0;
    string t = "";
    for(ll i = k - 1; i >= 0; --i) {

        if(ok) {
            t.push_back(s[i]);
            continue;
        }

        if(s[i] == last) {
            t.push_back(first);
            continue;
        }

        char smallest = '.';
        for(ll c = s[i] - 'a' + 1; c < 26; ++c) {
            if(occ[c]) {
                smallest = c + 'a';
                break;
            }
        }

        ok = 1;
        t.push_back(smallest);
    }

    reverse(t.begin(), t.end());
    cout << t << '\n';
    
    return 0;
}