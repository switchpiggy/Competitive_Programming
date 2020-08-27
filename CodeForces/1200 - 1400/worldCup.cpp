#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, arr[100005], mins = INT_MAX, ans = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {

        scanf("%d", &arr[i]);

        int a = arr[i] - i + n;

        if(a/n < mins) {
        	
        	mins = a/n;
        	
        	ans = i;
        	
        }

    }
    

    printf("%d", ans);



}   