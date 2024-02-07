#include<iostream>
using namespace std;

class UTMatrix{
    private:
        int n;
        int *A;
    public:
        UTMatrix(int n);
        ~UTMatrix();
        void SetRowMajor(int i,int j,int x);
        void SetColMajor(int i,int j,int x);
        int GetRowMajor(int i,int j);
        int GetColMajor(int i,int j);
        void DisplayRowMajor();
        void DisplayColMajor();
};

UTMatrix::UTMatrix(int n){
    this->n=n;
    A=new int[n*(n+1)/2];
}

UTMatrix::~UTMatrix(){
    delete []A;
}

void UTMatrix::SetRowMajor(int i,int j,int x){
    if(i<=j){
        int index=(n*(i-1)-(((i-2)*(i-1))/2)) + j-i ;
        A[index]=x;
    }
}

void UTMatrix::SetColMajor(int i,int j,int x){
    if(i<=j){
        int index=(j*(j-1))/2 + i-1;
        A[index]=x;
    }
}

int UTMatrix::GetRowMajor(int i,int j){
    if(i<=j){
        int index=(n*(i-1)-(((i-2)*(i-1))/2)) + j-i;
        return A[index];
    }
}

int UTMatrix::GetColMajor(int i,int j){
    int index=(j*(j-1))/2 + i-1;
    return A[index];
}

void UTMatrix::DisplayRowMajor(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j){
                cout<<A[(n*(i-1)-(((i-2)*(i-1))/2)) + j-i]<<" ";
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

void UTMatrix::DisplayColMajor(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j){
        cout<<A[(j*(j-1))/2 + i-1]<<" ";
    }
    else{
        cout<<"0 ";
    }
        }
    }
    cout<<endl;
}

int main(){
    int d;
    cout<<"Enter Dimentions";
    cin>>d;

    UTMatrix um(d);
    int x;
    cout<<"Enter all Elements";
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            cin>>x;
            um.SetRowMajor(i,j,x);
        }
    }
    um.DisplayRowMajor();

    return 0;
}