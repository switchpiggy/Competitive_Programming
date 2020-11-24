#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll pos, neg, z, n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] == 0) z++;
        else if(a[i] > 0) pos++;
        else neg++;
    }

    if(pos == n) {
        for(ll i = 1; i < n; ++i) cout << "1 " << i + 1 << ' ' << 1 << '\n';
        return 0;
    }

    if(neg%2 == 0) {
        ll op = 0;
        ll pz = -1, pn = -1;
        for(ll i = 0; i < n; ++i) {
            if(a[i] == 0) {
                if(pz == -1) pz = i;
                else {
                    cout << "1 " << i + 1 << ' ' << pz + 1 << '\n';
                    op++;
                }
            }
        }

        for(ll i = 0; i < n; ++i) {
            if(a[i] != 0) {
                if(pn == -1) pn = i;
                else {
                    op++;
                    cout << "1 " << i + 1 << ' ' << pn + 1 << '\n';
                }
            }
        }

        if(pz != -1 && op < n - 1) cout << "2 " << pz + 1 << '\n';
        return 0;
    } 

    ll op = 0, pz = -1, pn = -1, pp = -1;
    for(ll i = 0; i < n; ++i) {
        if(a[i] == 0) {
            if(pz == -1) pz = i;
            else {
                cout << "1 " << i + 1 << ' ' << pz + 1 << '\n';
                op++;
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(a[i] < 0 && (pn == -1 || a[pn] < a[i])) {
            pn = i;
        }
    }
    
    for(ll i = 0; i < n; ++i) {
        if(a[i] != 0 && i != pn) {
            if(pp == -1) pp = i;
            else {
                op++;
                cout << "1 " << i + 1  << ' ' << pp + 1 << '\n';
            }
        }
    }

    if(op == n-1) return 0;
    if(pz != -1) {
        cout << "1 " << pz + 1 << ' ' << pn + 1 << '\n';
        op++;
    }
    if(op == n - 1) return 0;
    cout <<"2 " << pn + 1 << '\n';

    return 0;
}