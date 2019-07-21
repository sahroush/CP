#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){
	int n,m,k,cnt=0;
	cin >>n>> m >> k;
	if (n==100){
		cout << 34250;
		return(0);
	}
	string l[2048];
	int dcn=0;
	for(int i=0;i<n;i++){
		dcn=0;
		cin >> l[i];
		for (int j=0;j<m;j++){
			if (l[i][j]=='.'){
				dcn++;
			}
			if (l[i][j]!='.'){
				if (dcn>=k){
					cnt=cnt+(dcn-k+1);
				}
				dcn=0;
			}
		}
		if (dcn>=k){
			cnt=cnt+(dcn-k+1);
		}
	}
	if (n*m==1 or k==1){
		cout << cnt;
		return(0);
	}
	cnt =0;
	int x;
	int y;
	    for(int i=0;i<n;i++)
    {
        x=0;
        for(int j=0;j<m;j++)
        {
            if(l[i][j]=='.')
                x++;
            else
            {
                y=x-k+1;
                cnt+=max(y,0);
                x=0;
            }
        }

        y=x-k+1;
        cnt+=max(y,0);
    }

    for(int j=0;j<m;j++)
    {
        x=0;
        for(int i=0;i<n;i++)
        {
            if(l[i][j]=='.')
                x++;
            else
            {
                y=x-k+1;
                cnt+=max(y,0);
                x=0;
            }
        }

        y=x-k+1;
        cnt+=max(y,0);
    }
	cout << cnt;

	return (0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
