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

int n , k , c[maxn] , p[maxn] , a[maxn] , indx1[maxn] , indx2[maxn];

bool cmp1(const int i,const int j){
    return p[i] > p[j];
}
bool cmp2(const int i,const int j){
    return a[i] < a[j];
}

int main(){
    migmig
    cin >> n;
    for (int i = 1  ; i <= n ; i ++){
        cin >> c[i] >> p[i];
        indx1[i] = i;
    }
    cin >> k;
    for (int i =1  ; i <= k ; i  ++){
         cin >> a[i];
         indx2[i] = i ;
    }
    sort(indx1+1 , indx1 +1 + n, cmp1);
    sort(indx2+1 , indx2 +1 + k, cmp2);
    ll sum = 0 , cnt = 0 ;
    int vis[maxn];
    int l[maxn];
    fill(vis , vis+maxn , 0);
    fill(l , l+maxn , 0);
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(c[indx1[i]] <= a[indx2[j]] && !vis[indx2[j]]){
                cnt++;
                sum += p[indx1[i]];
                l[indx1[i]] = indx2[j];
                vis[indx2[j]] = 1;

                break;
            }
        }
    }
    cout << cnt << '\t' << sum << endl;
    for(int i = 1; i <= n; i++){
        if(l[i]){
            cout << i << '\t' << l[i] << endl;
        }
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
