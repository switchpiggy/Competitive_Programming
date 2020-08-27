#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, s;

int main() {
    cin >> n >> k >> s;
    for(ll i = 0; i < k; ++i) cout << s << ' ';
    if(s == 1000000000) s = 0;
    for(ll i = k; i < n; ++i) cout << s + 1 << ' ';

    return 0; 
}
