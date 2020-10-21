#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll res = 0;

    cout << n - n/2 - n/3 + n/6 - n/7 + n/21 + n/14 - n/5 + n/10 + n/15 + n/35 - n/30 - n/42 - n/70 - n/105 + n/210 << '\n';

    return 0;
}