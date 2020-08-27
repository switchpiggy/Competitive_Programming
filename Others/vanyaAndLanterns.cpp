#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int n, l, a[1005];
 
    scanf("%d %d", &n, &l);
 
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
 
    sort(a, a + n);
 
    int ans = 2 * max(a[0], l - a[n - 1]);
 
    for(int i = 0; i < n - 1; ++i) {
 
        ans = max(ans, a[i + 1] - a[i]);
 
    }
 
    printf("%.10f\n", ans/2.);
 
}