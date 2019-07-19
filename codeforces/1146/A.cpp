#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;





int main(){
	string s;
	cin >> s;
	int a=0,o=0;
	for (int i=0;i<s.size();i++){
		if(s[i]=='a'){
			a++;
		}
		else{
			o++;
		}
	}
	if (a<=o){
		cout << a+a-1;
	}
	else{
		cout << a+o;
	}
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
