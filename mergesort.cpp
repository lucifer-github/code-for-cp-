#include<iostream>
#include <vector>
#include<stdlib.h>
#define SIZE 50
using namespace std;
//vector<int> A(SIZE);
void init(int *A){
	for(int i=0;i<SIZE;i++){
		A[i]=rand();
		 //A++;
    }//	return A;
}
void mergesort(int *A,int low,int high){
       if(low>=high){
           return;
          //return A[high];
       }


       int mid=(low+high)/2;
       mergesort(A,low,mid);
       mergesort(A,mid+1,high);
       vector <int> v;
       int i ,j;
       i=low;
       j=mid+1;

       while(i<=mid&&j<=high){
         	if(A[i]>A[j]){
               v.push_back(A[j]);
               j++;
         	}

       	    else{
       		    v.push_back(A[i]);
       	     	i++;
       	    }
       }//while

       while(i<=mid){
         	v.push_back(A[i]);
       	    i++;
       }
       while(j<=high){
       	    v.push_back(A[j]);
       	    j++;
       }
       for(int i=0;i<v.size();i++){
       	A[i+low]=v[i];
       }
//return A;

}
int main(){int A[SIZE];
  //  vector <int> A(SIZE);
	init(A);
	//cout<<"\the"<<A[3];
    mergesort(A,0,SIZE-1);
    for(int i=0;i<SIZE;i++){
    	cout<<A[i]<<"\ti:"<<i<<"\n";
    }
	return 0;

}
