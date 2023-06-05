#include <iostream>
using namespace std;

class Guild;

class character{
protected:
    static int Dem_Nhanloai;
    string name = "";
    float HP = 0.0, ATK = 0.0, DEF = 0.0;
public:
    float get_HP(){ return HP;}
    virtual void Nhap(){
        cin >> name >> HP >> ATK >> DEF;
    }
    bool is_dead(){
        return HP <= 0;
    }
    void Attack(character* x){
        if(this->ATK > x->DEF) x->HP = x->HP - (this->ATK - x->DEF);
    }
    virtual void adjust(){
        return;
    }
    void Xuat(){
        cout << name << " " << HP << "\n";
    }
};

int character::Dem_Nhanloai = 0;
class Nhan_loai : public character{
protected:
    string job = "";
public:
    void Nhap(){
        character::Nhap();
        cin >> job;
        ++Dem_Nhanloai;
    }
};
class Ban_nhan : public character{
protected:
    string racial = "";
public:
    void Nhap(){
        character::Nhap();
        cin >> racial;
    }
};
class Di_hinh : public character{};

class Human : public Nhan_loai{};
class Elf : public Nhan_loai{
    void adjust(){
        this->DEF *= 1.5;
    }
};
class Orc : public Ban_nhan{
    void adjust(){
        this->HP *= 1.5;
    }
};
class Golbin : public Ban_nhan{
public:
    void adjust(){
        this->ATK *= 1.1;
    }
};
class Vampire : public Di_hinh{
public:
    void adjust(){
        this->HP =((Dem_Nhanloai *  0.1) + 1) * this->HP;
    }
};
class Devil : public Di_hinh{
protected:
    static int Dem_Devil;
public:
    void Nhap(){
        ++Dem_Devil;
        Di_hinh::Nhap();
    }
    void adjust(){
        ATK = ATK + (Dem_Devil * 0.1) * ATK;
        DEF = DEF + (Dem_Devil * 0.1) * DEF;
    }
};
int Devil::Dem_Devil = 0;
class Guild{
    character* arr[50];
    int iN;
public:
    friend istream& operator>> (istream& is, Guild &x){
        is >> x.iN;
        for(int i = 0; i < x.iN; i++){
            int k; is >> k;
            switch(k) {
                case 1:
                    x.arr[i] = new Human;
                    x.arr[i]->Nhap();
                    break;
                case 2:
                    x.arr[i] = new Elf;
                    x.arr[i]->Nhap();
                    break;
                case 3:
                    x.arr[i] = new Orc;
                    x.arr[i]->Nhap();
                    break;
                case 4:
                    x.arr[i] = new Golbin;
                    x.arr[i]->Nhap();
                    break;
                case 5:
                    x.arr[i] = new Vampire;
                    x.arr[i]->Nhap();
                    break;
                case 6:
                    x.arr[i] = new Devil;
                    x.arr[i]->Nhap();
                    break;
            }
        }
        for(int i = 0; i < x.iN; i++) x.arr[i]->adjust();
        return is;
    }
    void attack(character* enemy){
        for(int i = 0; i < iN; i++){
            if(!arr[i]->is_dead()) arr[i]->Attack(enemy);
        }
    }
    bool is_all_dead(){
        for(int i = 0; i < iN; i++)
            if(!arr[i]->is_dead()) return 0;
        return 1;
    }
    character* get_MIN_HP(){
        character* MINHP;
        for(int i = 0; i < iN; i++){
            if(!arr[i]->is_dead()){
                MINHP = arr[i];
                break;
            }
        }
        for(int i = 0; i < iN; i++){
            if(!arr[i]->is_dead() && MINHP->get_HP() > arr[i]->get_HP()) MINHP = arr[i];
        }
        return MINHP;
    }
    void print_survivor(){
        for(int i = 0; i < iN - 1; i++){
            for(int j = i + 1; j < iN; j++)
                if(arr[i]->get_HP() > arr[j]->get_HP()){
                    character temp = *arr[i];
                    *arr[i] = *arr[j];
                    *arr[j] = temp;
                }
        }
        for(int i = 0; i < iN; i++){
            if(!arr[i]->is_dead()) arr[i]->Xuat(); }
    }
};
class Boss : public character{};

int main(){
    Guild team;
    cin >> team;
    Boss boss;
    boss.Nhap();
//    Battle
    do{
        team.attack(&boss);
        if(!boss.is_dead()) boss.Attack(team.get_MIN_HP());
        else break;
    }while(!team.is_all_dead());
    if(!boss.is_dead()) boss.Xuat();
    else{
        team.print_survivor();
    }
    return 0;
}
