#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    ll a = 0;
    while(n) {
        n /= k;
        a++;
    }

    cout << a << '\n';
    return 0;
}