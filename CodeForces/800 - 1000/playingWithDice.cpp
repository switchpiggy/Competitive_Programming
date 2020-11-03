#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, w, d, l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    for(ll i = 1; i <= 6; ++i) {
        if(abs(a - i) < abs(b - i)) w++;
        else if(abs(a - i) == abs(b - i)) d++;
        else l++;
    }

    cout << w << ' ' << d << ' ' << l << '\n';
    return 0;
}