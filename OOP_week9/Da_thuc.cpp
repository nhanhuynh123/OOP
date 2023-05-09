#include <iostream>
#include <math.h>

using namespace std;
class Dathuc{
    int n;
    int *a;
public:
    // Khởi tạo
        Dathuc() {
        n = 0;
        a[0] = 0;
        }
        // Khởi tạo đa thức bậc n
        Dathuc(const int n, int heso[]) : n(n), a(new int [n+1]) {
            for (int i = 0; i <= n; i++) {
                a[i] = 0;
            }
        }
        // Chuyển kiểu từ int sang Dathuc
        explicit Dathuc(int x) : n(0), a(new int[1]) {
            a[0] = x;
        }
//    tinh gia tri da thuc
    int operator() (int x){
    int res = 0;
    for(int i = 0; i < n; i++) res += a[i] * pow(x, i);
    return res;
    }
// tra ve he so tai vi tri i
    int& operator[] (int i){
        if(i < 0 || i > n){
            throw "Ko hop le.";
        }
        return a[i];
    }
//    Nhap
    friend istream& operator>> (istream &is, Dathuc &x){
        is >> x.n;
        x.a = new int [x.n + 1];
        for(int i = x.n; i >= 0; i--) is >> x.a[i];
        return is;
    }
//    Xuat
    friend ostream& operator<< (ostream &os, Dathuc &x){
        for(int i = x.n; i >= 0; i--){
            os << x.a[i];
            if(i != 0) os  << "(x^" << i << ")" << " + ";
        }
        return os;
    }
//    Tong hai da thuc
    friend Dathuc operator+ (Dathuc A, Dathuc B){
        int max_n = max(A.n, B.n);
        Dathuc Res(max_n);
        for(int i = 0; i <= min(A.n, B.n); i++) Res.a[i] = A.a[i] + B.a[i];
        for(int i = min(A.n, B.n) + 1; i <= Res.n; i++){
        if(A.n > B.n) Res.a[i] = A.a[i];
        else Res.a[i] = B.a[i];
        }
        return Res;
    }
};
int main(){
    Dathuc D;
    cin >> D;
    cout << D << endl;
    cout << D.calculus(3) << endl;
    Dathuc Res = D + 2;
    cout << Res << endl;
    return 0;
}
