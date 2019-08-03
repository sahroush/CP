#include <bits/stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;

#define abs(x) sqrt(x*x);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
queue <int> q;
int main(){
	int n;
	cin >> n;
	int inp;
	for (int i=0;i<n;i++){
		cin >> inp;
		if (inp %2==0){
			inp--;			
		}
		cout << inp << '\t';
	}


	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
