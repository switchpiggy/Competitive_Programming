/*  
ID: alanxia1  
PROB: barn1  
LANG: C++  
*/   
#include <bits/stdc++.h>   
using namespace std;   
   
int a[201];   
bool fg[201];   
int main()   
{   
    freopen("barn1.in","r",stdin);   
    freopen("barn1.out","w",stdout);   
    int m,s,c,i,total,j,k,length,temp;   
    cin>>m>>s>>c;   
    for (i=1; i<=c; i++) cin>>a[i];   
    for (i=1; i<=c; i++)   
        for (j=i+1; j<=c; j++)   
            if (a[i]>a[j])   
            { temp=a[i]; a[i]=a[j]; a[j]=temp; }   
    memset(fg,true,sizeof(fg));   
    total=c;   
    for (i=1; i<=c-m; i++)   
    {   
        length=1000000;   
        for (j=1; j<=c-1; j++)   
            if (fg[j] && length>a[j+1]-a[j])   
            { length=a[j+1]-a[j]; k=j; }   
        total+=length-1;   
        fg[k]=false;   
    }   
    cout<<total<<endl;   
}   