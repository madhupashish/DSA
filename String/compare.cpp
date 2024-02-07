#include<iostream>
using namespace std;

int main(){
    char A[]="painter";
    char B[]="painting";

int i,j;
    for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++){
        if(A[i]!=B[i])
            break;
    }
    if(A[i]==B[i])
        cout<<"Equal";
    else if(A[i]<B[j])
        cout<<"Smaller";
    else
        cout<<"Greater";
}