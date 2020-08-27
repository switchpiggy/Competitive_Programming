#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dist;
string s;
map<string, ll> occ;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> s;
        occ[s]++;
        if(occ[s] == 1) dist++;
    }

    cout << dist << endl;
    return 0;
}