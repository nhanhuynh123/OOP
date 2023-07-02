#include <iostream>
using namespace std;
class time{
    int s, m, h;
    public:
    int turntosecond(){
        return s + 60*m + 3600*h;
    }
    time turntotime(){
        int sum = this->turntosecond();
        time temp;
        temp.h = sum/3600;
        sum %= 3600;
        temp.m = sum/60;
        sum %= 60;
        temp.s = sum;
        return temp;
    }
    time() : s(0), m(0), h(0){}
    friend istream& operator>> (istream &is, time &x){
        is >> x.s >> x.m >> x.h;
        return is;
    }
    friend ostream& operator<< (ostream &os, time &x){
        os << x.s << " " << x.m << " " << x.h << " ";
        return os;
    }
    time operator++ (){
        this->s = this->s + 1;
        (*this) = this->turntotime();
        return (*this);
    }
};
int main(){
    class time Time;
    cin >> Time;
    ++Time;
    cout << "\n" << Time;

    return 0;
}
