#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
queue<pair<char, ll>> q;

int main() {
    scanf("%lld", &n);
    q.push(make_pair('B', 0));

    while(q.front().second < n) {
        pair<char, ll> f = q.front();
        if(f.first == 'B') {
        	q.push(make_pair('B', f.second + 1));
            q.push(make_pair('R', f.second + 1));
            
        } else {
        	q.push(make_pair('R', f.second + 1));
            q.push(make_pair('R', f.second + 1));
            q.push(make_pair('B', f.second + 1));

        }
        
        q.pop();
    }

    while(!q.empty()) {
        printf("%c", q.front().first);
        q.pop();
    }

    printf("\n");

    return 0;
}