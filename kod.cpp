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
	virtual void yazdir()const{
		cout<<"öğrencinin ad - soyadı: "<<ad<<" "<<soyad<<"\nTC: "<<num<<"\nDoğum Tarihi: "<<dt<<endl;
	}
	
	void dosyayazdir(ofstream &dosya){
		dosya<<"öğrencinin ad - soyadı: "<<getad()<<" "<<getsoyad()<<"\nTC: "<<getnum()<<"\nDoğum Tarihi: "<<getdt();
		cout << "GIRILEN VERI DOSYAYA YAZILDI." << endl;
	}
};


//---------------------------------------------------------------------------------------------------------------------------------------------------


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
	
	void dersekle(){
		int x;
		cout << "Ogrenci icin ders adedi girin: ";
		cin >> x;
		for(int i = 0; i <= x; i++){
			string cu;
			getline(cin,cu);
			dersler.push_back(cu);
	}
	}
	void yazdir()const{
		kisi::yazdir();
		cout<<"Sınıfı: "<<sinif<<"\nÖğrenci No: "<<onum<<"\nDersler: ";  
		for(size_t i = 0;i<dersler.size();i++){
			cout<<dersler.at(i)<<" ";
		}
	}	
};



//---------------------------------------------------------------------------------------------------------------------------------------------------



class shoca:public kisi{
private:
	string dersadi;
	unsigned int derssaati;
	public:
		shoca(string ad,string soyad,string num,string dt,string dersadi,int derssaati):kisi(ad,soyad,num,dt),dersadi(dersadi),derssaati(derssaati){}
		~shoca(){}
		
		string getdersadi(){
			return dersadi;
		}
		unsigned int getderssaati()const{
			return derssaati;
		}
		
		virtual double maashesapla()const{
			return derssaati*50;
		}
		void yazdir()const{
		kisi::yazdir();
		cout <<"\nDersi:"<<dersadi<<"\nDers saati: "<<derssaati<<"Maaşı: "<<maashesapla()<<endl;			
		}
};

		

//---------------------------------------------------------------------------------------------------------------------------------------------------


	class hoca: public shoca{
	private:
		double tabanmaas;
	public:
		hoca(string ad,string soyad,string num,string dt,string dersadi,int derssaati,double tabanmaas):shoca(ad,soyad,num,dt,dersadi,derssaati),tabanmaas(tabanmaas){}

		double gettabanmaas(){
			return tabanmaas;
		}	
		
		double maashesapla()const{
			return tabanmaas+getderssaati()*50;
		}
		void yazdir()const{
			kisi::yazdir();
		cout<<"\nDers saati: "<<getderssaati()<<"Maaşı: "<<maashesapla()<<"\nTaban maaşı: "<<tabanmaas<<endl;
		}
	};


	void dosyaoku(ifstream &dosya){
		if (dosya)
		{
			cout<<"VERİLER DOSYADAN OKUNDU!!!!"<<endl;
			while(dosya.peek()!=EOF){
				string cu;
				getline(dosya,cu);
				cout<<cu;
			}
		}
		
	}



int main()
{
	ofstream dosya("deneme.txt");
    ogrenci o1("Ayse", "Ay", "222222222", "01.01.2000", "123456789", 7);
	o1.dersekle();
	o1.yazdir();
	o1.dosyayazdir(dosya);
	cout<<endl;


	shoca s1("Ahmet", "Ak", "333333333","12.1.2000", "Matematik", 20);
	s1.yazdir();
	s1.dosyayazdir(dosya);
	cout<<endl;


	hoca h1("Zehra", "Gun", "4444444444", "03.05.1999", "Turkce", 4, 4000);
	h1.yazdir();
	h1.dosyayazdir(dosya);
	cout<<endl;
	dosya.close();

	
	ifstream dosya2("dosya.txt");
	dosyaoku(dosya2);


    return 0;
}
