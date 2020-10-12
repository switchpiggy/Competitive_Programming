#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string a, b;
ll pref[200007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for(ll i = 0; i < (ll)b.length(); ++i) {
        pref[i][b[i] - '0']++;
    }

    for(ll i = 1; i < (ll)b.length(); ++i) {
        pref[i][0] += pref[i - 1][0];
        pref[i][1] += pref[i - 1][1];        
    }

    ll ans = 0;
    pref[-1][0] = pref[-1][1] = 0;
    
    for(ll i = 0; i < (ll)a.length(); ++i) {
        //b.length() - a.length()
        if(a[i] == '0') ans += pref[(ll)b.length() - a.length() + i][1] - pref[i - 1][1];
        else ans += pref[(ll)b.length() - (ll)a.length() + i][0] - pref[i - 1][0];
    }

    cout << ans << '\n';
    return 0; 
}