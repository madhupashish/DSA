//changing upppercase into lowercase
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    char A[]="WELCOME";
    for(int i=0;A[i]!=0;i++){
        A[i]=A[i]+32;
    }
    cout<<"After Changing Case of String the New String is "<< A <<endl;
    printf("%s",A);
    
    return 0;
}