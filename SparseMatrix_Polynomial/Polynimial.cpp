#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Poly
{
private:
    int n;
    Term *terms;

public:
    Poly()
    {
        n = 0;
        terms = nullptr;
    }

    void create()
    {
        cout << "Number of terms? ";
        cin >> n;
        terms = new Term[n];

        cout << "Enter terms:" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> terms[i].coeff >> terms[i].exp;
        }
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << terms[i].coeff << "x^" << terms[i].exp;
            if (i < n - 1)
                cout << " + ";
        }
        cout << endl;
    }

    Poly *add(Poly *p2)
    {
        int i = 0, j = 0, k = 0;
        Poly *sum = new Poly();
        sum->terms = new Term[n + p2->n];

        while (i < n && j < p2->n)
        {
            if (terms[i].exp > p2->terms[j].exp)
                sum->terms[k++] = terms[i++];
            else if (terms[i].exp < p2->terms[j].exp)
                sum->terms[k++] = p2->terms[j++];
            else
            {
                sum->terms[k].exp = terms[i].exp;
                sum->terms[k++].coeff = terms[i++].coeff + p2->terms[j++].coeff;
            }
        }
        for (; i < n; i++)
            sum->terms[k++] = terms[i];
        for (; j < p2->n; j++)
            sum->terms[k++] = p2->terms[j];

        sum->n = k;
        return sum;
    }

    ~Poly()
    {
        delete[] terms;
    }
};

int main()
{
    Poly p1, p2, *p3;

    p1.create();
    p2.create();

    p3 = p1.add(&p2);

    cout << endl;
    p1.display();
    cout << endl;
    p2.display();
    cout << endl;
    p3->display();

    delete p3;

    return 0;
}
