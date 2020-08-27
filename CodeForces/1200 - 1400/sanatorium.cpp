#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int arr[3];

    scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);

    sort(arr, arr + 3);

    long long int n = max((long long)0, arr[2] - 1 - arr[1]) + max((long long)0, arr[2] - 1 - arr[0]);

    if(n < 0) n = 0;

    printf("%lld", n);

    

}