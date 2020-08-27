#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
map<string, ll> occ;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        ll temp;

        cin >> s >> temp;
        occ[s] = max(occ[s], temp);
    }

    cout << occ.size() << endl;
    for(auto i = occ.begin(); i != occ.end(); ++i) {
        ll c = 0;
        for(auto j = occ.begin(); j != occ.end(); ++j) {
            if(i->second >= j->second) c++;
        }

        //cout << c << endl;

        cout << i->first << ' ';
        if(100 * c >= 99 * occ.size()) cout << "pro" << endl;
        else if(100 * c >= 90 * occ.size()) cout << "hardcore" << endl;
        else if(100 * c >= 80 * occ.size()) cout << "average" << endl;
        else if(100 * c >= 50 * occ.size()) cout << "random" << endl;
        else cout << "noob" << endl;
    }

    return 0;
}