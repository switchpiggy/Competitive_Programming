#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int maxs, sum, temp, n;

    sum = 0;

    maxs = -1;

    scanf("%lld", &n);

    for(long long int i = 0 ; i < n; ++i) {

        scanf("%lld", &temp);

        maxs = max(maxs, temp);

        sum += temp;

    }

    if(sum%2 == 0 && maxs <= sum - maxs) printf("YES");

    else printf("NO");

}