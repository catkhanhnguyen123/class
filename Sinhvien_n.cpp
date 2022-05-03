#include <iostream>

using namespace std;

struct ngaysinh
{
    int ngay, thang, nam;

};

class sinhvien
{
private:
    char hoten[20];
    struct ngaysinh
    {
        int ngay;
        int thang;
        int nam;
    };
    ngaysinh n;

public:
    void set(char hoten[20], ngaysinh n)
    {
        strcpy_s(this->hoten, hoten);
        this->n = n;
    }
    void nhap(sinhvien* a)
    {
        cout << "Nhap thong tin sinh vien:";
        cin >> a->hoten >> a->n.ngay >> a->n.thang >> a->n.nam ;
    }
    void display(sinhvien* a)
    {
        cout << a->hoten << endl;
        cout << a->n.ngay << "/" << a->n.thang << "/" << a->n.nam << endl;
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
            for (int j = i + 1; j < n; j++){
                if ((p + i)->n.nam > (p + j)->n.nam) {
                    sinhvien tmp = *(p + j);
                    *(p + j) = *(p + i);
                    *(p + i) = tmp;
                }
                else if ((p + i)->n.nam == (p + j)->n.nam) {
                    if ((p + i)->n.thang > (p + j)->n.thang){
                        sinhvien tmp = *(p + j);
                        *(p + j) = *(p + i);
                        *(p + i) = tmp;
                    }
                    else if ((p + i)->n.thang == (p + j)->n.thang) {
                        if ((p + i)->n.ngay > (p + j)->n.ngay) {
                            sinhvien tmp = *(p + j);
                            *(p + j) = *(p + i);
                            *(p + i) = tmp;
                        }
                    }
                }
            }
        }
    }
};
int main()
{
    sinhvien* p;
    p = new sinhvien[3];
    cout << "Nhap thong tin sv: " << endl;
    p->Nhapds(p, 3);
    cout << "Hien thi thong tin vua nhap: " << endl;
    p->Hienthids(p, 3);
    cout << "Danh sach sau khi sap xep la: " << endl;
    p->Sapxep(p, 3);
    p->Hienthids(p, 3);
    delete[] p;
    return 0;
}
