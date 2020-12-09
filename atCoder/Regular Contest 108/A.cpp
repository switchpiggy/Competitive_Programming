#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 1; i * i <= m; ++i) {
        if(m%i == 0 && i + m/i == n) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}