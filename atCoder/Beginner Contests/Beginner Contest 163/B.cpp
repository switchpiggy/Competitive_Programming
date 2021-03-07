#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a;

int main() {
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a;
        n -= a;
    }

    if(n < 0) n = -1;
    cout << n << endl;

    return 0;
}