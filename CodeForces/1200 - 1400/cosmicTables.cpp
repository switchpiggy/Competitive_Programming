 #include<stdio.h>
#include<iostream>
using namespace std;
int a,s,d[1001][1001],f[1001],g[1001],h,j,k,l,n,m,i;
char x;
main(){
cin>>n>>m>>k;
for(i=0;i<1000;i++){
f[i]=i;
g[i]=i;}
 
for(i=0;i<n;i++){
f[i]=i;
g[i]=i;
for(a=0;a<m;a++){
scanf("%d",&d[i][a]);
}
}
 
 
for(i=0;i<k;i++){
scanf(" %c%d%d",&x,&h,&j);
if(x=='r') swap(f[j-1],f[h-1]);
if(x=='c') swap(g[j-1],g[h-1]);
if(x=='g') printf("%d\n",d[f[h-1]][g[j-1]]);
}
 
}