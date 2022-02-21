#include <iostream>
#include <fstream>
#include "Sotietkiem.h"
#include <windows.h>
using namespace std;

class Danhsach
{
private:
    Sotietkiem *p;
    int n;
public:

    Danhsach();             
    ~Danhsach();            
    void NhapDanhSach();    
    void XuatDanhSach();     
    void Tinhtongtienlai(); 
    void Ghifile();          
    void Xoa(int );           
    int Index(int );        
    void Docfile ();           
    void Sapxep();          
    void Capnhat();          
    void Timkiem();         
    void Add(Sotietkiem* ); 
    void Xoathongtin();     

};

void Menu(Danhsach );   

void set_color( int code ) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}