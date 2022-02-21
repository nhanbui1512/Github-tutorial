#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include <fstream>

using namespace std;

class Sotietkiem
{
public:
	Sotietkiem();
	~Sotietkiem();
	virtual void Ghi();
	virtual void Nhap();
	virtual void Xuat();
	virtual unsigned int Tinhlai();

	int CMND();
	int Kyhan();
	int Ngaytichluy();
	virtual void Addinfor (string, string, int, int ,int ,int ,unsigned int ,int);
	unsigned int Laitichluy();
	int ngay();
	int thang();
	int nam();

	void operator =(const Sotietkiem& );	
	friend ostream& operator<<(ostream& , const Sotietkiem& );
	friend istream& operator>>(istream& , const Sotietkiem& );
	friend int Thoigian();	

protected:
	string _MaKH;	
	string _Ten;
	int _CMND;
	unsigned int _TienGui;
	int _ngaygui,_thanggui,_namgui;
	unsigned int _Laitichluy;
	int _Ngaytichluy;
	int _kyhan;
	
	
};

class Socokyhan: public Sotietkiem
{
	
public:
	virtual void Nhap();
	unsigned int Tinhlai();
};

class Sokhongkyhan : public Sotietkiem{
		
	public:
		virtual void Nhap();
		unsigned int Tinhlai();
		
};
int Thoigian (int ,int ,int );

