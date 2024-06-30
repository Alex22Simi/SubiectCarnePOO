#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MagazinCarne
{
	const int idProdus;
	char* tipProdus;
	string dataExpirare;
	int nrProduse;
	float* pret;
	static int nextId;
	static string tara;
public:
	MagazinCarne():idProdus(nextId++)
	{
		this->tipProdus = new char[strlen("Necunoscut") + 1];
		strcpy(this->tipProdus, "Necunoscut");
		this->dataExpirare = "30.06.2024";
		this->nrProduse = 0;
		this->pret = nullptr;
	}
	MagazinCarne( const char* tipProdus, string dataExpirare,int nrProduse,
		float* pret) :idProdus(nextId++)
	{
		this->tipProdus = new char[strlen(tipProdus) + 1];
		strcpy(this->tipProdus, tipProdus);
		this->dataExpirare = dataExpirare;
		this->nrProduse = nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < nrProduse; i++)
		{
			this->pret[i] = pret[i];
		}
	}
	//getteri
	const int getIdProdus()
	{
		return this->idProdus;
	}
	char* getTipProdus()
	{
		return this->tipProdus;
	}
	string getDataExpirare()
	{
		return this->dataExpirare;
	}
	int getNrProduse()
	{
		return this->nrProduse;
	}
	float* getPret()
	{
		
			return this->pret;
		
	}
	
	//setteri
	void setTipProdus(char* tipProdus)
	{
		if (this->tipProdus != NULL)
		{
			delete[] this->tipProdus;
		}
		this->tipProdus = new char [strlen(tipProdus) + 1];
		strcpy(this->tipProdus, tipProdus);
	}
	void setDataExpirare(string dataExpirare)
	{
		this->dataExpirare = dataExpirare;
	}
	void setNrProduse(int nrProduse)
	{
		this->nrProduse = nrProduse;
	}
	void setPret(float* pret, int nrProduse)
	{
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
		this->nrProduse = nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < nrProduse; i++)
		{
			this->pret[i] = pret[i];
		}
	}
	MagazinCarne(const MagazinCarne& m):idProdus(nextId++)
	{
		this->tipProdus = new char[strlen(m.tipProdus) + 1];
		strcpy(this->tipProdus, m.tipProdus);
		this->dataExpirare = m.dataExpirare;
		this->nrProduse = m.nrProduse;
		this->pret = new float[this->nrProduse];
		for (int i = 0; i < m.nrProduse; i++)
		{
			this->pret[i] = m.pret[i];
		}
	}
	MagazinCarne& operator=(const MagazinCarne& m)
	{
		if (this != &m)
		{
			if (this->tipProdus != NULL)
			{
				delete[]this->tipProdus;
			}
			if (this->pret != NULL)
			{
				delete[] this->pret;
			}
			this->tipProdus = new char[strlen(m.tipProdus) + 1];
			strcpy(this->tipProdus, m.tipProdus);
			this->dataExpirare = m.dataExpirare;
			this->nrProduse = m.nrProduse;
			this->pret = new float[this->nrProduse];
			for (int i = 0; i < m.nrProduse; i++)
			{
				this->pret[i] = m.pret[i];
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const MagazinCarne& m)
	{
		out << m.idProdus << endl;
		out << m.tipProdus << endl;
		out << m.dataExpirare << endl;
		out << m.nrProduse << endl;
		for (int i = 0; i < m.nrProduse; i++)
		{
			out << m.pret[i] << ", ";
		}
		out << endl;
		out << m.tara << endl;
		return out;
	}
	friend istream& operator>>(istream& in,  MagazinCarne& m)
	{
		cout << "Introduceti tipul produsului" << endl;
		char aux[256];
		in.getline(aux, 256);
		if (m.tipProdus != NULL)
		{
			delete[] m.tipProdus;
		}
		m.tipProdus = new char[strlen(aux) + 1];
		strcpy(m.tipProdus, aux);

		cout << "Introduceti data de expirare" << endl;
		in >> m.dataExpirare;

		cout << "Introduceti nr de produse" << endl;
		in >> m.nrProduse;

		cout << "Introduceti pretul" << endl;
		delete[] m.pret;
		m.pret = new float[m.nrProduse];
		for (int i = 0; i < m.nrProduse; i++)
		{
			in >> m.pret[i];
		}
		return in;
	}
	//citire fisier txt
	friend ofstream& operator<< (ofstream& out, const MagazinCarne& m)
	{
		out << m.idProdus << endl;
		out << m.tipProdus << endl;
		out << m.dataExpirare << endl;
		out << m.nrProduse << endl;
		for (int i = 0; i < m.nrProduse; i++)
		{
			out << m.pret[i] << ", ";
			
		}
		out << endl;
		out << m.tara << endl;
		return out;
	}
	//scriere fisier txt
	friend ifstream& operator>>(ifstream& in, MagazinCarne& m)
	{
		//citire char*
		in >> ws;
		char aux[100];
		in.getline(aux, 99);
		if (m.tipProdus != NULL)
		{
			delete[] m.tipProdus;
		}
		m.tipProdus = new char[strlen(aux) + 1];
		strcpy(m.tipProdus, aux);

		//citire string
		in >> ws;
		getline(in, m.dataExpirare);

		//citire numerice
		in >> m.nrProduse;

		//citire float*
		if (m.pret != NULL)
		{
			delete[] m.pret;
		}
		m.pret = new float[m.nrProduse];
		for (int i = 0; i < m.nrProduse; i++)
		{
			in >> m.pret[i];
		}
		return in;

	}



	~MagazinCarne()
	{
		if (this->tipProdus != NULL)
		{
			delete[] this->tipProdus;
		}
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
	}
	/*bool operator==( const MagazinCarne& m)
	{
		if ( this->nrProduse == m.nrProduse)
		{
			return true;
		}
		else
		{
			return false;
		}
		for (int i = 0; i < nrProduse; i++)
		{
			if (this->pret[i] == m.pret[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
	}*/
	friend bool operator==(const MagazinCarne& m1, const MagazinCarne& m2);
	//operatorul + -> sa adune 1 + obiect la nrProduse
	MagazinCarne operator+(int x)
	{
		MagazinCarne copie = *this;
		copie.nrProduse = nrProduse + x;
		return copie;
	}
	friend MagazinCarne operator+(int x,MagazinCarne& m);
	/*float operator[](int index)
	{
		if (nrProduse > 0 && index < nrProduse)
		{
			return pret[index];
		}
		else return -1;
	}*/
	float& operator[](int index)
	{
		if (nrProduse > 0 && index < nrProduse)
		{
			return pret[index];
		}
	}
};
bool operator==(const MagazinCarne& m1, const MagazinCarne& m2)
{
	if (m1.nrProduse == m2.nrProduse)
	{
		return true;
	}
	else
	{
		return false;
	}
	for (int i = 0; i < m1.nrProduse; i++)
	{
		if (m1.pret[i] == m2.pret[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
MagazinCarne operator+(int x, MagazinCarne& m)
{
	m.nrProduse += x;
	return m;

	

}

string MagazinCarne::tara("Romania");
int MagazinCarne::nextId = 1;

int main()
{
	MagazinCarne m;
	cout << m << endl;

	float pret1[] = { 23, 25, 26, 78 };
	MagazinCarne m1( "Carne proaspata", "20.07.2024", 4, pret1);
	cout << m1 << endl;
	cout << endl << endl;

	float pret2[] = { 213, 200 };
	MagazinCarne m2( "Carne congelata", "07.07.2025", 2, pret2);
	cout << m2 << endl;
	cout << endl << endl;

	float pret3[] = { 13, 20, 55 };
	MagazinCarne m3( "Peste congelat", "17.11.2025", 3, pret3);
	cout << m3 << endl;

	MagazinCarne m4(m3);
	cout << m4 << endl;

	m4 = m;
	cout << m4;

	cout << endl << endl;
	cout << m1.getNrProduse() << endl;
	for (int i = 0; i < m1.getNrProduse(); i++)
	{
		cout << m1.getPret()[i] << endl;
	}
	cout << endl << endl;
	m1.setNrProduse(5);

	float noiPreturi[] = { 23, 25, 26, 78 , 33};
	m1.setPret(noiPreturi, 5);
	cout << m1.getNrProduse() << endl;
	for (int i = 0; i < m1.getNrProduse(); i++)
	{
		cout << m1.getPret()[i] << endl;
	}

	bool var;
	bool var2;
	var = m1 == m2;
	cout << var << endl;
	var2=  m4 == m;
	cout << var2 << endl;

	cout << m1 << endl;
	m1 + 1;

	float noiPreturi2[] = { 23, 25, 26, 78 , 33, 35 };
	m1.setPret(noiPreturi2, 6);
	cout << endl << endl << endl;
	cout << m1;
	cout << endl << endl;

	cout << m1 << endl << "De aici" << endl;
	//operator+(1, m1);
	1 + m1;
	cout << m1 << endl << endl << endl;
	cout << m1[1] << endl;
	//cin >> m1;
	cout << endl << endl << endl;


	//sa se scoataa maxim de nr de produse 
	MagazinCarne vectMagazine[] = { m1, m2 , m3 };
	int nrMagazine = 3;
	int maxim = 0;
	MagazinCarne rezultat;
	for (int i = 0; i < nrMagazine; i++)
	{
		if (vectMagazine[i].getNrProduse() > maxim)
		{
			maxim = vectMagazine[i].getNrProduse();
			rezultat = vectMagazine[i];
		}
	}
	cout << rezultat << endl;
	//sa se scoata minimul din nr de produse

	/*cin >> m1;
	cout << m1;*/
	//sa se scoata minimul din nr de produse
	MagazinCarne minimVect[] = { m1, m2, m3 };
	int nrVectMin = 3;
	int minim = minimVect[0].getNrProduse();
	MagazinCarne rezultatMinim = minimVect[0];
	for (int i = 0; i < nrVectMin; i++)
	{
		if (minimVect[i].getNrProduse() < minim)
		{
			minim = vectMagazine[i].getNrProduse();
			rezultatMinim = vectMagazine[i];
		}
	}
	cout << m2 << endl;
	cout << rezultatMinim << endl;
	/*cin >> m2;
	cout << m2;*/

	ofstream f("exempluFis.txt", ios::out);
	f << m1;
	f.close();

	ifstream g("exempluFis.txt", ios::in);
	cout << "aici" << endl;
	cout << m1 << endl;
	cout << "si aici" << endl;
	g >> m1;
	cout << m1 << endl;
	g.close(); cout << endl;



	
}