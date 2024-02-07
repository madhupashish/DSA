//for counting words in a sentence
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    char A[]="How are you";
    int word=1;
    for(int i=0; A[i]!='\0';i++){
        if(A[i] ==" " && A[i-1]!==" "){
            word++;
        }
    }
    cout<<"No. of words is  "<<word<<endl;
    printf("%d",word);

    return 0;
}