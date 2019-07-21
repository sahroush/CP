#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define pf1(a) printf("%lld\n", a)
#define pf2(a,b) printf("%lld %lld\n",a,b)
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){


	map <ll, ll> mp;
	map <ll, ll>::iterator it;
    // seive();

    ll tc, num, t = 1, pownum;

    //freopen("/opt/Coding/clion code/input.txt", "r", stdin);
    //freopen("/opt/Coding/clion code/output.txt", "w", stdout);

    sc1(num);

    ll arr[num];

    for(ll i = 0; i < num; i++)
        sc1(arr[i]);

    sort(arr, arr + num);

    for(ll i = 0; i < num - 1; i++){
        for(ll j = i + 1; j < num; j++){
            mp[arr[i] + arr[j]]++;
        }
    }

    ll ans = 0;
    for(it = mp.begin(); it != mp.end(); it++){
        ans = max(ans, it->second);
    }

    pf1(ans);

    return (0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
