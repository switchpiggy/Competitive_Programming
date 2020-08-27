#include <bits/stdc++.h>
int m,k,i,j,y[100010],x[100010][3],r=1e10,a=1e10;
int main(){
    scanf("%d%d%d",&j,&m,&k);
    for(i=0;i<m;i++)scanf("%d%d%d",&x[i][0],&x[i][1],&x[i][2]);
    for(i=0;i<k;i++){
        scanf("%d",&j);
        y[j]=1;
    }
    for(i=0;i<m;i++)
        if(y[x[i][0]]^y[x[i][1]])r=std::min(r,x[i][2]);
    printf("%d",(r==a?-1:r));
}