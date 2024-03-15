#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class CauhoiTn {
private:
    string noiDungCauHoi;
    string noiDungDapAnA;
    string noiDungDapAnB;
    char dapAnDung;

public:
    void nhap();
    void docfile(ifstream& f);
    void ghifile(ofstream& f);
    void kiemtra();
    void xuat();
    void menu();

    // khai bao ham friend
    friend bool giongnhau(CauhoiTn cau1, CauhoiTn cau2);
};

void CauhoiTn::nhap() {
    cin.ignore(); // loai bo ki tu '\n' thua
    cout << "nhap noi dung cau hoi: ";
    getline(cin, noiDungCauHoi);
    cout << "nhap noi dung dap an A: ";
    getline(cin, noiDungDapAnA);
    cout << "nhap noi dung dap an B: ";
    getline(cin, noiDungDapAnB);
    cout << "dap an dung (A hoac B): ";
    cin >> dapAnDung;
}

void CauhoiTn::docfile(ifstream& f) {
    getline(f, noiDungCauHoi);
    getline(f, noiDungDapAnA);
    getline(f, noiDungDapAnB);
    f >> dapAnDung;
    f.ignore(); // loai bo ki tu '\n' thua
}

void CauhoiTn::ghifile(ofstream& f) {
    f << noiDungCauHoi << endl;
    f << noiDungDapAnA << endl;
    f << noiDungDapAnB << endl;
    f << dapAnDung << endl;
}

void CauhoiTn::kiemtra() {
    cout << "cau hoi: " << noiDungCauHoi << endl;
    cout << "dap an A: " << noiDungDapAnA << endl;
    cout << "dap an B: " << noiDungDapAnB << endl;
    char traLoi;
    cout << "nhap cau tra loi cua ban (A hoac B): ";
    cin >> traLoi;
    if (toupper(traLoi) == toupper(dapAnDung)) {
        cout << "Cau tra loi dung!" << endl;
    }
    else {
        cout << "Cau tra loi sai!" << endl;
    }
}

void CauhoiTn::xuat() {
    cout << noiDungCauHoi << endl;
    cout << dapAnDung << endl;
}

void CauhoiTn::menu() {
    vector<CauhoiTn> options;
    int luaChon;
    do {
        cout << "======================MENU====================" << endl;
        cout << "1. tao de thi" << endl;
        cout << "2. kiem tra" << endl;
        cout << "3. xoa khoang trong thua o cac cau hoi va tra loi" << endl;
        cout << "4. thoat!" << endl;
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            cout << "nhap so luong cau hoi: ";
            int n;
            cin >> n;
            options.resize(n);
            for (int i = 0; i < n; i++) {
                cout << "cau " << i + 1 << ":" << endl;
                options[i].nhap();
            }
            break;
        }
        case 2:
            for (auto& test : options) {
                test.kiemtra();
            }
            break;
        case 3: {
            ifstream inputFile("de_thi.ttn");
            ofstream outputFile("temp_de_thi.ttn"); // Tao file tam de luu va chinh sua
            if (!inputFile.is_open() || !outputFile.is_open()) {
                cout << "Khong the mo file!" << endl;
                break;
            }

            string line;
            while (getline(inputFile, line)) {
                // loai bo khoang trong thua o dau dong va cuoi dong
                line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
                line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);

                // ghi lai noi dung da chinh sua vao file moi
                outputFile << line << endl;
            }

            // dong file va xoa file cu
            inputFile.close();
            outputFile.close();
            remove("de_thi.ttn");
            // Doi ten file temp thanh ten file cu
            rename("temp_de_thi.ttn", "de_thi.ttn");

            cout << "Da xoa khoang trong thua thanh cong!" << endl;
            break;
        }
        case 4:
            cout << "thoat chuong trinh!" << endl;
            break;
        default:
            cout << "du lieu khong hop le!" << endl;
        }
    } while (luaChon != 4);
}

// dinh nghia ham friend giongnhau
bool giongnhau(CauhoiTn cau1, CauhoiTn cau2) {
    return (cau1.noiDungCauHoi == cau2.noiDungCauHoi &&
        cau1.noiDungDapAnA == cau2.noiDungDapAnA &&
        cau1.noiDungDapAnB == cau2.noiDungDapAnB &&
        cau1.dapAnDung == cau2.dapAnDung);
}

int main() {
    CauhoiTn hihi;
    hihi.menu();
    return 0;
}
