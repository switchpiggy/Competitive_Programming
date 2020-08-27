#include <stdio.h>
#include <math.h>
#include<iostream>
#include<string.h>
using namespace std;
 
int finds(int l,int r);
int Search(int low , int high );
int ask(int v);
int k,n;
int mid;
long long sum;
long long kx;
int main()
{
    scanf("%d%d",&n,&k);
    int ans=finds(1,n);
    printf("%d\n",ans);
}
 
int ask(int v)
{
    sum=v;
    kx=k;
    while(v/kx)
    {
        sum+=v/kx;
        kx*=k;
    }
    if(sum<n)
        return 0;
    else if(sum>n)
        return 1;
    else
        return 2;
}
 
int Search(int low , int high )
{
	int middle = (low + high)/2;
    int ans=ask(mid);
    if(high==low)
        return middle;
    cout<<low<<"  "<<high<<endl;
    cout<<middle<<endl;
	if(ans==2)
		return middle;
	if(ans==1)
		return Search(  low , middle - 1 );
	if(ans==0)
		return Search(  middle + 1 , high );
 
};
 
int finds(int l,int r)
{
    mid=(l+r)>>1;
    if(mid==l)
        return r;
    int ans=ask(mid);
    //cout<<l<<"  "<<r<<endl;
    //cout<<mid<<endl;
    if(ans==2)
        return mid;
    if(ans==0)
        finds(mid,r);
    else
        finds(l,mid);
}