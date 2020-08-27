#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t, n, a[100005], b[100005];
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld", &n);
        for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        for(int i = 0; i < n; ++i) scanf("%lld", &b[i]);
        
        bool less = false, more = false, flag = false;
        for(int i = 0; i < n; ++i) {
            if(!more && b[i] > a[i]) flag = true;
            if(!less && a[i] > b[i]) flag = true;

            if(a[i] == -1) less = 1;
            if(a[i] == 1) more = 1;
        }
        if(!flag) printf("YES\n");
        else printf("NO\n");
    }
}