#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e3+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , w[100] , t[100] , sum1[100] , sum2[100] , cnt1 = 0 , cnt2 = 0 ;
vector < int >  p1 , p2;

int main(){
    migmig
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        cin >> t[i] >> w[i];
        if (t[i] == 1){
            cnt1++;
            p1.push_back(w[i]);
        }
        else{
            cnt2++;
            p2.push_back(w[i]);
        }
    }
    sort(p1.begin() , p1.begin() + cnt1);
    sort(p2.begin() , p2.begin() + cnt2);
    reverse(p1.begin() , p1.begin() + cnt1);
    reverse(p2.begin() , p2.begin() + cnt2);
    for (int i = 0 ; i <= cnt1 ; i ++){
        if (i){
            sum1[i] = sum1[i-1] + p1[i-1];
        }
        else{
            sum1[i] = 0;
        }
    }
    for (int i = 0 ; i <= cnt2 ; i ++){
        if (i){
            sum2[i] = sum2[i-1] + p2[i-1];
        }
        else{
            sum2[i] = 0;
        }
    }
    int mn = 1e8;

    for (int i  =  0 ; i <= cnt1 ; i++){
        for (  int j=0 ; j<= cnt2 ; j++){
            int wid = i+j+j;
            if ( sum1[cnt1] - sum1[i] + sum2[cnt2] - sum2[j] <= wid){
                mn = min(mn  , wid);
            }

        }
    }
    dokme(mn);
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
