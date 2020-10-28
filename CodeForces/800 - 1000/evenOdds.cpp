#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(k <= (n + 1)/2) cout << 2 * k - 1 << '\n';
    else cout << 2 * (k - (n + 1)/2) << '\n';

    return 0;
}