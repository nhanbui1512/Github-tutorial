#include "Danhsach.h"

using namespace std;

Danhsach::Danhsach()
{
    this->p = nullptr;
    this->n = 0;
}

Danhsach::~Danhsach()
{
    delete [] this-> p;
}

void Danhsach::Add(Sotietkiem *s){

    
    if(this->n == 0) {
        this-> p = new Sotietkiem[this->n+1];
        *(this->p + this->n) = *s;
    }
    else{
        Sotietkiem *temp = new Sotietkiem[this->n];
        for(int i=0;i<this->n;i++){
            *(temp + i) = *(this->p + i);
        }
        delete [] this->p;
        this->p = new Sotietkiem[this->n + 1];
        for(int i=0;i<this->n;i++){
            *(this->p + i) = *(temp + i);
        }
        *(this->p + this->n) = *s;
        delete [] temp;
    }
     this->n++;
}

void Danhsach::XuatDanhSach(){
    

    int choose;
	do
	{
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t\t\t\t\t\t\t" <<    "MENU XUAT CAC LOAI SO TIET KIEM"<<endl<<endl;
		cout<<"\t\t\t\t\t" <<"                  *************************************************" <<endl;
		cout<<"\t\t\t\t\t" <<"                  *        1.XUAT SO KHONG KY HAN.                *" <<endl;
		cout<<"\t\t\t\t\t" <<"                  *        2.XUAT SO CO KY HAN.                   *" <<endl;
		cout<<"\t\t\t\t\t" <<"                  *        3.XUAT TAT CA SO TIET KIEM.            *" <<endl;
		cout<<"\t\t\t\t\t" <<"                  *        4.QUAY LAI!                            *" <<endl;
		cout<<"\t\t\t\t\t" <<"                  *************************************************" <<endl;
		cout<<"\t\t\t\t\t\t\t"<<"  Bam so : ";
		cin >>choose;
		switch (choose)
		{
		case 1: {
			system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t\t\t" <<"THONG TIN CAC SO TIET KIEM KHONG KY HAN"<<endl;
			cout <<"\t\t._______________________________________________________________________________________________________________________________." <<endl;
			cout <<"\t\t|" <<left <<setw(5)  <<"Ma KH" <<"\t";
			cout <<"|" <<left <<setw(10) <<"CMND" <<"\t";
			cout <<"|" <<left <<setw(25) <<"Ho va Ten" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Ngay lam so" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Tien gui" <<"\t";
			cout <<"|" <<left <<setw(13) <<"Ngay tich luy" <<"\t";
			cout <<"|" <<left <<setw(6) <<"Ky han" <<"\t";
			cout <<"|" <<left <<setw(12) <<"Lai tich luy" <<"\t" <<"|" <<endl;
			cout <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;
            
			unsigned int sum = 0;
			int dem = 0;
			for(int i = 0;i<this->n;i++) {
				if((this->p+i)->Kyhan() == 0 ){
				(this->p+i)->Xuat();
				sum += (this->p+i)->Laitichluy();
				dem++;
				}
			}
			cout <<"\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |"<<endl;
			cout <<"\t\t|\t\t\t\t\t\tTONG TIEN LAI : "<<setw(10) <<left << sum <<" VND   \t\t\t\t\t        | "<<endl;
			cout <<"\t\t|_______________________________________________________________________________________________________________________________|" <<endl;
			cout <<"\n\t\t\t\t\t\t\t"<<"    TONG CONG CO: " <<dem <<" SO KHONG KY HAN" <<endl;

			system("pause");
		}
			break;	
		
		case 2: {
			system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t\t\t" <<"THONG TIN CAC SO TIET KIEM CO KY HAN"<<endl;
			cout <<"\t\t._______________________________________________________________________________________________________________________________." <<endl;
			cout <<"\t\t|" <<left <<setw(5)  <<"Ma KH" <<"\t";
			cout <<"|" <<left <<setw(10) <<"CMND" <<"\t";
			cout <<"|" <<left <<setw(25) <<"Ho va Ten" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Ngay lam so" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Tien gui" <<"\t";
			cout <<"|" <<left <<setw(13) <<"Ngay tich luy" <<"\t";
			cout <<"|" <<left <<setw(6) <<"Ky han" <<"\t";
			cout <<"|" <<left <<setw(12) <<"Lai tich luy" <<"\t" <<"|" <<endl;
			cout <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;
            unsigned int sum = 0;
			int dem = 0;

			for(int i = 0;i<this->n;i++){
				if((this->p +i)->Kyhan() != 0 ){
					(this->p + i)->Xuat();
					sum += (this->p + i)->Laitichluy();
					dem++;
				}
			}
			cout <<"\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |"<<endl;
			cout <<"\t\t|\t\t\t\t\t\tTONG TIEN LAI : " <<setw(10) <<left << sum <<" VND   \t\t\t\t\t        | "<<endl;
			cout <<"\t\t|_______________________________________________________________________________________________________________________________|" <<endl;
			cout <<"\n\t\t\t\t\t\t\t"<<"    TONG CONG CO: " <<dem <<" SO CO KY HAN" <<endl;

			system("pause");
		}
			break;
		
		case 3: {
			system("cls");
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t\t\t" <<"THONG TIN TAT CA CAC SO TIET KIEM "<<endl;
			cout <<"\t\t._______________________________________________________________________________________________________________________________." <<endl;
			cout <<"\t\t|" <<left <<setw(5)  <<"Ma KH" <<"\t";
			cout <<"|" <<left <<setw(10) <<"CMND" <<"\t";
			cout <<"|" <<left <<setw(25) <<"Ho va Ten" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Ngay lam so" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Tien gui" <<"\t";
			cout <<"|" <<left <<setw(13) <<"Ngay tich luy" <<"\t";
			cout <<"|" <<left <<setw(6) <<"Ky han" <<"\t";
			cout <<"|" <<left <<setw(12) <<"Lai tich luy" <<"\t" <<"|" <<endl;
			cout <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;
			set_color(10);
			for (int i = 0; i < this->n; i++)
			{
				if((this->p+ i)->Kyhan() == 0) (this->p +i)->Xuat();
			}
			set_color(11);
			for (int i = 0; i < this->n; i++)
			{
				if((this->p+i)->Kyhan() != 0) (this->p +i)->Xuat();
			}
			set_color(7);	
			cout <<"\n\t\t\t\t\t\t\t"<<"TONG CONG CO TAT CA " <<this->n <<" SO TIET KIEM" <<endl;
			system("pause");
		}
			break;
		
		default:
			break;
		}

	} while (choose!=4);
}

void Danhsach::NhapDanhSach()
{
	int choose ;
	Sotietkiem* sotietkiem;
	do
	{
		system("cls");
		cout <<endl<<endl;
		cout <<"\t\t\t\t\t\t\t\t" <<"MENU THEM CAC LOAI SO TIET KIEM"<<endl<<endl;
		cout <<"\t\t\t\t\t" <<"                *************************************************" <<endl;
		cout <<"\t\t\t\t\t" <<"                *        1.THEM SO CO KY HAN.                   *" <<endl;
		cout <<"\t\t\t\t\t" <<"                *        2.THEM SO KHONG KY HAN.                *" <<endl;
		cout <<"\t\t\t\t\t" <<"                *        3.QUAY LAI!                            *" <<endl;
		cout <<"\t\t\t\t\t" <<"                *************************************************" <<endl;
        cout <<"\t\t\t\t\t\t\t"<<"Bam so : ";
		cin>>choose;
		switch (choose)
		{
		case 1:
			{
				sotietkiem=new Socokyhan;
				sotietkiem->Nhap();
				Add(sotietkiem);
			}
			break;
		case 2:
			{
				sotietkiem=new Sokhongkyhan;
				sotietkiem->Nhap();
				Add(sotietkiem);
			}
			break;
		default:
			break;
		}
	} while (choose!=3);
}

void Danhsach::Docfile() {
	string _ma,_ten;
	int _cmnd,_ngay,_thang,_nam, _kyhan;
	unsigned int _tien;
	fstream myfile;
	Sotietkiem* sotietkiem;
	int n;
	myfile.open("source.txt",ios::in);	
	myfile >> n;
	for(int i = 0;i < n;i++){
		myfile >> _ma >> _ten >>_cmnd >>_ngay >>_thang >>_nam >>_tien >>_kyhan;
		if(_kyhan == 0 ){
			sotietkiem = new Sokhongkyhan;
			sotietkiem->Addinfor(_ma,_ten,_cmnd,_ngay,_thang,_nam,_tien,_kyhan);
			Add(sotietkiem);
		}
		else{
			sotietkiem = new Socokyhan;
			sotietkiem->Addinfor(_ma,_ten,_cmnd,_ngay,_thang,_nam,_tien,_kyhan);
			Add(sotietkiem);
		}
	}
	myfile.close();	
	std::cout <<"\n\t\t\t\t\t\t\t    DOC DU LIEU TU FILE THANH CONG." <<endl;
	system("pause>pls");

}

void Danhsach::Tinhtongtienlai()
{
	system("cls");
	unsigned int S = 0;
	for(int i=0; i<this->n;i++)
	{
		S+= (this->p +i)->Laitichluy();
	}
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t" <<"   THONG TIN TAT CA CAC SO TIET KIEM "<<endl;
			cout <<"\t\t._______________________________________________________________________________________________________________________________." <<endl;
			cout <<"\t\t|" <<left <<setw(5)  <<"Ma KH" <<"\t";
			cout <<"|" <<left <<setw(10) <<"CMND" <<"\t";
			cout <<"|" <<left <<setw(25) <<"Ho va Ten" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Ngay lam so" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Tien gui" <<"\t";
			cout <<"|" <<left <<setw(13) <<"Ngay tich luy" <<"\t";
			cout <<"|" <<left <<setw(6) <<"Ky han" <<"\t";
			cout <<"|" <<left <<setw(12) <<"Lai tich luy" <<"\t" <<"|" <<endl;
			cout <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;
			int tem;
			for (int i = 0; i < this->n; i++)
			{
				(this->p + i)->Xuat();
			}
			cout <<"\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |"<<endl;
			cout <<"\t\t|\t\t\t\t\t\tTONG TIEN LAI : " <<setw(10) <<left << S <<" VND   \t\t\t\t\t        |"<<endl;
			cout <<"\t\t|_______________________________________________________________________________________________________________________________|" <<endl;
	system("pause>pls");

}

int Danhsach::Index( int cmnd ){
	int i = 0 ;
	while (i < this->n){
		if(cmnd == (this->p+ i)->CMND()) {
			break;
		}	
		else i++;	
	}
	return i;
	
}

void Danhsach::Ghifile(){
	fstream file;
    file.open("text1.txt",ios::out);

	file <<left <<setw(5)  <<"Ma KH" <<"\t";
	file <<left <<setw(10) <<"CMND" <<"\t";
	file <<left <<setw(25) <<"Ho va Ten" <<"\t";
	file <<left <<setw(13) <<"Ngay lam so" <<"\t";
	file <<left <<setw(10) <<"Tien gui" <<"\t";
	file <<left <<setw(13) <<"Ngay tich luy" <<"\t";
	file <<left <<setw(6) <<"Ky han" <<"\t";
	file <<left <<setw(12) <<"Lai tich luy" <<"\t" <<endl;
	file.close();

	for(int i=0;i< this->n ;i++)
	{
		if((this->p + i)->Kyhan()==0) {
			(this->p + i)->Ghi();
		}

	}

	file.open("text1.txt",ios::app);
	file <<"\n";
	file.close();

	for(int i=0;i< this->n ;i++)
	{
		if((this->p + i)->Kyhan()!=0) {
			(this->p + i)->Ghi();
		}
	}
	file.open("text1.txt",ios::app);
	file <<endl <<"\t\t\t\t\t\t\tTong cong: " << this->n  <<" so tiet kiem " <<endl;
	file.close();
	cout <<"\t\t\t\t\t\t\tXUAT THONG TIN RA FILE THANH CONG." <<endl;
	system("pause");
	
}

void Danhsach::Xoa(int index){
    
    if(index >=0){
        if(this->n == 1){
            delete [] p;
            this->p = nullptr;
        }
        else{
            Sotietkiem *temp = new Sotietkiem[this->n];
            for (int i = 0; i < this->n; i++)
            {
                *(temp + i) = *(this->p + i) ;
            }
            delete [] this->p ;
            this->p = new Sotietkiem[this->n-1];
            for (int i = 0; i < this->n-1 ;i++)
            {
                if(i<index) *(this->p +i) = *(temp + i);
                else *(this->p + i) = *(temp + i + 1);
            }
            delete [] temp;
        }
        this->n--;
    }
}

void Danhsach::Capnhat(){
	int cmnd;
	cout <<"\t\t\t\tNhap vao CMND Khach hang muon cap nhat thong tin: "; cin  >> cmnd;
	if( Index(cmnd) == this->n ) {
		cout <<"\t\t\t\tKhong tim thay khach hang can cap nhat" <<endl;
	} 
	else
	{
		(this->p + Index(cmnd))->Nhap();
		cout <<"\t\t\t\tCap nhat thanh cong! " <<endl;
	}
	
}

void Danhsach::Timkiem(){
	int choose;
	int cmnd;
	int day,month,year;
	do
	{	system("cls");
		cout <<endl <<endl <<endl;
		cout <<"\t\t\t\tTIM KIEM SO TIET KIEM " <<endl;
		cout <<"\t\t\t\t1.TIM KIEM THEO CMND" <<endl;
		cout <<"\t\t\t\t2.TIM KIEM THEO NGAY THANG NAM" <<endl;
		cout <<"\t\t\t\t3.THOAT" <<endl;
		cout <<"\t\t\t\t" <<"Bam so: ";
		cin >>choose;
		switch (choose)
		{
		case 1:
		
			cout <<"\t\t\t\tNhap CMND: "; cin >> cmnd;
			cout <<"\t\t._______________________________________________________________________________________________________________________________." <<endl;
			cout <<"\t\t|" <<left <<setw(5)  <<"Ma KH" <<"\t";
			cout <<"|" <<left <<setw(10) <<"CMND" <<"\t";
			cout <<"|" <<left <<setw(25) <<"Ho va Ten" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Ngay lam so" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Tien gui" <<"\t";
			cout <<"|" <<left <<setw(13) <<"Ngay tich luy" <<"\t";
			cout <<"|" <<left <<setw(6) <<"Ky han" <<"\t";
			cout <<"|" <<left <<setw(12) <<"Lai tich luy" <<"\t" <<"|" <<endl;
			cout <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;
			
			for (int i = 0; i < this->n; i++)
			{	
				if((this->p +i)->CMND() == cmnd ){

					(this->p +i)->Xuat();
				}
			}
			system("pause");
			
			break;
		case 2:
			cout <<"\t\t\t\tNHAP THOI DIEM " <<endl;
			cout <<"\t\t\t\tNgay: "; cin >>day;
			cout <<"\t\t\t\tThang: "; cin >>month;
			cout <<"\t\t\t\tNam: "; cin >>year;
			cout <<"\t\t._______________________________________________________________________________________________________________________________." <<endl;
			cout <<"\t\t|" <<left <<setw(5)  <<"Ma KH" <<"\t";
			cout <<"|" <<left <<setw(10) <<"CMND" <<"\t";
			cout <<"|" <<left <<setw(25) <<"Ho va Ten" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Ngay lam so" <<"\t";
			cout <<"|" <<left <<setw(10) <<"Tien gui" <<"\t";
			cout <<"|" <<left <<setw(13) <<"Ngay tich luy" <<"\t";
			cout <<"|" <<left <<setw(6) <<"Ky han" <<"\t";
			cout <<"|" <<left <<setw(12) <<"Lai tich luy" <<"\t" <<"|" <<endl;
			cout <<"\t\t|_______|_______________|_______________________________|_______________|_______________|_______________|_______|_______________|" <<endl;
			
			for (int i = 0; i < this->n; i++)
			{
				if((this->p +i)->ngay() == day && (this->p +i)->thang()==month && (this->p +i)->nam()==year ){
					(this->p +i)->Xuat();
				}
			}
			system("pause");
			break;
		
		default:
			break;
		}
		
	} while (choose !=3);
	
	system("cls");

}

void Danhsach::Xoathongtin(){
	int choose;
	do
	{
		system("cls");
		cout <<"\n\n\t\t\t==========XOA THONG TIN KHACH HANG==========" <<endl <<endl;
		cout <<"\t\t1.XOA THEO CMND " <<endl;
		cout <<"\t\t2.XOA TAT CA SO TIET KIEM" <<endl;
		cout <<"\t\t3.THOAT" <<endl;
		cout <<"\t\tBam so : ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			int _cmnd;	
			cout <<"\n\n\t\tNhap CMND khach hang can tim: "; cin >> _cmnd;

			if( Index(_cmnd) == this->n ){
				cout <<"\n\t\tKhong co khach hang can tim !!!" <<endl;
				system("pause>pls");
			}
			else {
			Xoa(Index(_cmnd));
			cout <<"\n\t\tXoa thanh cong so co cung cmnd. " <<endl;
			system("pause>pls");
			}
			break;
		case 2:
			int sum;
			sum = this->n;
			for (int i = 0; i < sum; i++)
			{
				Xoa(i);
			}
			cout <<"\n\t\tXoa thanh cong tat ca so tiet kiem. " <<endl;
			system("pause>pls");
			break;
		default:
			break;
		}

	} while (choose!=3);
}

void swap(Sotietkiem *a, Sotietkiem *b){
        Sotietkiem doi;
        doi=*a;
        *a=*b;
       *b=doi;
}

void Danhsach::Sapxep(){
	int choose;
	do
	{	
		system("cls");
		cout <<"\n\n\n";
		cout <<"\t\t1.SAP XEP THEO LAI TICH LUY" <<endl;
		cout <<"\t\t2.SAP XEP THEO THOI GIAN" <<endl;
		cout <<"\t\t3.THOAT" <<endl;
		cin >>choose; 
		switch (choose)
		{
		case 1: // sap xep theo lai tich luy
			int choose1;
			do
			{	
				system("cls");
				cout <<"\n\n\n";
				cout <<"\t\t1.SAP XEP TANG DAN" <<endl;
				cout <<"\t\t2.SAP XEP GIAM DAN" <<endl;
				cout <<"\t\t3.BACK" <<endl;

				cin >> choose1;
				switch (choose1)
				{
				case 1: // sap xep tang dan

					for (int i=0; i< this->n -1 ; i++){
            			for (int j=i+1; j< this->n; j++){
                			if ((this->p+i)->Laitichluy() > (this->p + j)->Laitichluy() ) swap((p+i),(p+j));
            			}
        			}
					cout <<"\t\t\tSAP XEP THANH CONG!" <<endl;
					system("pause");
					break;

				case 2: // sap xep giam dan 
				
					for (int i=0; i< this->n -1 ; i++){
            			for (int j=i+1; j< this->n; j++){
                			if ((this->p+i)->Laitichluy() < (this->p + j)->Laitichluy() ) swap((p+i),(p+j));
            			}
        			}
					cout <<"\t\t\tSAP XEP THANH CONG!" <<endl;
					system("pause");

					break;
				
				default:
					break;
				}

			} while (choose1 !=3);

			break;
		case 2: // sap xep theo thoi gian
			int choose2;
			do
			{	
				system("cls");
				cout <<"\n\n\n";
				cout <<"\t\t1.SAP XEP TANG DAN" <<endl;
				cout <<"\t\t2.SAP XEP GIAM DAN" <<endl;
				cout <<"\t\t3.BACK" <<endl;

				cin >> choose2;
				switch (choose2)
				{
				case 1: // sap xep tang dan
					for (int i=0; i< this->n -1 ; i++){
            			for (int j=i+1; j< this->n; j++){
                			if ((this->p+i)->Ngaytichluy() > (this->p + j)->Ngaytichluy() ) swap((p+i),(p+j));
            			}
        			}
					cout <<"\t\t\tSap xep thanh cong!" <<endl;
					system("pause");

					break;
				case 2: // sap xep giam dan 
					for (int i=0; i< this->n -1 ; i++){
            			for (int j=i+1; j< this->n; j++){
                			if ((this->p+i)->Ngaytichluy() < (this->p + j)->Ngaytichluy() ) swap((p+i),(p+j));
            			}
        			}
					cout <<"\t\t\tSap xep thanh cong!" <<endl;
					system("pause");
					break;
				
				default:
					break;
				}

			} while (choose2 !=3);
			
			break;

		default:
		break;
		}

	} while (choose != 3);
	
	
}



void Menu(Danhsach nganhang)
{
	int choose;
	do
	{	set_color(7);
		system("cls");
		cout<<endl<<endl;
		cout <<"\t\t\t\t\t" << "        ||========================================================================||" <<endl;
    	cout <<"\t\t\t\t\t" << "        ||                                                                        ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        ||                       DO AN CO SO LAP TRINH                            ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        || Sinh vien thuc hien:                                                   ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        ||  +Mai Van Pho                                                          ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        ||  +Bui Thien Nhan                                                       ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        || Ten do an: Danh sach quan ly so tiet kiem ngan hang                    ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        || Giang vien huong dan: Nguyen Van Nguyen                                ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        ||                                                                        ||" <<endl;
    	cout <<"\t\t\t\t\t" << "        ||========================================================================||" <<endl;
		cout <<endl <<endl<<endl ;

		cout<<"\t\t\t\t" <<"                            *************************************************" <<endl;
		cout<<"\t\t\t\t" <<"                            *        1.THEM SO TIET KIEM                    *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        2.XUAT DANH SACH SO TIET KIEM          *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        3.TINH TONG TIEN LAI CAN TRA           *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        4.DOC FILE                             *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        5.XUAT RA FILE                         *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        6.XOA                                  *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        7.CAP NHAT                             *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        8.SAP XEP                              *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        9.TIM KIEM                             *" <<endl;
		cout<<"\t\t\t\t" <<"                            *        10.THOAT                               *" <<endl;
		cout<<"\t\t\t\t" <<"                            *************************************************" <<endl;
        cout<<"\t\t\t\t\t\t\t" <<"    Bam so : ";
		cin>>choose;
		switch (choose)
		{
		case 1:
			nganhang.NhapDanhSach();
			break;
		case 2:
			nganhang.XuatDanhSach();
			break;
		case 3:
			nganhang.Tinhtongtienlai();
			break;
		case 4:
			nganhang.Docfile();
			break;	
		case 5:
			nganhang.Ghifile();
			break;
		case 6:
			nganhang.Xoathongtin();
			break;
		case 7:
			system("cls");
			nganhang.Capnhat();
			system("pause");
			break;
		case 8:
			nganhang.Sapxep();	
			break;
		case 9:
			nganhang.Timkiem();	
			break;

		default:
			break;
		}
	} while (choose!=10);

}



int main(){
	Danhsach nganhang;
	Menu(nganhang);
    system("cls");
    return 0 ;
}

