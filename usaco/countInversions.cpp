#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, cnt = 0, a[100007];

const ll MOD = 1e9 + 7;

void merge(ll l, ll r) {
    vector<ll> temp;

    ll m = (l + r)/2;
    ll i = l, j = m + 1;

    while(i <= m && j <= r) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            cnt += m - i + 1;
            cnt %= MOD;
            temp.push_back(a[j]);
            j++;
        }
    }

    while(i <= m) {
        temp.push_back(a[i]);
        i++;
    }

    while(j <= r) {
        temp.push_back(a[j]);
        j++;
    }

    copy(temp.begin(), temp.end(), a + l);
}

void mergeSort(ll l, ll r) {
	if(l >= r) return;
    ll m = (l + r)/2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    merge(l, r);
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    
    mergeSort(0, n - 1);

    printf("%lld\n", cnt);

    return 0;
}