//for counting vowels & consonents
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    char A[]="How are you";
    int Vcount=0;
    int Ccount=0;
    for(int i=0; A[i]!=0;i++){
        if(A[i]=='a'||A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]='u' 
        || A[i]=='A'||A[i]=='E'|| A[i]=='I'||A[i]=='O'||A[i]=='U'){
            Vcount++;
        }
        else if(A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122){
            Ccount++;
        }
    }

    return 0;
}