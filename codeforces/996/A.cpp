#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;






int main(){
	int n,cnt=0;
	cin >> n;
	cnt+=n/100;
	n=(n-n/100*100);

	cnt+=n/20;
	n=(n-n/20*20);

	cnt+=n/10;
	n=(n-n/10*10);
	
	cnt+=n/5;
	n=(n-n/5*5);
	
	cout << cnt+n;
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
