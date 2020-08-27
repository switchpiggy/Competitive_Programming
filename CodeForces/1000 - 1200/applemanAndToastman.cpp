#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, arr[300005];

void solve() {

    ll total = 0;

    for(ll i = 1; i < n; ++i) total += arr[i] * (i + 1);

    total += n * arr[n];

    printf("%lld", total);

    return;

}

int main() {

    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) scanf("%lld", &arr[i]);
    sort(arr, arr + n + 1);

    solve();

    return 0;

}