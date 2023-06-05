#include <iostream>

using namespace std;
//DATE
class date{
    int d, m, y;
public:
    date() : d(0), m(0), y(0){};
    void Nhap(){
        cin >> d >> m >> y;
    }
};
// USER
class user{
    string name;
    char ID[10];
    date Birth;
    char adds[100];
public:
    user() : name(""), ID(""), Birth(), adds(""){}
    void Nhap(){
        cin.ignore();
        getline(cin, name);
        cin >> ID;
        Birth.Nhap();
        cin.ignore();
        cin >> adds;
    }
};
// DAT
class certificate{
protected:
    char cer_num[10], land_adds[100];;
    user USER;
    int plot_num, map_num;
    float are, tax;
    date insuance;
public:
    virtual void Nhap(){
        cin >> cer_num;
        USER.user::Nhap();
        cin >> plot_num >> map_num;
        cin >> are >> tax;
        insuance.date::Nhap();
    }
    float price_tax(){
        return are * tax;
    }
    virtual void Xuat(){
        cout << cer_num << endl;
        cout << plot_num << " " << map_num << endl;
        cout << are << " " << tax << endl;
    }
    virtual bool check(){
        return 0;
    }
};
//################
//AGRICULTURE
class agri : public certificate{
    int qua_to;
public:
    void Nhap(){
        certificate::Nhap();
        cin >> qua_to;
    }
    bool check(){
        return qua_to < 2023;
    }
};
//#############
//NON_AGRICULTURE
class non_agri : public certificate{
public:
    void Nhap(){
        certificate::Nhap();
    }
};
//#############
//ARRAY
class arr_of_user{
    certificate* *arr;
    int iN;
public:
    friend istream& operator>> (istream &is, arr_of_user &x){
        is >> x.iN;
        x.arr = new certificate*[x.iN];
        for(int i = 0; i < x.iN; i++){
            int k; is >> k;
            switch(k) {
                case 1:
                    x.arr[i] = new agri;
                    x.arr[i]->Nhap();
                    break;
                case 2:
                    x.arr[i] = new non_agri;
                    x.arr[i]->Nhap();
            }
        }
        return is;
    }
    void best(){
        int max = 0;
        for(int i = 1; i < iN; i++) if(arr[i]->price_tax() > arr[max]->price_tax()) max = i;
        arr[max]->certificate::Xuat();
    }
    void out_of_date(){
        for(int i = 0; i < iN; i++){
            if(arr[i]->check() == 1) arr[i]->Xuat();
            cout << endl;
        }
    }
};
int main(){
    
    arr_of_user A;
    cin >> A;
    cout << "\n";
    A.best();
    cout << endl;
    A.out_of_date();
    
    return 0;
}
