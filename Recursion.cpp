#include <bits/stdc++.h>
using namespace std;

int fact(int n,int val =1){
    if(n==0) return val;
    return fact(n-1,n*val);
}

bool ispal(string str, int s=0, int e=4)
{
    if(s>=e) return true;
    if(str[s]!=str[e]) return false;
    return ispal(str,s+1,e-1);
}

int sumofdigits(int n,int val=0) //tail recursion
{
    if(n==0) return val;
    return sumofdigits(n/10,val+n%10);
}

int maxropecuts(int n,int a,int b,int c)
{
    if(n==0) return 0;
    else if(n<0) return -1;
    int res = max({maxropecuts(n-a,a,b,c), maxropecuts(n-b,a,b,c), maxropecuts(n-c,a,b,c)});
    if(res == -1) return -1;//not possible
    return res+1;//possible cut
}

int fibb(int n)
{
    if(n<=1) return n;
    return fibb(n-1)+fibb(n-2);
}

void printnto1(int n)
{
    if(n==0) return;
    cout<<n<<" ";
    printnto1(n-1);
}

void print1ton(int n,int k=1)
{

    if(n==0) return;
    cout<<k<<" ";
    print1ton(n-1,k+1);
}

void subsetprinter(string str,string ans,int size,int i = 0)
{
    if(i==size) {cout<<ans<<" ";return ;}
    subsetprinter(str,ans,size,i+1);
    subsetprinter(str,ans+str[i],size,i+1);
}
int main()
{
    cout<<"factorial: "<<fact(5)<<"\n";
    cout<<"fibb: "<<fibb(5)<<"\n";
    cout<<"printing 5 to 1:\n";
    printnto1(5);
    cout<<"\n";
    cout<<"printing 1 to 5:\n";
    print1ton(5);
    cout<<"\n";
    cout<<"ispal:"<<ispal("abbaa")<<"\n";
    cout<<"sum of digits of 253: "<<sumofdigits(253)<<"\n";
    cout<<"maxcuts: "<<maxropecuts(5,2,1,5)<<"\n";
    cout<<"Subset of ABC:\n";
    subsetprinter("ABC","",3,0);
    cout<<"\n";
}