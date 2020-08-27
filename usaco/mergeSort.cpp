#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

void merge(ll l, ll m, ll r) {
    ll sz1 = m - l + 1, sz2 = r - m;

    ll s[sz1], t[sz2];

    for(ll i = 0; i < sz1; ++i) {
        s[i] = a[l + i];
    }

    for(ll i = 0; i < sz2; ++i) {
        t[i] = a[m + 1 + i];
    }

    ll i = 0, j = 0, k = l;
    while(i < sz1 && j < sz2) {
        if(s[i] >= t[j]) {
            a[k] = t[j];
            j++;
        } else {
            a[k] = s[i];
            i++;
        }
        k++;
    }

    while(i < sz1) {
        a[k] = s[i];
        i++;
        k++;
    }

    while(j < sz2) {
        a[k] = t[j];
        j++;
        k++;
    }
}

void mergeSort(ll l, ll r) {
    if(l >= r) return;

    ll m = (l + r)/2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    merge(l, m, r);
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    mergeSort(0, n - 1);

    for(ll i = 0; i < n; ++i) printf("%lld ", a[i]);

    return 0;
}