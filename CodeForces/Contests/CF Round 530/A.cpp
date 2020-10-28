#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll w, h, u, d, u1, d1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h >> u >> d >> u1 >> d1;
    for(ll i = h; i >= 0; --i) {
       w += i;
       if(d == i) w = max(0ll, w - u); 
       if(d1 == i) w = max(0ll, w - u1);
    }

    cout << w << '\n';
    return 0;
}