#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    bool ok = 0;
    //ll cnt = 0;
    for(ll i = 1; i * i <= m; ++i) {
        if(m%i == 0 && i >= k && i < m) {
            ok = 1;
            break;
            //cnt++;
        }

        if(m%i == 0 && m/i >= k && m/i < m) {
            ok = 1;
            break;
            //cnt++;
        }
    }

    if(n%2 == 0 || (n%2 == 1 && !ok)) cout << "Marsel\n";
    else cout << "Timur\n";
    return 0;
}