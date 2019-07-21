#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){
	int l[5][5];
	int x,y;
	for(int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			cin >> l[i][j];
			if (l[i][j]==1){
				x=i+1;
				y=j+1;
			}
		}
	}
	cout << sqrt(pow((3-x),2))+sqrt(pow((3-y),2));

	return (0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
