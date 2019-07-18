#include<iostream>
using namespace std;
int main(){
	int a,n;
	cin >> n;
	int x,y,z;
	x=0;
	y=0;
	z=0;
	for (int i =0;i<n;i++){
		cin >> a;
		x+=a;
		cin >> a;
		y+=a;
		cin >> a;
		z+=a;
	}
	if (x==y and y==z and z==0){
		cout << "YES";
	}
	else{
	
		cout << "NO";
	}	
	return(0);
}
