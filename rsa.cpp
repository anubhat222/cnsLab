#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int hcf(int a, int b){
    if(a==0){
        return b;
    }
    else{
    hcf(b%a,a);
    }
}
int encrypt(int e,int n,int msg){
    return fmod(pow(msg,e),n);
}
int decrypt(int d,int n,int cmsg){
    int de=1;
    for(int i=1;i<=d;i++){
        de=(de*cmsg)%n;
    }
    return de;

}

int main(){
    int p,q,e,d;
    int m;
    int enc,dec;
    int n,phi;
    cout<<"Enter the message:";
    cin>>m;
    cout<<"Enter 2 large prime nos for key generation: ";
    cin>>p>>q;
    n=p*q;
    phi=(p-1)*(q-1);
    cout<<"n :"<<n<<endl;
    cout<<"Euler's Totient is :"<<phi<<endl; 
    cout<<"Choose the value of e,it should be less than euler's totient: ";
    cin>>e;
    //correction of e and phi are not coprimes
    if(hcf(e,phi)!=1){
        while(e<phi){
            e++;
            if(hcf(e,phi)==1){
                break;
            }

        }
    }
    //private key
    
    for(d=1;d<phi;d++){
        if((e*d)%phi==1)
        break;
    }
    cout<<"Private key element d="<<d<<endl;
    enc=encrypt(e,n,m);
    dec=decrypt(d,n,enc);
    cout<<"encrypted message is :"<<enc<<endl;
    cout<<"After decryption:"<<dec<<endl;
    return 0;

}

