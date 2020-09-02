#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    cin >> n >> m;
    cout << min(n, m) + 1 << endl;
    for(ll i = min(n, m); i >= 0; --i) cout << i << ' ' << min(n, m) - i << endl;
    return 0;
}