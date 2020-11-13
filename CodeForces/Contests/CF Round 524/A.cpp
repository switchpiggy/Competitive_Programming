#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    cout << (k + 2 * n - 1)/k + (k + 5 * n - 1)/k + (k + 8 * n - 1)/k << '\n';

    return 0;
}