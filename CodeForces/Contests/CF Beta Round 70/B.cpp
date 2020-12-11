#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<string> s = {"G", "GB", "GBI", "GBIV", "RGBIV", "ROGBIV"};
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n/7; ++i) cout << "ROYGBIV";
    if(n%7) cout << s[n%7 - 1] << '\n';

    return 0;
}