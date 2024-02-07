#include<iostream>
using namespace std;

int main(){
    char A[]="python";
    char B[7];
    int i;
    int j;

    for( i=0;A[i]!='\0';i++){
        i=i-1;
    }
    for( j=0;i>=0;j++){
        B[j]=A[i];
    }
    B[j]='\0';
    cout<<"Reverse of String is"<<B<<endl;

    return 0;
}
