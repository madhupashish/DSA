#include<iostream>
using namespace std;

class LTMatrix{
    private:
        int n;
        int *A;
    public:
        LTMatrix(int n){
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        ~LTMatrix(){delete []A;}
        void Display(bool row = true);
        void SetRowMajor(int i,int j,int x);
        void SetColMajor(int i,int j,int x);
        int GetRowMajor(int i,int j);
        int GetColMajor(int i,int j);
        void DisplayRowMajor();
};

void LTMatrix::SetRowMajor(int i,int j,int x){
    if(i>=j){
        int index=((i*(i-1))/2) + j-1 ;
        A[index]=x;
    }
}

void LTMatrix::SetColMajor(int i,int j,int x){
    if(i>=j){
        int index=(n*(j-1)-(((j-2)*(j-1))/2)) + i-j ;
        A[index]=x;
    }
}

int LTMatrix::GetRowMajor(int i, int j){
    if(i>=j){
        int index=(i*(i-1))/2 + j-1;
        return A[index];
    }
    else{return 0;}
}

int LTMatrix::GetColMajor(int i,int j){
    if(i>=j){
        int index=(n*(j-1)-(((j-2)*(j-1))/2)) + i-j ;
        return A[index];
    }
    else{
        return 0;
    }
}

void LTMatrix::DisplayRowMajor(){
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j)
                cout<<A[(i*(i-1))/2 + j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    int d;
    cout<<"Enter Dimentions";
    cin>>d;

    LTMatrix lm(d);
    int x;
    cout<<"Enter all Elements";
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            cin>>x;
            lm.SetRowMajor(i,j,x);
        }
    }
    lm.DisplayRowMajor();
    return 0;
}