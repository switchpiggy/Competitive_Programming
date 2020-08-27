#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        long long int n, g, b;

        long long int res = 0;

        scanf("%lld %lld %lld", &n, &g, &b);

        long long int num = ceil(n/2);

        long long int nums = n - num;

        long long int low = 0;

        long long int high = 499999500000;

        while(low <= high) {

            long long int mid = (low + high)/2;

            if((mid/(g+b))*g + min(mid%(g+b), g) < num) low = mid + 1;

            else if(mid - (mid/(g+b))*g - min(mid%(g+b), g) < nums) high = mid - 1;

            else {

                res = mid;
                
                high--;

            }

        }

        printf("%lld\n", res);

    }


}