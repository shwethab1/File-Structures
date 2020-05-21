#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int flag = 0;
void merge(ofstream &b, ifstream &c, ifstream &d)
{
    char buf1[10], buf2[10];
    strcpy(buf1, " ");
    strcpy(buf2, " ");
    while (!(c.eof()) && !(d.eof()))
    {
        if (strcmp(buf1, buf2) == 0)
        {
            b << buf1 << "|";
            c.getline(buf1, 25, '|');
            d.getline(buf2, 25, '|');
        }
        else if (strcmp(buf1, buf2) > 0)
        {
            b << buf2 << "|";
            d.getline(buf2, 25, '|');
            flag = 1;
        }
        else
        {
            b << buf1 << "|";
            c.getline(buf1, 25, '|');
            flag = 2;
        }
    }
    if (flag == 1)
    {
        b << buf1 << "|";
    }
    else if (flag == 2)
    {
        b << buf2 << "|";
    }
    if (d.eof())
    {
        while (!c.eof())
        {
            c.getline(buf1, 25, '|');
            b << buf1 << "|";
        }
    }
    else
    {
        while (!d.eof())
        {
            d.getline(buf2, 25, '|');
            b << buf2 << "|";
        }
    }
}

int main()
{

    int m;
    cout << "enter the no of files\n";
    cin >> m;
    int e = 1, n = 1;
    char file[20][20];
    for (int i = 1; i <= m; i++)
    {
        cout << "enter the file name" << i << ":\n";
        cin >> file[n];
        ofstream ofile1(file[n]);
        n++;
        cout << "enter the no of records\n";
        int z;
        char name[10];
        cin >> z;
        cout << "enter the record contents\n";
        for (int f = 0; f < z; f++)
        {
            cin >> name;
            ofile1 << name << "|";
        }
        ofile1.close();
    }
    while (m != 1)
    {
        if (m % 2 == 1)
        {
            m++;
        }
        m = m / 2;
        for (int j = 0; j < m; j++)
        {
            cout << "enter inter filename\n";
            cin >> file[n];
            ofstream outf(file[n]);
            ifstream ofile1(file[e]);
            ifstream ofile2(file[e + 1]);
            e = e + 2;
            n++;
            merge(outf, ofile1, ofile2);
            outf.close();
            ofile1.close();
            ofile2.close();
        }
    }
    cout << "\nthe sorted records are in the file:" << file[n - 1] << endl;
    cout << "\nsorted records ie contents of file " << file[n - 1] << " are\n";
    ifstream out(file[n - 1]);
    while (!out.eof())
    {
        char name[10];
        out.getline(name, 25, '|');
        cout << name << " ";
    }
    return 0;
}
