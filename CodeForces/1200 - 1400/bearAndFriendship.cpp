#include<bits\stdc++.h>
int64_t n,m,a,b,s,u[150179],p[150179];
int L(int x){return u[x]==x?x:u[x]=L(u[x]);}
int main(){
std::cin>>n>>m;for(;a<n;a++)u[a]=a,p[a]=1;
for(s=m;m--;)
std::cin>>a>>b,a=L(a-1),b=L(b-1),
a-b?u[a]=b,p[b]+=p[a]:0;
for(;n--;)u[n]==n?s-=p[n]*(p[n]-1)/2:0;
std::cout<<(s?"NO":"YES");
}