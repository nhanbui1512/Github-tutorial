#include "Sotietkiem.h"

int Thoigian(int d,int m,int y){
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);

    int current_d = now->tm_mday;    // ngày hiện tại
    int current_m = (now ->tm_mon +1);   // tháng hiện tại
    int current_y =(now->tm_year + 1900);    // năm hiện tại
    int a = 0;
    
    while(current_y >= y){
        
        if(current_y == y && current_m == m){
            a+= current_d - d;
            break;
        }
        else { // thang 4,6,9,11 co 30 ngay
            if(m==4 || m==6 || m==9 || m==11){
                a+=30-d;
            } 
            // thang 1,3,5,7,8,10 co 31 ngay
            if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                a+=31-d;
            }
            if (m==2) { 
                if(y%4==0 && y%100!=0 || y%400 == 0){ // thang 2 nhuan 29 ngay
                    a+=29-d;
                } 
                else a+=28-d;   // thang 2 nhuan 28 ngay
            }
            m++; d=0;
            if(m==13){ // qua năm khác
            y++; m =1;
            }
        }
    }
    if (y>current_y || (y >= current_y && m > current_m ) || (d>current_d && m >= current_m && y >= current_y ) ) a = 0;   // Nếu thời điểm trước ngày hiện tại thì trả về = 0 
    return a;
}
// So tiet kiem
Sotietkiem::Sotietkiem(){
	this-> _Ten = " ";
	this-> _CMND = 0;
	this-> _TienGui = 0;
	this-> _ngaygui = 1;
	this-> _thanggui = 1;
	this-> _namgui = 2000;
	this->_Laitichluy = 0;
    this->_kyhan = 0;
}
Sotietkiem::~Sotietkiem(){

}

void Sotietkiem::Nhap(){
    cout <<"\n\t\t" <<"Nhap ma khach hang: ";fflush(stdin); getline(cin,_MaKH);;
	cout <<"\t\t" <<"Nhap ten khach hang: "; getline(cin,_Ten);
	cout <<"\t\t" <<"Nhap CMND : "; cin >>_CMND;

    time_t t = time(0);   // get time now
    tm* now = localtime(&t);

    int current_d = now->tm_mday;    // ngày hiện tại
    int current_m = (now ->tm_mon +1);   // tháng hiện tại
    int current_y =(now->tm_year + 1900);    // năm hiện tại

    do
    {
        int A[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
        bool value;
        do
        {
            cout <<"\t\t" << "Nhap thoi diem gui tien " << endl;
            do
            {
                cout <<"\t\t" << "Ngay: ";cin >> _ngaygui;
                if (_ngaygui < 1 || _ngaygui> 31) cout << "\t\tNgay khong hop le. Nhap lai ngay gui: " <<endl;
            } while (_ngaygui < 1 || _ngaygui > 31);
            do
            {
                cout <<"\t\t" << "Thang: ";cin >> _thanggui;
                if (_thanggui < 1 || _thanggui>12) cout << "\t\tThang khong hop le. Nhap lai thang gui: " <<endl;
            } while (_thanggui < 1 || _thanggui>12);
            do
            {
                cout <<"\t\t" << "Nam: ";cin >> _namgui;
                if (_namgui < 0 || _namgui> current_y) cout << "\t\tNam khong hop le. Nhap lai nam gui: " <<endl;
            } while (_namgui < 0 || _namgui> current_y);

            if (_thanggui != 2) {
                if (_ngaygui > A[_thanggui]) value = false;
                else value = true;
            }
            else {
                if (_namgui % 4 == 0 && _namgui % 100 != 0 || _namgui % 400 == 0) {
                    if (_ngaygui > A[_thanggui])  value = false;
                    else value = true;
                }
                else {
                    A[_thanggui] = 28;
                    if (_ngaygui > A[_thanggui])  value = false;
                    else value = true;
                }
            }
            if (value == false)
                cout <<"\t\t" << "Thoi diem gui tien khong hop le !!! Yeu cau nhap lai " << endl;
        } while (value != true);

    } while (_ngaygui >current_y || (_namgui >= current_y && _thanggui > current_m ) || (_ngaygui >current_d && _thanggui >= current_m && _namgui >= current_y));

    cout <<"\t\t" <<"So tien gui vao: "; cin >>_TienGui;
    this->_Ngaytichluy = Thoigian(_ngaygui,_thanggui,_namgui);
}

void Sotietkiem::Xuat(){

    cout <<"\t\t|" <<left <<setw(5) <<this->_MaKH <<"\t";
    cout <<"|" <<left <<setw(10) <<this->_CMND <<"\t";
    cout <<"|" <<left <<setw(25) <<this->_Ten <<"\t"; 
    cout <<"|" <<left  <<_ngaygui <<"/" <<_thanggui <<"/"<<_namgui <<"\t";
    cout <<"|" <<left <<setw(10) <<this->_TienGui <<"\t" ;
    cout <<"|" <<left <<setw(13) <<this->_Ngaytichluy <<"\t";
    cout <<"|" <<left <<setw(6) <<this->_kyhan <<"\t";
    cout <<"|" <<left <<setw(12) <<this->_Laitichluy <<"\t" <<"|" <<endl;
    cout <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;

}


void Sotietkiem::Ghi(){
    fstream file;
    file.open("text1.txt",ios::app);
    file <<left <<setw(5) <<this->_MaKH <<"\t";
    file <<left <<setw(10) <<this->_CMND <<"\t";
    file <<left <<setw(25) <<this->_Ten <<"\t"; 
    file <<left <<_ngaygui <<"/" <<_thanggui <<"/" <<setw(8) <<_namgui <<"\t";
    file <<left <<setw(10) <<this->_TienGui <<"\t" ;
    file <<left <<setw(13) <<this->_Ngaytichluy <<"\t";
    file <<left <<setw(6) <<this->_kyhan <<"\t";
    file <<left <<setw(12) <<this->_Laitichluy <<"\t" <<endl;
    file.close();
}
int Sotietkiem::CMND(){
    return this->_CMND;
}

int Sotietkiem::Kyhan(){
    return this->_kyhan;
}

//              So khong ky han
void Sokhongkyhan::Nhap(){
    system("cls");
    cout <<"\n\n\t\t\t" <<"Nhap thong tin khach hang gui khong ky han :" <<endl;
	Sotietkiem::Nhap();
    this->_Laitichluy = Tinhlai();
}
unsigned int Sotietkiem::Tinhlai(){
    return 0;
}


unsigned int Sokhongkyhan::Tinhlai(){

	float laisuat = 0.015;    // 0.15%/nam
	return ((_TienGui*laisuat + 1 )*_Ngaytichluy)/360;
}
//               so co ky han
void Socokyhan::Nhap(){
    system("cls");
    cout <<"\n\n\t\t\t" << "Nhap thong tin khach hang gui tien co ky han : " <<endl;
	Sotietkiem::Nhap();
	cout <<"\t\t" <<"Nhap ky han gui tien (1,2,3,6,9,12,24,36,48,60 thang) : "; cin >> _kyhan;
    while ( _kyhan!=1 && _kyhan!=2 && _kyhan!=3 && _kyhan!=6 && _kyhan!=9 && _kyhan!=12 &&_kyhan!= 24 &&_kyhan !=36 &&_kyhan !=48 && _kyhan !=60 )
    {
        cout <<"\t\t" <<"Khong co ky han muon dang ky, yeu cau nhap lai: (1,2,3,6,9,12,24,36,48,60 thang) "; cin >>this->_kyhan;
        if(_kyhan == 1 || _kyhan == 2 || _kyhan == 3 || _kyhan == 6 || _kyhan == 9 || _kyhan == 12 || _kyhan == 24 || _kyhan == 36 || _kyhan == 48 || _kyhan == 60) break;
    }
    this->_Laitichluy = Tinhlai();
}



unsigned int Socokyhan::Tinhlai(){


    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    int current_d = now->tm_mday;    // ngày hiện tại
    int current_m = (now ->tm_mon +1);   // tháng hiện tại
    int current_y =(now->tm_year + 1900);    // năm hiện tại


    int month = this->_thanggui;
    int year = this->_namgui;
    
    for (int i = 0; i < _kyhan ; i++)
    {
        month ++ ;
        if (month > 12)
        {
            year++;
            month = 1;
        }
    }
    
    if( year < current_y || year == current_y && month < current_m || this->_ngaygui <= current_d && month == current_m && year == current_y)
    {

        float laisuat = 0;
        if(_kyhan ==1 || _kyhan == 2 || _kyhan == 3) {
            laisuat = 0.031;
            return (_TienGui*laisuat + 1)*_kyhan/12;
        }
        if(_kyhan == 6 || _kyhan == 9){
            laisuat = 0.04;
            return ( _TienGui*laisuat + 1)*_kyhan/12;
        }
        if(_kyhan == 12){
            laisuat = 0.055;
            return (_TienGui*laisuat + 1)*_kyhan/12;
        }
        if(_kyhan == 24 || _kyhan == 36 || _kyhan == 48 || _kyhan == 60 ){
            laisuat = 0.053;
            return (this->_TienGui*laisuat + 1)*_kyhan/12;
        }
        else return 0;
    }
    else return 0 ;
   
}
int Sotietkiem::Ngaytichluy(){
    return this->_Ngaytichluy;
}


void Sotietkiem::Addinfor (string ma,string ten,int cmnd,int ngay,int thang,int nam, unsigned int tien,int kyhan){
    this->_MaKH = ma;
    this->_Ten = ten;
    this->_CMND = cmnd;
    this->_ngaygui = ngay;
    this->_thanggui = thang;
    this->_namgui = nam;
    this->_TienGui = tien;
    this->_kyhan = kyhan;
    this->_Ngaytichluy = Thoigian(ngay,thang,nam);
    this->_Laitichluy = Tinhlai();
}

unsigned int Sotietkiem::Laitichluy(){
    return _Laitichluy; 
}

void Sotietkiem::operator =(const Sotietkiem& p){
    this->_MaKH = p._MaKH;
    this->_CMND =p._CMND;
    this->_Ten = p._Ten;
    this->_ngaygui =p._ngaygui;
    this->_thanggui =p._thanggui;
    this->_namgui =p._namgui;
    this->_TienGui =p._TienGui;
    this->_kyhan = p._kyhan;
    this->_Ngaytichluy = p._Ngaytichluy;
    this->_Laitichluy = p._Laitichluy;
}

int Sotietkiem::ngay(){
    return this->_ngaygui;
}
int Sotietkiem::thang(){
    return this->_thanggui;
}

int Sotietkiem::nam(){
    return this->_namgui;
}

ostream& operator<<(ostream& o , const Sotietkiem& p){
    o <<"\t\t|" <<left <<setw(5) <<p._MaKH <<"\t"
    <<"|" <<left <<setw(10) <<p._CMND <<"\t"
    <<"|" <<left <<setw(25) <<p._Ten <<"\t" 
    <<"|" <<left <<p._ngaygui <<"/" <<p._thanggui <<"/"<<p._namgui <<"\t"
    <<"|" <<left <<setw(10) <<p._TienGui <<"\t" 
    <<"|" <<left <<setw(13) <<p._Ngaytichluy <<"\t"
    <<"|" <<left <<setw(6) <<p._kyhan <<"\t"
    <<"|" <<left <<setw(12) <<p._Laitichluy <<"\t" <<"|" <<endl
    <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;
    return o;
}





