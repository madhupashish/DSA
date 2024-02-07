#include<iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
    public:
        Array(){
            size=10;
            length=0;
            A=new int[size];
        }
        ~Array(){
            delete []A;
        }
        void Display();
        int LinearSearch(int key);
        int LinearSearch1(int key);
        void Swap(int *X, int *Y);
};

void Array :: Display(){
    for(int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
}

void Array :: Swap(int* X , int *Y){
    int temp;
    temp=*X;
    *X=*Y;
    *Y=temp;
}

int Array :: LinearSearch(int key){
    for(int i=0;i<length;i++){
        if(key==A[i]){
            return i;
        }
    }
        return -1;
}

int Array :: LinearSearch1(int key){
    for(int i=0;i<length;i++){
        if(key==A[i]){
            Swap(&A[i],&A[0]);
            return i;
        }
    }
    return -1;
}

int main (){
    int arr[]={10,11,12,13,14,15,17};
    
    return 0;
}