#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
queue<ll> a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'D') a.push(i);
        else b.push(i);
    }

    while(!a.empty() && !b.empty()) {
        ll t1 = a.front(), t2 = b.front();
        a.pop();
        b.pop();
        
        if(t1 > t2) b.push(t2 + n);
        else a.push(t1 + n);
    }

    if(a.empty()) cout << 'R' << '\n';
    else cout << 'D' << '\n';

    return 0;
}