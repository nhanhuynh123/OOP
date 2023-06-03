#include <iostream>
using namespace std;
// CLASS ROOM
class room{
protected:
    string type;
    int dem;
public:
    virtual void Nhap(){
        cin >> dem;
    }
    room() : dem(0), type(""){};
    room(string loai, int sdem) : type(loai), dem(sdem){};
    virtual float dthu(){
        return 0;
    }
    bool comp(float x){
        return room::dthu() > x;
    }
};
// $$$$$$$$$$$$
// Room Deluxe
class Deluxe : public room{
    float pdv, ppv;
public:
    void Nhap(){
        room::Nhap();
        cin >> pdv >> ppv;
    }
    Deluxe(){
        room("Deluxe", 0);
    }
    float dthu(){
        return dem * 750 + pdv + ppv;
    }
};
// $$$$$$$$$$$$$
// Room Premium
class Premium : public room{
    float pdv;
public:
    void Nhap(){
        room::Nhap();
        cin >> pdv;
    }
    Premium() : room("Premium", 0){};
    float dthu(){
        return dem * 500 + pdv;
    }
};
// $$$$$$$$$$
// Room Business
class Business : public room{
public:
    Business() : room("Business", 0){};
    float dthu(){ return dem * 300;}
};
// $$$$$$$$$
// Array
class Hotel{
    room* *arr;
    int iN;
    float De, Pre, Bu;
public:
    friend istream& operator>> (istream &is, Hotel &x){
        x.De = x.Pre = x.Bu = 0;
        is >> x.iN;
        x.arr = new room*[x.iN];
        
        
        for(int i = 0; i < x.iN; i++){
            
            
            int k; is >> k;
            switch (k) {
                case 1:
                    x.arr[i] = new Deluxe;
                    x.arr[i]->Nhap();
                    x.De += x.arr[i]->dthu();
                    break;
                case 2:
                    x.arr[i] = new Premium;
                    x.arr[i]->Nhap();
                    x.Pre += x.arr[i]->dthu();
                    break;
                case 3:
                    x.arr[i] = new Business;
                    x.arr[i]->Nhap();
                    x.Bu += x.arr[i]->dthu();
                    break;}
            
        }
        
        
        return is;
    }
    int best_seller(){
        if(De > Pre){
            if(De > Bu) return 1;
            else return 3;
        }
        else{
            if(Pre > Bu) return 2;
            else return 3;
        }
    }
    
};
int main(){
    Hotel SOFITEL;

    cin >> SOFITEL;
    cout << SOFITEL.best_seller();
    return 0;
}
