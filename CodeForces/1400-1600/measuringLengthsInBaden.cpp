#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;
    ll res = n/3;
    if(n%3 == 2) res++;

    cout << res/12 << ' ' << res%12 << endl;
    return 0;
}