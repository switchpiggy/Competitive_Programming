#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string n;
ll occ[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll ans = 0;
    for(ll i = 0; i < (ll)n.length(); ++i) ans = (ans + (n[i] - '0')%3)%3;

    if(!ans) {
        cout << 0 << '\n';
        return 0;
    }

    for(ll i = 0; i < (ll)n.length(); ++i) {
        occ[(n[i] - '0')%3]++;
    }

    if(ans == 2) {
        if(occ[2] && (ll)n.length() > 1) cout << 1 << '\n';
        else if(occ[1] >= 2 && (ll)n.length() > 2) cout << 2 << '\n';
        else cout << "-1\n";
    } else if(ans == 1) {
        if(occ[1] && (ll)n.length() > 1) cout << 1 << '\n';
        else if(occ[2] >= 2 && (ll)n.length() > 2) cout << 2 << '\n';
        else cout << "-1\n";
    } else {
        if(occ[0] && (ll)n.length() > 1) cout << 1 << '\n';
        else if((ll)n.length() > 3 && (occ[2] >= 3 || occ[1] >= 3)) cout << 3 << '\n';
        else cout << "-1\n";
    }

    return 0;
}