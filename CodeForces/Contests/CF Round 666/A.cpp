#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
map<char, ll> occ;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        occ.clear();

        string temp;
        for(ll i = 0; i < n; ++i) {
            cin >> temp;
            for(ll j = 0; j < temp.length(); ++j) occ[temp[j]]++;
        }

        bool ok = 1;
        for(auto i = occ.begin(); i != occ.end(); ++i) {
            if(i->second%n != 0) {
                ok = 0;
                break;
            }
        }

        if(ok) cout <<"YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}