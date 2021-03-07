#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;
    if(n >= 10) cout << r << '\n';
    else cout << r + (100 * (10 - n)) << '\n';
}