#include <iostream>
#include<cstring>
#include<fstream>
#pragma warning(disable:4996)

using namespace std;

void removepunct()
{
    ifstream fin("TextFile1.txt");
    char x[111];
    fin.getline(x, 111);

    size_t len = strlen(x);

    cout << "Introdu sirul initial\n" << x << '\n';

    for (int i = 0; i < len;++i)
    {
        if (ispunct(x[i]))
        {
            strcpy(x + i, x + i + 1);
            --i;
            --len;

        }
    }

    cout << x;
}

void upperLwr()
{
    ifstream fin("TextFile1.txt");
    char u[111];
    fin.getline(u, 111);

    size_t len = strlen(u);

    for (int i = 0;i < len;++i)
    {
        if (isalpha(u[i]))
        {
            if (islower(u[i]))
            {
                u[i] -= 32;
            }
            else
            {
                u[i] += 32;
            }


        }

    }

    cout << u;

}

void filtrareNumere()
{
    ifstream fin("TextFile1.txt");
    char a[256];
    fin.getline(a, 111);

    size_t len = strlen(a);

    for (int i = 0; i < len;++i)
    {
        if (isdigit(a[i]))
        {
            strcpy(a + i, a + i + 1);
            --i;
            --len;
        }

    }

    cout << a;

}


int main() {

    cout << "introduceti  valoarea:\n 0 = stergerea semnelor de punctuatie\n 1 = conversie upper/lower\n 2 = elimina cifre\n";
    int n;
    cin >> n;

    switch (n) {
    case 1:
        upperLwr();
        break;

    case 2:
        filtrareNumere();
        break;
    default:
        removepunct();

    }



    return 0;
}