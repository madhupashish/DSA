#include<iostream>
using namespace std;

template<class T>
class Array{
    private:
        T *A;
        int size;
        int length;
    public:
        Array(){
            size=10;
            length=0;
            A=new T [size];
        }
        ~Array(){
            delete []A;
        }

void display();
void insert(T x ,int index);
T Delete(int index);

};

template <class T>
void Array<T>::display(){
    for(int i= 0;i<length ; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void Array<T>::insert(T x,int index){
    if(index>=0 && index<=length){
        for(int i=length-1;i>=index; i--){
            A[i+1]=A[i];
            A[index]=x;
            length++;
        }
    }
}

template<class T>
T Array<T>::Delete(int index){
    T x=0;
    if(index>=0 && index<=length){
        x=A[index];
        for(int i= index; i<length-1;i++){
            A[i]=A[i+1];}
            length--;
    }
    return x;
}

int main(){
    Array<char>arr(10);
    arr.insert(0,'a');
    arr.insert(1,'b');
    arr.insert(2,'c');
    arr.display();
    cout<<arr.Delete(0);
    arr.display();

    return 0;
}