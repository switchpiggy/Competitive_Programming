#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    
    scanf("%d %d", &n, &m);

    vector<int> a(n);

    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);

    sort(a.begin(), a.end());

    while(m--) {

        int cur;

        scanf("%d", &cur);

        int idx = upper_bound(a.begin(), a.end(), cur) - a.begin();

        printf("%d ", idx);

    }




}