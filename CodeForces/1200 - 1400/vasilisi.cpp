#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

int main(){
int r1,r2,c1,c2,d1,d2,i,j,k,l,x1,x2,x3,x4;
cin>>r1>>r2;
cin>>c1>>c2;
cin>>d1>>d2;
for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
        for(k=1;k<=9;k++){
            for(l=1;l<=9;l++){
                if((i+j==r1)&&(k+l==r2)&&(i+k==c1)&&(j+l==c2)&&(i+l==d1)&&(j+k==d2)&&(i!=j)&&(i!=k)&&(i!=l)&&(j!=k)&&(j!=l)&&(k!=l)){
                    cout<<i<<" "<<j<<endl;
                    cout<<k<<" "<<l<<endl;
                    exit(0);
                }
            }
        }
    }
}
cout<<-1;
return 0;
}
