#include <bits/stdc++.h>

using namespace std;

int main() {

    int arr[3], t;
    
    scanf("%d", &t);
    
    while(t--) {

    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

    sort(arr, arr + 3, greater<int>());

    if(arr[0] <= arr[1] + arr[2] + 1) printf("YES\n");

    else printf("NO\n");
    
    }

    return 0;



    

}