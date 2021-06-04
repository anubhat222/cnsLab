#include<bits/stdc++.h>
using namespace std;
bool isPrime(long long int n){
    if(n<=1){
        return false;
    }
    if(n==2||n==3){
        return true;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
            break;
        }
    }
    return true;
}
long long int power(long long int a, long long int b,long long int P)
{
	if (b == 1)
		return a;

	return (((long long int)pow(a, b)) % P);
}

int main(){
   long long int P, G, x, a, y, b, ka, kb;
	
	cout<<"Enter the prime number P: ";
	cin>>P;
    cout<<"Verifing wether the number is prime or not"<<endl<<"...."<<endl<<"...."<<endl<<"...."<<endl;
    while(!isPrime(P)){
        cout<<"The above entered number was not a prime, Please enter a a valid number which belongs to prime category:";
        cin>>P;
    }
   
    cout<<"Enter the value for G : ";
	cin>>G;
	cout<<"Enter the secret integer a & b: ";
	cin>>a>>b;
	x = power(G, a, P);
	y = power(G, b, P);
	cout<<" The private keys are : "<<x<< " "<<y<<endl;
	ka = power(y, a, P);
	kb = power(x, b, P);
	cout<<"The public keys are : "<<ka<<" "<<kb<<endl;

	
}