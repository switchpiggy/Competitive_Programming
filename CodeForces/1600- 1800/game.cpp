#include <bits/stdc++.h>
 
using namespace std;
#define mod 1000000009
typedef long long ll;
typedef long double ld;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = INT_MAX;
    int dist[3][3] = {{0, 1, 2}, {2, 0, 1}, {1, 2, 0}};
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto &x: vec)
    {
        cin >> x;
        x--;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        while(s--)
        {
            int a;
            cin >> a;
            a--;
            g[a].push_back(i);
        }
    }
    for(int j = 0; j < 3; j++)
    {
        int current = j;
        int currentAns = 0;
        int need[205];
        bool Mark[205];
        memset(need, 0, sizeof(need));
        memset(Mark, 0, sizeof(Mark));
        for(auto &x: g)
        {
            for(auto &y: x)
            {
                need[y]++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            queue<int> que;
            for(int i = 0; i < n; i++)
            {
                if(!Mark[i] && !need[i])
                    que.push(i);
            }
            int selected = -1;
            int Min = INT_MAX;
            while(que.size())
            {
                int a = que.front();
                que.pop();
                int need = dist[current][vec[a]];
                if(need <= Min)
                {
                    Min = need;
                    selected = a;
                }
            }
            Mark[selected] = true;
            currentAns += Min + 1;
            current = vec[selected];
            for(auto &x: g[selected])
            {
                need[x]--;
            }
        }
        ans = min(ans, currentAns);
    }
    cout << ans;
    return 0;
}