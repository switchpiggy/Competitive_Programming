#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u, v;
vector<ll> adj[100007];
bool visited[100007];

void preorder(ll cur, ll prev) {
    if(adj[cur].size() == 1 && adj[cur][0] == prev) {
        printf("%lld ",cur);
        return;
    }
    sort(adj[cur].begin(), adj[cur].end());

    printf("%lld ", cur);
    for(ll i = 0; i < adj[cur].size(); ++i) {
        if(adj[cur][i] == prev) continue;
        preorder(adj[cur][i], cur);
    }

    return;
}

void postorder(ll cur, ll prev) {
    if(adj[cur].size() == 1 && adj[cur][0] == prev) {
        printf("%lld ", cur);
        return;
    }
    sort(adj[cur].begin(), adj[cur].end());
    
    for(ll i = 0; i < adj[cur].size(); ++i) {
        if(adj[cur][i] == prev) continue;
        postorder(adj[cur][i], cur);
    }

    printf("%lld ", cur);

    return;
}

void inorder(ll cur, ll prev) {
    if(adj[cur].size() == 1 && adj[cur][0] == prev) {
        printf("%lld ", cur);
        return;
    } 
    sort(adj[cur].begin(), adj[cur].end());

    if(adj[cur].size() == 1) {
        for(ll i = 0; i < adj[cur].size(); ++i) {
            if(adj[cur][i] == prev) continue;
            else inorder(adj[cur][i], cur);
        }
        printf("%lld ", cur);
        
    } else {
        for(ll i = 0; i < adj[cur].size(); ++i) {
            if(adj[cur][i] == prev) continue;
            else {
                inorder(adj[cur][i], cur);
                break;
            }
        }
        printf("%lld ", cur);
        for(ll i = adj[cur].size() - 1; i >= 0; --i) {
            if(adj[cur][i] == prev) continue;
            else {
                inorder(adj[cur][i], cur);
                break;
            }
        }
    }

    return;
}

void levelOrder(ll cur) {
    queue<ll> q;
    q.push(cur);

    while(!q.empty()) {
        ll f = q.front();
        q.pop();

        printf("%lld ", f);
        visited[f] = 1;

        for(ll i = 0; i < adj[f].size(); ++i) {
            if(!visited[adj[f][i]]) q.push(adj[f][i]);
        }
    }
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n - 1; ++i) {
        scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preorder(1, -1);
    printf("\n");
    inorder(1, -1);
    printf("\n");
    postorder(1, -1);
    printf("\n");
    levelOrder(1);
    printf("\n");

    return 0;
}