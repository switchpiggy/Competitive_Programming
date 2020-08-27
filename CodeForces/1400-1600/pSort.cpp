#include <bits/stdc++.h>
using namespace std;
int n,x[105],d,par[105];
int find (int a){
    if (a==par[a]) return a;
    return par[a]=find(par[a]);
}
void unon (int a,int b){
    par[find(a)]=find(b);
}
int main(){
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>x[i];
        par[i]=i;
    }
    for (int i=1; i<=n; i++){
        cin>>d;
        if (i-d>0) unon(i,i-d);
        if (i+d<=n) unon(i,i+d);
    }
    for (int i=1; i<=n; i++)
        if (find(i)!=find(x[i])) { cout<<"NO"<<endl; return 0; }
    cout<<"YES"<<endl;
    return 0;
}