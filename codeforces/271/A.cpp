#include<iostream>
using namespace std;
int main(){
	int n,b,a,d,c,done=1;
	cin >> n;
	while (done){
		n+=1;
		a=n/1000;
		c=n/10-n/100*10;
		b=n/100-n/1000*10;
		d=n/1-n/10*10;
		if (a!=b and a!=c and a!=d and b!=c and b!=d and c!=d){
			cout << a << b << c << d;
			done =0;
		}
	}
	return(0);
}