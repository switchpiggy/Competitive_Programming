#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        int x = 0, y = 0;

        int n;

        scanf("%d", &n);

        pair<int, int> cur = make_pair(0, 0);

        map<pair<int, int>, int> visited;

        visited[cur] = 0;

        int l = -1, r = n;

        for(int i = 0; i < n; ++i) {

            char c;

            cin >> c;

            if(c == 'D') cur.second--;

            else if(c == 'U') cur.second++;

            else if(c == 'R') cur.first++;

            else if(c == 'L') cur.first--;

            if(visited.count(cur)) {

                if(i - visited[cur] + 1 < r - l + 1) {

                    r = i;

                    l = visited[cur];

                }

            }

            visited[cur] = i + 1;

        }
        
        if(l == -1 || r == n) printf("-1\n");

        else printf("%d %d\n", l + 1, r + 1);

    }
}