#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.2e5 + 10;

unordered_map<int, int> M;
int a[maxn];
int n, ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        ++M[a[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        --M[a[i]];
        int flg = 0;
        for (int j = 0; j < 31; j++)
            if (M[(1 << j) - a[i]])
                flg = 1;
        if (!flg)
            ans++;
        ++M[a[i]];
    }
    printf("%d\n", ans);
    return 0;
}