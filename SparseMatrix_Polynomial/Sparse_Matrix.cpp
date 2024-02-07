#include <iostream>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element* ele;

public:
    Sparse(int rows, int cols, int count)
    {
        m = rows;
        n = cols;
        num = count;
        ele = new Element[num];
    }

    ~Sparse()
    {
        delete[] ele;
    }

    void create()
    {
        cout << "Enter Dimensions: ";
        cin >> m >> n;
        cout << "Number of non-zero elements: ";
        cin >> num;

        cout << "Enter non-zero elements: ";
        for (int i = 0; i < num; i++)
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
    }

    void display()
    {
        int k = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k < num && i == ele[k].i && j == ele[k].j)
                    cout << ele[k++].x << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    Sparse* add(Sparse& s2)
    {
        if (n != s2.n || m != s2.m)
            return nullptr;

        Sparse* sum = new Sparse(m, n, num + s2.num);

        int i = 0, j = 0, k = 0;
        while (i < num && j < s2.num)
        {
            if (ele[i].i < s2.ele[j].i)
                sum->ele[k++] = ele[i++];
            else if (ele[i].i > s2.ele[j].i)
                sum->ele[k++] = s2.ele[j++];
            else
            {
                if (ele[i].j < s2.ele[j].j)
                    sum->ele[k++] = ele[i++];
                else if (ele[i].j > s2.ele[j].j)
                    sum->ele[k++] = s2.ele[j++];
                else
                {
                    sum->ele[k] = ele[i];
                    sum->ele[k++].x = ele[i++].x + s2.ele[j++].x;
                }
            }
        }

        for (; i < num; i++)
            sum->ele[k++] = ele[i];
        for (; j < s2.num; j++)
            sum->ele[k++] = s2.ele[j];

        sum->num = k;
        return sum;
    }
};

int main()
{
    Sparse s1(0, 0, 0), s2(0, 0, 0), *s3;

    s1.create();
    s2.create();

    s3 = s1.add(s2);

    if (s3 == nullptr)
    {
        cout << "Matrices cannot be added." << endl;
        return 0;
    }

    cout << "First Matrix" << endl;
    s1.display();
    cout << "Second Matrix" << endl;
    s2.display();
    cout << "Sum Matrix" << endl;
    s3->display();

    delete s3;

    return 0;
}
