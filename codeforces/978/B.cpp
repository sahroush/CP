#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt=0;
	int  f=0;
	for(int i=0;i<n;i++){
		if (s[i]=='x' and f<2){
			f++;
			//cout << "why";
		}
		else if (s[i]== 'x'){
			cnt++;
			//cout << "seriously??";
		}
		else {
			//cout << "WTF";
			f=0;
		}
	}
	cout << cnt;
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
