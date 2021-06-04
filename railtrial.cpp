#include<bits/stdc++.h>
using namespace std;
string encrypt(char pt[10000],int key){
    int ptl=strlen(pt);
    vector<vector<char>>railFence(key,vector<char>(ptl));
    for (int i=0; i < key; i++)
        for (int j = 0; j <ptl; j++)
            railFence[i][j] = '\t';
    bool flag=false;
    int r=0,c=0;
    for(int i=0;i<strlen(pt);i++){
        if(r==0||r==key-1){
            flag=!flag;
        }
        railFence[r][c++]=pt[i];
        if(flag){
            r++;
        }
        else{
            r--;
        }
    }
    string res;
    for(int i=0;i<key;i++){
        for(int j=0;j<ptl;j++){
            if(railFence[i][j]!='\t'){
                res.push_back(railFence[i][j]);
            }
        }
    }
    return res;
}
string decrypt(string ct,int key){
    int ctl=ct.length();
    vector<vector<char>>rail(key,vector<char>(ctl));
    for (int i=0; i < key; i++)
        for (int j = 0; j <ctl; j++)
            rail[i][j] = '\t';
    bool flag;
    int r=0,c=0;
    for (int i=0; i < ctl; i++)
    {
        if (r == 0)
            flag = true;
        if (r == key-1)
           flag = false;

      
        rail[r][c++] = '*';

        
        flag?r++ : r--;
    }

  
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<ctl; j++)
            if (rail[i][j] == '*' && index<ctl)
                rail[i][j] = ct[index++];


    
    string result;

    r = 0, c = 0;
    for (int i=0; i< ctl; i++)
    {
        if (r == 0)
            flag = true;
        if (r == key-1)
            flag = false;

        
        if (rail[r][c] != '*')
            result.push_back(rail[r][c++]);

        
        flag?r++: r--;
    }
    return result;
}




int main(){
   char pt[10000];
   int k;
    cout<<"Enter the plain text:";
    cin>>pt;
    cout<<"Enter the key:";
    cin>>k;
    string enc;
    enc=encrypt(pt,k);
    cout<<"The encrypted form of plaintext is:"<<enc<<endl;
    string dec;
    dec=decrypt(enc,k);
    cout<<"After decryption:"<<dec;
    return 0;

}