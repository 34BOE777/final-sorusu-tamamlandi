/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class kisi{
    private:
    string ad,soyad,num,dt;
    public:
    kisi(){}
    kisi(string ad,string soyad,string num,string dt):ad(ad),soyad(soyad),num(num),dt(dt){}
    ~kisi(){}	
    string getad(){
	return ad;
	}
	
	string getsoyad(){
	return soyad;
	}
	
	string getnum(){
	return num;
	}
	
	string getdt(){
	return dt;
	}
	virtual void yazdir()=0;
    
};
class ogrenci:public kisi{
	private:
		string onum;
		vector <string> dersler;
		int sinif;
		public:
			ogrenci(string ad,string soyad,string num,string dt,string onum,int sinif):kisi(ad,soyad,num,dt),onum(onum),sinif(sinif){}
	
	string getonum(){
	return onum;
	}
	
	int getsinif(){
		return sinif;
	}
	
	vector<string> getdersler(){
		return dersler;
	}
	void yazdir(){
		cout<<"öğrencinin ad - soyadı: "<<getad()<<"\nTC: "<<getnum()<<"\nDoğum Tarihi: "<<getdt()<<"\nSınıfı: "<<getsinif()<<"\nDersler: "/*<<getdersler()<<endl*/;
		ifstream dosya("dosya.txt",ios::app);
		dosya<<"öğrencinin ad - soyadı: "<<getad()<<"\nTC: "<<getnum()<<"\nDoğum Tarihi: "<<getdt()<<"\nSınıfı: "<<sinif<<"\nDersler: "/*<<getdersler()*/;
		dosya.close();	
	}
			
};



int main()
{
  

    return 0;
}
