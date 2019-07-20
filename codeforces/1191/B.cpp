#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){
	string s[3];
	cin >> s[0]>> s[1]>> s[2];
	if(s[0]==s[1] and s[1]==s[2]){
		cout << 0;
		return(0);
	}
	sort(s,s+3);
	if(s[0][0]+3 ==s[1][0]+2 and s[1][0]+2==s[2][0]+1 and s[0][1]==s[1][1] and s[1][1]==s[2][1]){
		cout<< 0 ;
		return(0);
	}
	if(s[0]==s[1] or s[1]==s[2]){
		cout << 1;
		return(0);
	}
	if((s[0][0]+3 ==s[1][0]+2 and s[0][1]==s[1][1] or s[1][0]+2==s[2][0]+1 and s[1][1]==s[2][1] or s[0][0]+3 ==s[2][0]+2 and s[0][1]==s[2][1]   ) ){
		cout<<  1;
		return(0);
	}
	if ((s[0][0] +3 ==s[1][0]+1 and s[0][1]==s[1][1]) or (s[0][0] +3 ==s[2][0]+1 and s[0][1]==s[2][1])or (s[1][0] +3 ==s[2][0]+1 and s[1][1]==s[2][1]) ){
		cout <<1;
		return(0);
	}
	cout << 2;
	return(0);
		
	
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
