#include <iostream>

using namespace std;
int hcf(int n,int m)
{
    if(n>m)
      return(hcf(m,n));
    if(m%n==0)
        return n;
    return(hcf(m%n,n));
}

int call_lcm(int arr[],int n)
{
    int LCM=1;
    for(int i=0;i<n;i++)
    {   int HCF;
        HCF=hcf(LCM,arr[i]);
        LCM=(LCM*arr[i])/HCF;
    }
    return LCM;
}

int call_hcf(int arr[],int n)
{
    int HCF=arr[0];
    for(int i=1;i<n;i++)
    {
        HCF=hcf(HCF,arr[i]);

    }
    return HCF;
}

int main()
{   int n;
cout<<"enter the number of value\n";
cin>>n;
int arr[n];
cout<<"enter the elements\n";
for(int i=0;i<n;i++)
   cin>>arr[i];

   cout<<"lcm is:"<<call_lcm(arr,n);
        return 0;
}
