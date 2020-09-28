#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    if(m >= n && k >= n) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}