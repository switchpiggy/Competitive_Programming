# include <bits/stdc++.h>
using namespace std;
# define fi cin
# define fo cout
char c[1000005];
int main(void)
{
    fi>>(c+1);
    int mn = 0,mx = 0,cnt = 0,n = strlen(c+1);
    for (int i = 1;i <= n;++i)
    {
        if (c[i] == '+') ++cnt;else --cnt;
        mx = max(mx,cnt);
        mn = min(mn,cnt);
    }
    return fo << mx - mn << '\n',0;
}