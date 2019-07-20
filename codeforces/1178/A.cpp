#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 
 
 
 
int main(){
	int n;
	cin >> n;
	int cnt=0;
	int a[n];
	bool flag=0;
	for (int i=0;i<n;i++){
		cin >> a[i];
		cnt +=a[i];
		if (a[i]*2==a[0]){
			flag=1;
		}
	}

	int cmp=cnt/2+1-a[0];
	int cntp=0;
	int in=1;
	int num[100];
	int f=0;
	while (cmp>0){
		if (in==n){
			break;
		}
		if (a[in]*2<=a[0]){
			cmp-=a[in];
			cntp++;
			num[f]=in;
			f++;
		}
		in++;
	}
	if (cmp>0 ){
		cout << 0;
		return(0);
	}
	cout << cntp+1<< endl;
	cout << 1<<" ";
	for (int i=0;i<f;i++){
		cout << num[i] +1<< " ";
	}
	
	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
