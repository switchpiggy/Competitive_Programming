#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int adj[2005];



int dfs(int x) {

    int total = 0;

    stack<int> s;
    
    s.push(x);

    while(!s.empty()) {

        int t = s.top();

        s.pop();

        if(t != -1) {
        	
        	s.push(adj[t]); 
        
        	total++;
        	
        }

    }

    return total;

}

int main() {

    int n, length = INT_MIN;

    s(n);

    for(int i = 1; i <= n; ++i) s(adj[i]);

    for(int i = 1; i <= n; ++i) length = max(length, dfs(i));

    printf("%d", length);

    return 0;


}