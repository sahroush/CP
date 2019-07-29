#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int s[100000];
int y[100000],no[100000];
int cnty=0,cntn=0;
char v[100000];
int cntv=0;

int main(){
	ll n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
	    cin >> s[i];
	    if(s[i]<0){
	    	no[(-s[i])-1]++;
	        cntn++;
	    }
	    else{
	        y[s[i]-1]++;
	        cnty++;
	    }
	}
	for(int i=0;i<n;i++){
	    if(y[i]+cntn-no[i]==m){
	        v[i]=1;
	        cntv++;
	    }
	}
	    
    for(int i=0;i<n;i++){
	    int j;
	    if(s[i]<0){
	        j=-s[i]-1;
	        if(v[j]==0){
	            cout << "Truth" << endl;
			}
	        else if(cntv==1){
	            cout << "Lie" << endl;
			}
	    	else{
	            cout << "Not defined" << endl;
			}
	    }
	    else{
	        j=s[i]-1;
	        if((v[j]==1)&&(cntv==1)){
	            cout << "Truth" << endl;
			}
	        else if(v[j]==1){
	            cout << "Not defined" << endl;
			}
	        else {
	            cout << "Lie" << endl;
			}
	    }
	}
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
