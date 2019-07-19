#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;




int main(){
	string s;
	cin >> s;
	int flag=0, cnt=0;
	for (int i=s.size()-1;i>=0;i--){
		if (s[i]==')'){
			flag++;
		}
		else if (flag!=0){
			cnt++;
			flag--;
		}
	}
	cout << cnt*2;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
