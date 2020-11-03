#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n%2 == 1) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 1; i <= n; i += 2) {
        cout << i + 1 << ' ' << i << ' ';
    }

    return 0;
}