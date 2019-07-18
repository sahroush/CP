#include<iostream>
using namespace std; 
int main(){
    string s;
    cin >> s;
    int a=0; 	 	
    for (int i =0;i<s.size();i++){ 		
        if (s[i] >= 'A' and s[i] <= 'Z'){
            a++;
        }
        else{
            a--;
        }	
    } 		
    for (int i =0;i<s.size();i++){ 		
        if (s[i] >= 'A' and s[i] <= 'Z' and a<=0){
            s[i]=s[i]+('a'-'A');
        }
        else if (s[i]>='a' and s[i] <= 'z' and a>0){
            s[i]=s[i]-('a'-'A');
        }	
    } 	
    cout << s;
    return(0); 
}