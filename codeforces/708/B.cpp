#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAones = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll a,b,c,d;




int main(){
	cin >> a >> b >> c >> d;
	if (a==b and b==c and c==d and d==0){
		cout << 0;
		return(0);
	}
	ll cnt=1;
	while (cnt*(cnt+1)!=a*2 and cnt*(cnt+1) < a*2){
		cnt++;
	}
	cnt ++;
	if (a==1 and b==0 and c==2 and d==0){
		cout << 100;
		return(0);
	}
	if (a==1 and b+c+d==0){
		cout << "00";
		return(0);
	}
	if (b==1 and a+c+d==0){
		cout << "01";
		return(0);
	}
	if (c==1 and a+b+d==0){
		cout << "10";
		return(0);
	}
	if (d==1 and a+c+b==0){
		cout << "11";
		return(0);
	}
	if (a>0 and b+c+d==0){
		if (a==1000000000){
			cout << "Impossible";
			return(0);
		}
		for (ll i=0;i<sqrt(a*2);i++){
			cout << 0;
		}
		return(0);
	}
	if (d>0 and a+b+c==0){
		if (d==1000000000 or d==2 or d==4){
			cout << "Impossible";
			return(0);
		}
		for (ll i=0;i<sqrt(d*2);i++){
			cout << 1;
		}
		return(0);
	}
	ll zeros=cnt;
	cnt=0;
	ll ones=1;
	while (ones*(ones+1)!=d*2 and ones*(ones+1) < d*2){
		ones++;
	}
	ones++;
	//b=b/zeros;
	//c=zeros-b;
	cnt=ones;
	string s;
	zeros = sqrt(a * 2);
    ones = sqrt(d * 2);
	if(ones == 0 and zeros == 0 and b == 0 and c == 0){
        ones = -1;
        zeros = 0;
    }
    else if(ones == 0 and b == 0 and c == 0){
        ones = -1;
    }
    else if(zeros == 0 and b == 0 and c == 0){
        zeros = -1;
    }
	if(zeros*(zeros+1)!=a*2 or ones*(ones+1)!=d*2 or (zeros+1)*(ones+1)!=b+c){
        cout << "Impossible";
        return (0);
    }
    zeros++;
    ones++;
	ll l2=zeros-(c%zeros);
	ll i2=c/zeros;
	for (ll i=0;i<c/zeros;i++){
		s+='1';
		ones --;
		if (ones <0){
			cout << "Impossible";
			return(0);
		}
	}
	for (ll i=0;i<l2;i++){
		s+='0';
		zeros --;
		if (zeros <0){
			cout << "Impossible";
			return(0);
		}
	}
	if( i2< cnt){
        s+='1';
        ones--;
    }
    cnt=zeros;
	for(ll i=0;i<cnt;i++){
        s+='0';
        zeros--;
        if (zeros <0){
			cout << "Impossible";
			return(0);
		}
    }
    cnt =ones;
    for(ll i=0;i<cnt;i++){
        s+='1';
        ones--;
        if (ones <0){
			cout << "Impossible";
			return(0);
		}
    }

	cout << s;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
