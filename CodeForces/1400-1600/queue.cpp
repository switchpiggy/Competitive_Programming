#include <bits/stdc++.h>

using namespace std;

int main() {

    long long arr[100005], n;

    scanf("%lld", &n);

    for(int i = 0; i < n; ++i) scanf("%lld", &arr[i]);

    sort(arr, arr + n);

    long long int s = 0, count = 0;

    for(int i = 0; i < n; ++i) {

        if(arr[i] >= s) {
        	
        	 count++;

        s += arr[i];
        	
        }

    }

    printf("%lld", count);


}