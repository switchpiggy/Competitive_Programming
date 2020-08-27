#include <iostream>
#include <cmath>
using namespace std;
int r,x,y,x1,y1;
int main(){
	cin>>r>>x>>y>>x1>>y1;
	cout<<ceil((sqrt(pow(x1-x,2)+pow(y1-y,2)))/(2*r))<<endl;
} 	