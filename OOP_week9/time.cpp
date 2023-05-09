#inlcude <iostream>

class time
  int s, m, h;
public:
  time(int s1){
    h = s1/3600;
    m = (s1%3600) / 60;
    s = (s1%3600) % 60;
    return *this;}
//   Mot so truong hop dung ham friend
//   operator Nhap, xuat
//   operator cong, tru, nhan, chia
//   chuyen kieu
//   truy xuat thuoc tinh cua hai lop ma ko the dung cac pham vi truy xuat khac: vecto nhan ma tran

// dung static:
// muon tinh toan, xu ly 1 tien ich hoac van de ko lien quan den class hien tai: tim 'uoc chung lon nhat' trong 'ham rut gon' cua class 'phan so'
