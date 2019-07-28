#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAones = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll xp,yp,xv,yv;
ll cntp=-1,cntv=0;



int main(){
	cin >> xp >> yp >> xv >> yv;
	ll x1=xp,x2=xv,y1=yp,y2=yv;
	int cnt=0;
	while (cnt <1000000-2000){
		cnt++;
		if (xp>0 and (yp!=yv and xp-1!=xv)){
			xp--;
		}
		else if (yp>0 and (xp!=xv and yp-1!=yv)){
			yp--;
		}
		if (yp==xp and xp==0){
			cout << "Polycarp";
			return(0);
		}
		//cout /*<< xp << '\t' << yp  << endl*/ << xv << '\t' << yv << endl;
		if (yv>0 and xv>0 and (yv-1!=yp and xv-1!=xp)){
			yv--;
			xv--;
		}
		else if (yv>0 and (xp!=xv and yv-1!=yp)){
			yv--;
		}
		else if (xv>0 and (yp!=yv and xv-1!=xp)){
			xv--;
		}
		if (yv==0 and xv==0){
			cout << "Vasiliy";
			return(0);
		}	
	}
	//cout << "hi";
	xp=x1;
	xv=x2;
	yp=y1;
	yv=y2;
	cntp+=xp+yp;
	cntv+=min(xv,yv);
	xv-=cntv;
	yv-=cntv;
	cntv+=xv+yv;
	//cout << cntp << endl << cntv;
	if (cntp>=cntv){
		cout <<  "Vasiliy";
	}
	else{
		cout <<  "Polycarp";
	}
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
