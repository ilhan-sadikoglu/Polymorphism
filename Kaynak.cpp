#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Sekil { //nesnesi oluşturulamayan sanal bir sınıf
public:
	int getKenar() { 
		return kenar;
	}
	int getTaban() {
		return taban;
	}
	int getYukseklik() {
		return yukseklik;
	}
	int setTaban(int a) {
		taban = a;
	}
	int setYukseklik(int a) {
		yukseklik = a;
	}
	void setKenar(int a) {
		kenar = a;
	}
	virtual void print() = 0; //sanal olmasını sağladı
	~Sekil() = default;
protected:
	double kenar, taban, yukseklik;
	string renk;
};
class Dikdortgen : public Sekil { //Sekil sınıfından kalıtım alan bir dortgen sınıfı oluşturduk
public:
	Dikdortgen() {
		kenar = 4;
		taban = 0;
		yukseklik = 0;
	}
	Dikdortgen(int a, int b) {
		kenar = 4;
		taban = a;
		yukseklik = b;
	}
	virtual void print() {
		cout << "Bu bir Dikdortgen \n"<< "taban: " << taban << "\nyukseklik: " << yukseklik<<endl;
		cout << "alan: " << taban*yukseklik<<endl<<endl;
	}
	~Dikdortgen() = default;
};
class Kare : public Dikdortgen { //Sekil sınıfından kalıtım alan bir dortgen sınıfı oluşturduk
public:
	//constructorlarımızı yazmalıyız
	Kare() {
		kenar = 4;
		taban = 0;
		yukseklik = 0;
	}
	Kare(int a) {
		kenar = 4;
		taban = a;
		yukseklik = a;
	}
	void print() {
		cout << "Bu bir kare \n" << "taban ve yukseklik: " << taban << endl;
		cout << "alan: " << taban*yukseklik << endl << endl;
	}
	~Kare() = default;
};
class Ucgen: public Sekil { //Sekil sınıfından kalıtım alan bir üçgen sınıfı oluşturduk
public:
	Ucgen() {
		kenar = 3;
		taban = 0;
		yukseklik = 0;
	}
	Ucgen(int a, int b) {
		kenar = 3;
		taban = a;
		yukseklik = b;
	}
	virtual void print() {
		cout << "Bu bir Ucgen \n" << "taban: " << taban << "\nyukseklik: " << yukseklik << endl;
		cout << "alan: " << (taban*yukseklik)/2 << endl << endl;
	}
	~Ucgen() = default;
};
int main() {
	vector<Sekil*>dizi;
	
	Dikdortgen d1(5,7),d2(7,9);
	dizi.push_back(&d1);
	dizi.push_back(&d2);
	
	Kare k1(3), k2(4);
	dizi.push_back(&k1);
	dizi.push_back(&k2);

	Ucgen u1(6, 8);
	dizi.push_back(&u1);

	for(int i=0;i<dizi.size();i++)
		dizi[i]->print();
}