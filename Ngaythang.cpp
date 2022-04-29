#include <iostream>

using namespace std;

class NGAYTHANG
{
private:
    int ngay, thang, nam;
};

class sinhvien
{
private:
    int masv;
    char hoten[20];
    int diemthi;

public:
    void set(int masv, char hoten[20], int diemthi)
    {
        this->masv = masv;
        strcpy_s(this->hoten, hoten);
        this->diemthi = diemthi;
    }
    void nhap(sinhvien* a)
    {
        cout << "Nhap thong tin sinh vien:";
        cin >> a -> masv >> a -> hoten >> a -> diemthi;
    }

    void display(sinhvien* a)
    {
        cout << a -> masv << endl;
        cout << a -> hoten << endl;
        cout << a -> diemthi << endl;
    }

    void Nhapds(sinhvien* p, int n) {
        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin cua sv thu " << i + 1 << " :" << endl;
            nhap(p + i);
        }
    }
    void Hienthids(sinhvien* p, int n) {
        for (int i = 0; i < n; i++) {
            display(p + i);
            cout << "\n";
        }
    }
    void Sapxep(sinhvien* p, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                if ((p + i)->diemthi > (p + j)->diemthi) {
                    sinhvien tmp = *(p + j);
                    *(p + j) = *(p + i);
                    *(p + i) = tmp;
                }
        }
    }

};

int main()
{
    sinhvien* p;
    p = new sinhvien[3];
    cout << "Nhap thong tin sv: " << endl;
    p -> Nhapds(p, 3);
    cout << "Hien thi thong tin vua nhap: " << endl;
    p -> Hienthids(p, 3);
    cout << "Danh sach sau khi sap xep la: " << endl;
    p -> Sapxep(p, 3);
    p -> Hienthids(p, 3);
    delete[] p;
    return 0;
}

