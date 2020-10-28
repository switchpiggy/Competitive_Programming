#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cout << (n * (n - 1))/2 + (m * (m - 1)/2) << '\n';
    return 0;
}