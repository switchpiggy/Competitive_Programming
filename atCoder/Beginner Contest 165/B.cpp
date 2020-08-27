#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x;

int main() {
    cin >> x;
    ll p = 100, res = 0;
    while(p < x) {
        p += p/100;
        res++;
    }

    cout << res << endl;
    return 0;
}