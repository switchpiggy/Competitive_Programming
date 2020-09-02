#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<ll> pos;

int main() {
    cin >> t;
    while(t--) {
        pos.clear();
        string s, t;
        cin >> n >> s >> t;
        if(s == t) {
            cout << "Yes" << endl;
            continue;
        }
        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] != t[i]) pos.push_back(i);
        }

        if(pos.size() > 2 || pos.size() == 1) {
            cout << "No" << endl;
            continue;
        }

        if(s[pos[0]] == s[pos[1]] && t[pos[1]] == t[pos[0]]) {
            cout << "Yes" << endl;
            continue;
        }

        cout << "No" << endl;
    }

    return 0;
}