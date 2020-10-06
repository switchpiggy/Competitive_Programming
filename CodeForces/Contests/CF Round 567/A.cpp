#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y, z;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> z;
    cout << x/z + y/z + (x%z + y%z)/z << ' ';

    if(x%z + y%z >= z) cout << min(min(x%z, (z - y%z)%z), min(y%z, (z - x%z)%z)) << '\n'; 
    else cout << 0 << '\n';

    return 0;
}