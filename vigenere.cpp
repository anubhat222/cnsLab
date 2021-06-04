#include<bits/stdc++.h>
using namespace std;

int main(){
    char pt[10000];
    char k[100000];
    char ct[10000];
    cout<<"Enter the plain text:";
    cin>>pt;
    cout<<"Enter the key";
    cin>>k;
    int m=strlen(pt);
    int n=strlen(k);
    char kg[m];
    int i=0,j=n;
    for(int i=0;i<n;i++){
        kg[i]=(k[i]);
    }
    while(j<m){
        kg[j]=(k[i]);
        i=(i+1)%n;
        j++;
     }
     cout<<"The complete key gen:"<<kg;
     for(int i=0;i<m;i++){
         char j;
         ct[i]=(char)(((int)pt[i]-'a'+(int)kg[i]-'a')%26)+'a';
     }
     cout<<"The encrypted text is:"<<ct;
     
     
}
