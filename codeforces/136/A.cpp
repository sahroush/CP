#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define pf1(a) printf("%lld\n", a)
#define pf2(a,b) printf("%lld %lld\n",a,b)
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){
	int n,l[100];
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> l[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (l[j]==i+1){
				cout <<j+1<< " ";
			}
		}
		
	}
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
