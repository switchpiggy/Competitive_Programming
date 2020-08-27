#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, temp, m;
string to, the, dir, of;

int main() {
    scanf("%lld %lld", &n, &m);
    ll l = 0, r = n + 1;
    for(ll i = 0; i < m; ++i) {
        cin >> to >> the >> dir >> of >> temp;
        if(dir == "right") {
            l = max(l, temp);
            //cout << 'l' << endl;
        } else {
            r = min(r, temp);
        }
    }

    if(l >= r || r - l == 1) printf("-1\n");
    else printf("%lld\n", r - l - 1);

    return 0;
}