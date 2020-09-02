#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, temp;

int main() {
    cin >> n;
    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> temp;
        sum += temp;
    }

    if(sum%n == 0) cout << n << endl;
    else cout << n - 1 << endl;
    return 0;
}