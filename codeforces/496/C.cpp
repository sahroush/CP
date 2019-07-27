#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int del(int n , int m ,string s[],int indx){
	bool f;
	for (int i=indx;i<=indx;i++){
		f=0;
		for (int j=0;j<n-1;j++){
			if (s[j][i] > s[j+1][i]){
				return(i);
			}
		}
		if (f==0){
			return(-1);
		}
	}
}
bool check(int n,string s[]){
	for (int i=0;i<n-1;i++){
		if (s[i]>s[i+1]){
			return(0);
		}
	}
	return(1);
}


int n,m,cnt=0;
string s[100];

int main(){
	cin >> n >> m;
	if (n==1){
		cout << 0;
		return(0);
	}
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	int l[100];
	fill(l,l+100,0);
	int r;
	for(int i=0;i<n;i++){
		r=del(n,m,s,i);
		if (r!=-1){
			l[i]=1;
		}
	}
	int j;
    for(int i=0;i<n-1;i++){
        if(s[i]>s[i+1]){
            for(j=0;j<m;j++){
                if(s[i][j]>s[i+1][j]){
                	break;
				}
            }
            for(int k=0;k<n;k++){
                s[k][j]='0';
            }
            cnt++;
            i=-1;
        }
    }
    cout<<cnt;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
