#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int t;

    scanf("%lld", &t);

    while(t--) {
    	
    	long long int n, x, temp, maxs = -1;
    	
    	bool flag = false;

        scanf("%lld %lld", &n, &x);

        for(long long int i = 0; i < n; ++i) {

            scanf("%lld", &temp);

            if(temp == x && flag == false) {

                printf("1\n");

                flag = true;

            }

            maxs = max(temp, maxs);

        }

        if(flag) continue;

        else printf("%lld\n", max((long long)2, (x + maxs - 1)/maxs));

    }

}