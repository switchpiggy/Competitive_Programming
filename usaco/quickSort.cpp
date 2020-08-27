#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1000007];

ll part(ll l, ll r) {
    ll pivot = a[r];
    ll j = l;

    for(ll i = l; i < r; ++i) {
        if(a[i] <= pivot) {
            swap(a[i], a[j]);
            j++;
        }
    }

    swap(a[j], a[r]);

    return j;
}

void qSort(ll l, ll r) {
    if(l >= r) return;

    ll pivot = part(l, r);

    qSort(l, pivot - 1);
    qSort(pivot + 1, r);
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    qSort(0, n - 1);
    for(ll i = 0; i < n; ++i) printf("%lld ", a[i]);

    return 0;
}