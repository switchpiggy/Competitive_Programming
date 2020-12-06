#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> n;
    if(a <= 9 && n <= 9) cout << a *  n << '\n';
    else cout << "-1\n";
    return 0;
}