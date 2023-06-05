#include <iostream>
using namespace std;

class Hotel;
class room{
protected:
    int So_dem = 0;
public:
    virtual void Nhap(){
        cin >> So_dem;
    }
    virtual float dThu(){
        return 0;
    }
};
class Deluxe : public room{
    static float TongdThu;
    float pdv = 0.0, ppv = 0.0;
public:
    void Nhap(){
        room::Nhap();
        cin >> pdv >> ppv;
    }
    float dThu(){
        TongdThu += pdv + ppv + 750 * So_dem;
        return  pdv + ppv + 750 * So_dem;
    }
    static float Tong(){ return TongdThu;}
};
class Premium : public room{
    static float TongdThu;
    float pdv;
    public:
    void Nhap(){
        room::Nhap();
        cin >> pdv;
    }
    float dThu(){
        TongdThu += pdv + 500 * So_dem;
        return pdv + 500 * So_dem;
    }
    static float Tong(){ return TongdThu;}
};
class Business : public room{
    static float TongdThu;
    public:
    float dThu(){
        TongdThu += 300 * So_dem;
        return 300 * So_dem;
    }
    static float Tong(){ return TongdThu;}
};
float Deluxe::TongdThu = 0;
float Premium::TongdThu = 0;
float Business::TongdThu = 0;
class Hotel{
    int iN;
    room* arr[50];
public:
    friend istream& operator>> (istream &is, Hotel &x){
        is >> x.iN;
        for(int i = 0; i < x.iN; i++){
            int k; is >> k;
            switch(k) {
                case 1:
                    x.arr[i] = new Deluxe;
                    x.arr[i]->Nhap();
                    break;
                case 2:
                    x.arr[i] = new Premium;
                    x.arr[i]->Nhap();
                    break;
                case 3:
                    x.arr[i] = new Business;
                    x.arr[i]->Nhap();
                    break;
            }
        }
        for(int i = 0; i < x.iN; i++) x.arr[i]->dThu();
        return is;
    }
    int find_max_dThu(){
        if(Deluxe::Tong() > Premium::Tong()){
            if(Deluxe::Tong() > Business::Tong()) return 1;
            else return 3;
        }
        else{
            if(Premium::Tong() > Business::Tong()) return 2;
            else return 3;
        }
    }
};

int main(){
    Hotel Sofitel;
    cin >> Sofitel;
    cout << Sofitel.find_max_dThu();
    return 0;
}
