#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int n, a[200005], m;

    long long int ans = 1;

    scanf("%lld %lld", &n, &m);

    if(n > m) {

        printf("0");

        return 0;

    }

    for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);

    for(int i = 0; i < n; ++i) {

        for(int j = i + 1; j < n; ++j) {

            ans = (abs(a[i] - a[j]))%m * ans%m;

        }

    }

    printf("%lld", ans%m);

}