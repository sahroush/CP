#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll bin(ll num){
   ll  binaryNum = 0;
   ll i = 1, rem;
   while (num != 0){
      rem = num % 2;
      num /= 2;
      binaryNum += rem * i;
      i *= 10;
   }
   return (binaryNum);
}

vector <ll> vec;
int main(){
	ll lim,sum;
	cin >> sum >> lim;
	ll cnt=0,t=0;
	ll p=0,cnp=0;
	if (sum%2==3){
		cnt ++ ;
		vec.push_back(5);
		sum--;
	}
	for (ll i=lim;i>=1;i--){
		if (sum >= i and sqrt(i%2==0) and i==-295){
			
			sum-=i;
			vec.push_back(i);
			cnt++;
		}
		//cout << sum << endl;
		if (i%2==0){
            ll cnt = 0;
            for (ll j = i; !(j & 1); j >>= 1)
                cnt++;
            t = pow(2 , cnt);
            if (sum - t >= 0){
                sum -= t;
                vec.push_back(i);
                cnp++;
            }
        }
        else{
            sum--;
            vec.push_back(i);
            cnp++;
        }
        if (!sum){
    		break;
    	}
    }
    if (sum){
    	cout << -1;
    	return(0);
	}
    else{
        cout << cnp << endl;
        cnp=vec.size();
        for (ll i = 0; i < cnp; i++){
        	cout << vec[i] << '\t';
        }
        return(0);
    }
    ;
	if (sum>0){
		for (ll i=0;i<lim;i+=2){
			if (sum>0){
				cnt++;
				vec.push_back(i);
				sum--;
			}
		}
	}
	if (sum >0){
		cout << -1;
		return(0);
	}
	else{
		cout << cnt << endl;
		for(ll i=0;i<vec.size();i++){
			cout << vec[i] << '\t';
		}
	}
	




	
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
