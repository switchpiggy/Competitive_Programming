#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<string, ll> occ;
ll n;
string s;
pair<string, ll> maxn;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> s;
        occ[s]++;
    }
    
    for(auto itr = occ.begin(); itr != occ.end(); ++itr) {
        if(itr->second > maxn.second) {
            maxn.second = itr->second;
            maxn.first = itr->first;
        }
    }

    cout << maxn.first << ' ' << maxn.second << endl;
    
    return 0;
}