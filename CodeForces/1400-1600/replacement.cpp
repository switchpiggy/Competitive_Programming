#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a[100005];
    
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

    sort(a, a + n);

    if(a[n - 1] == 1) a[n - 1] = 2;

    else a[n - 1] = 1;

    sort(a, a + n);

    for(int i = 0; i < n; ++i) printf("%d ", a[i]);
}