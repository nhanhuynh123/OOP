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


// Ham huy destructor: dung de huy doi tuong
// giong voi constructor:
// ten ham trung voi ten lop
// khac voi constructor:
// co dau nga phia truoc
// chi co duy nhat mot ham huy, nhung co nhieu constructor
// neu ko dinh nghia ham huy thi mac nhien compiler se tu tao 1 ham huy tu nhien
// ham huy tu dong duoc goi
// khi ko co thuoc tinh con tro ko can build ham huy
