#include <bits/stdc++.h>

using namespace std;

int main() {

    int count = 0, numCases;
    
    scanf("%d", &numCases);

    while(numCases--) {

        int arr[3];

        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

        int ones = 0;

        for(int i = 0; i < 3; ++i) if(arr[i] == 1) ones++;

        if(ones >= 2) count++;

    }

    printf("%d\n", count);

}