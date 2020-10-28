#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    if(min(n, m)%2 == 0) cout << "Malvika\n";
    else cout << "Akshat\n";

    return 0;
}