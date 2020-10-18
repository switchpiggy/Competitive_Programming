#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    string v = "";
    ll cnt = 0, last = -1;
    for(ll i = 0; i < (ll)t.length(); ++i) {
        if(t[i] != 'a') v += t[i];
        else {
            cnt++;
            last = i;
        }
    }

    if(v.substr(0, (ll)v.length()/2) == v.substr((ll)v.length()/2) && (ll)v.length()/2 + cnt > last) {
        cout << t.substr(0, (ll)v.length()/2 + cnt) << '\n';
    } else cout << ":(\n";

    return 0;
}