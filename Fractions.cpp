#include <iostream>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo(int tu, int mau)
    {
        this -> tu = tu;
        this -> mau = mau;
    }

    void xuat()
    {
        int uoc = gcd(abs(tu), mau);
        cout << tu / uoc << "/" << mau / uoc << endl;
    }
    void cong(PhanSo a)
    {
        tu = tu * a.mau + mau * a.tu;
        mau = mau * a.mau;
    }
    void tru(PhanSo a)
    {
        tu = tu * a.mau - mau * a.tu;
        mau = mau * a.mau;
    }
    void nhan(PhanSo a)
    {
        tu = tu * a.tu;
        mau = mau * a.mau;
    }
    void chia(PhanSo a)
    {
        tu = tu * a.mau;
        mau = mau * a.tu;
    }
};

int main()
{
    PhanSo a(1, 2), b(2, 3), c(0, 0);
    
    cout << "Cong = ";
    c = a;
    c.cong(b);
    c.xuat();

    cout << "Tru = ";
    c = a;
    c.tru(b);
    c.xuat();

    cout << "Nhan = ";
    c = a;
    c.nhan(b);
    c.xuat();

    cout << "chia = ";
    c = a;
    c.chia(b);
    c.xuat();
}


