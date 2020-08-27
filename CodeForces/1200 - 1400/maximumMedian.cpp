#include <bits/stdc++.h>

using namespace std;

long long int n, k;

long long int a[200005];

bool check(int x) {

    long long int c = 0;

    for(long long int i = n/2; i < n; ++i) {

        if(x - a[i] > 0) c += x - a[i];

        if(c > k) return false;

    }

    if(c > k) return false;

    else return true;

}

int main() {

   

    scanf("%lld %lld", &n, &k);

    for(long long i = 0; i < n; ++i) scanf("%lld", &a[i]);

    long long int low = 0;

    long long int high = 2000000000;
    
    sort(a, a + n);

    while(low != high) {

        long long int mid = (low + high + 1)/2;

        if(check(mid)) low = mid;

        else high = mid - 1;

    }

    cout << low;

}