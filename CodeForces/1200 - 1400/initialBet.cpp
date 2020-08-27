#include <bits/stdc++.h>

using namespace std;

int main() {

    int diff, avg, sum, arr[5];

    sum = 0;
    
    for(int i = 0; i < 5; ++i) {

        scanf("%d", &arr[i]);

        sum += arr[i];

    }

    if(sum%5 != 0) {

        printf("-1");

        return 0;
    }

    avg = sum/5;

    diff = 0;

    for(int i = 0; i < 5; ++i) {

        diff += arr[i] - avg;

    }

    if(diff != 0 || avg <= 0) {

        printf("-1");

        return 0;

    } else printf("%d", avg);

}