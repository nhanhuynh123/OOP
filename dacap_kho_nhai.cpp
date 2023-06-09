#include <iostream>
using namespace std;

class GiamDoc{
protected:
    static float Sodu;
public:
    virtual void tralai(){
        return;
    }
    virtual void chihoahong(){
        return;
    }
};
class DaiLy : public GiamDoc{
private:
    int cap;
    float tiendonggop;
    int sogoi = 0;
    float arr[50];
protected:
    float sodu;
public:
    void donggop(float tien){
        tiendonggop += tien;
    }
    void tangcap(){
        if(tiendonggop > 500 * cap) cap++;
    }
    void nhanlai(float lai){
        sodu += lai;
    }
    void nhanhoahong(float hh){
        sodu += hh;
    }
    void mua(float x){
        GiamDoc::Sodu += x;
    }
    void mua(int x)
};
class NDT : public DaiLy{
public:
    void mua(float x){
        DaiLy::mua(x);
    }
    void nhanlai(float lai){
        sodu += lai;
    }
};
int main(){
    
    return 0;
}
