#include<iostream>
using namespace std; 
int main(){
    string s,a,b;
    cin >> s >> a;
    b=s;
    for (int i =0;i<s.size();i++){ 		
        if (s[i] == a[i] and s[i] == '1'){
            b[i]='0';
        }
        if (s[i] == a[i] and s[i] == '0'){
            b[i]='0';
        }
        if (s[i] != a[i] and (s[i] == '1' or a[i] == '1')){
            b[i]='1';
        }
    } 	
    cout << b;
    return(0); 
}