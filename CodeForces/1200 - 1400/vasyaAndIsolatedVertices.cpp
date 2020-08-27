#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int n, m;

    scanf("%lld %lld", &n, &m);

    long long rem = m;

    long long cur = 1;

    while(rem > 0) {

        long long diff = min(rem, cur);
        
        rem -= diff;

        cur++;

    }
	
	long long int res = max((long long)0, n - cur);
	
	if(cur == 1) res = n;

    printf("%lld %lld", max((long long)0, n - 2 * m), res);

}