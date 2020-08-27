#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n, d[200005];

    scanf("%lld", &n);

    for(int i = 0; i < n; ++i) {

        scanf("%lld", &d[i]);

        if(i >= 1) d[i] += d[i - 1];

    }

    long long sum = d[n - 1];

    long long low = 0;

    long long high = n - 1;

    long long res = INT_MIN;

    while(low <= high) {

        if(d[low] < sum - d[high]) low++;

        else if(d[low] > sum - d[high]) high--;

        else {
        	
        	res = max(res, d[low]);
        	
        	low++;
        	
        	high--;
        	
        }

    }

    printf("%lld", max(res, (long long)0));

}