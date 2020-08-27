#include<bits/stdc++.h>
using namespace std;
int main(){
char a,b=0,c=1,d=2;
while(cin>>a){
if(!(a==b&&b==c)&&!(a==b&&c==d)){
cout<<a;
d=c;
c=b;
b=a;
}
}
}