/*Trache Andrei-Daniel
GNU GCC COMPILER
Eduard Gabriel Szmeteanca
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Vaccin{
protected:

    float pret;
    float temperatura;
    string lista_substante;
    int nr_vaccine;
    string nume_producator;
    vector<Vaccin> lista_vaccine;

public:

    Vaccin(){
        this->pret = 0;
        this->temperatura = 0;
        this->nr_vaccine = 0;
        this->nume_producator = "Necunoscut";
    }
    Vaccin(float pret, float temperatura, string lista_substante, int nr_vaccine, string nume_producator){
        this->pret = pret;
        this->temperatura = temperatura;
        this->nr_vaccine = nr_vaccine;
        this->lista_substante = lista_substante;
        this->nume_producator = nume_producator;

    }

    friend ostream& operator <<(ostream &out, Vaccin &vaccin){   /// OPERATOR << PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        out << "Pretul este: " << vaccin.pret << "\n";
        out << "Temperatura este: " << vaccin.temperatura << "\n";
        out << "Lista de substante este: " << "\n";
        out << vaccin.lista_substante << "\n";
        out << "Producatorul este: " << vaccin.nume_producator << "\n";
        return out;
    };

    friend istream& operator >>(istream &in, Vaccin &vaccin){   /// OPERATOR >> PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        cout << "Pretul este: " ;
        in >> vaccin.pret;
        cout << "\n";
        cout << "Temperatura este: " ;
        in >> vaccin.temperatura;
        cout << "\n";
        cout << "Lista de substante este: \n";
        in >> vaccin.lista_substante;
        cout << "\n";
        cout << "Producatorul este: ";
        in >> vaccin.nume_producator;
        cout << "\n";
        return in;
    };

    //virtual void afisareSchemaVaccinare() = 0;

    void adaugareVaccin(Vaccin &vaccin){
        lista_vaccine.push_back(vaccin);
        this->nr_vaccine ++;
    }

    ~Vaccin(){
    }

};

class ListaVaccine{
protected:
    vector<Vaccin> lista_vaccine;
    int nr_vaccine;
public:
    ListaVaccine(){
    }
    void adaugareVaccin(Vaccin &vaccin){
        lista_vaccine.push_back(vaccin);
        this->nr_vaccine ++;
    }
    Vaccin& operator[](int index){   /// OPERATOR INDEXARE PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        if(index > this->nr_vaccine){
            cout << "nu se poate!";
        }
        return this->lista_vaccine[index];
    }
    //virtual void afisareSchemaVaccinare() = 0;

};



class VaccinAntigripal:public Vaccin{
    string tulpina_virus;
    bool recomandat_OMS;

public:

    VaccinAntigripal():Vaccin(){
        this->tulpina_virus = "Necunoscut";
        this->recomandat_OMS = false;
    }

    ///constructor preluat din proiect personal si modificat corespunzator
    VaccinAntigripal(string tulpina_virus, bool recomandat_OMS){//:Vaccin(pret, temperatura, lista_substante, nr_vaccine, nume_producator){
        this->tulpina_virus = tulpina_virus;
        this->recomandat_OMS = recomandat_OMS;
    }

    friend ostream& operator <<(ostream &out, VaccinAntigripal &vaccin){   /// OPERATOR << PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        out << (Vaccin&)vaccin;
        out << "Tulpina virusului este: " << vaccin.tulpina_virus << "\n";
        out << "Este recomandat?: " << vaccin.recomandat_OMS << "\n";
        return out;
    };



    //virtual void afisareSchemaVaccinare() = 0;

    void afisareSchemaVaccinare(){
        cout << "Se administreaza dultilor o doza de 0.5ml, iar copiilor si adolescentilor o doza de 0.3ml, repetandu-se din 2 in 2 ani.";
    }

    ~VaccinAntigripal(){
    }


};

class VaccinAntihepatic:public Vaccin{
    string tip_hepatita;
    string mod_vaccinare;

public:
    VaccinAntihepatic():Vaccin(){
        this->tip_hepatita = "Necunoscut";
        this->mod_vaccinare = "Necunoscut";
    }

    ///constructor preluat din proiect personal si modificat corespunzator
    VaccinAntihepatic(string tip_hepatita, string mod_vaccinare){//:Vaccin(pret, temperatura, lista_substante, nr_vaccine, nume_producator){
        this->tip_hepatita = tip_hepatita;
        this->mod_vaccinare = mod_vaccinare;
    }

    friend ostream& operator <<(ostream &out, VaccinAntihepatic &vaccin){   /// OPERATOR << PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        out << (Vaccin&)vaccin;
        out << "Tipul Hepatitei este: " << vaccin.tip_hepatita << "\n";
        out << "Mod vaccinare: " << vaccin.mod_vaccinare << "\n";
        return out;
    };

    //virtual void afisareSchemaVaccinare() = 0;

    void afisareSchemaVaccinare(){
        cout << "Antihepatita A si B, la copii cu varsta mai mica de 1 an se adminstreaza 2 injectari la un interval de o luna, a treia injectare dupa 6 luni de la prima administrare, la adulti conform schemei de imunizare recomandata de medic; cel Antihepatita C doar la recomandarea medicului";
    }

    ~VaccinAntihepatic(){
    }

};

class VaccinAntiSarsCov2:public Vaccin{
    string reactii_adverse;
    float rata_eficienta;
    string medicamente_contraindicate;

public:
    //virtual void afisareSchemaVaccinare() = 0;

    VaccinAntiSarsCov2():Vaccin(){
    }

    VaccinAntiSarsCov2(string reactii_adverse, float rata_eficienta, string medicamente_contraindicate):Vaccin(pret, temperatura, lista_substante, nr_vaccine, nume_producator){
        this->reactii_adverse = reactii_adverse;
        this->rata_eficienta = rata_eficienta;
        this->medicamente_contraindicate = medicamente_contraindicate;
    }

    friend ostream& operator <<(ostream &out, VaccinAntiSarsCov2& vaccin){   /// OPERATOR << PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        out << (Vaccin&)vaccin;
        out << "Reactii adverse: " << vaccin.reactii_adverse << "\n";
        out << "Medicamente contraindicate: " << vaccin.medicamente_contraindicate << "\n";
        return out;
    };

    void afisareSchemaVaccinare(){
        cout << "persoanelor cu varsta de peste 16 ani, 2 doze la 0 perioada de 21 zile";
    }

    ~VaccinAntiSarsCov2(){
    }

};

class Comanda{
    int id;
    string data;
    string nume_client;
    string vaccine;
    int nr_vaccine;
public:

    Comanda(){
        this->id = 0;
        this->nume_client = "Necunoscut";
        this->vaccine = "Necunoscut";
        this->nr_vaccine = 0;
    }
    Comanda(int id, string data, string nume_client, string vaccine, int nr_vaccine){
        this->id = id;
        this->data = data;
        this->nume_client = nume_client;
        this->vaccine = vaccine;
        this->nr_vaccine = nr_vaccine;
    }

    friend ostream& operator <<(ostream &out, Comanda& comanda){   /// OPERATOR << PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        out << "Id comanda: " << comanda.id << "\n";
        out << "Data comenzii: " << comanda.data << "\n";
        out << "Nume client: " << comanda.nume_client << "\n";
        out << "Lista vaccine: " << comanda.vaccine << "\n";
        return out;
    };

    ~Comanda(){
    }

};

class ListaComenzi{
    vector<Comanda> lista_comenzi;
    int nr_comenzi;
public:

     ListaComenzi& operator +(Comanda &comanda){   ///SUPRAINCARCARE + PRELUATA DIN PROIECT PERSONAL SI MODIFICATA
        this->nr_comenzi ++;
        lista_comenzi.push_back(comanda);
    }

    ListaComenzi& operator =(const ListaComenzi& lista){
        this->nr_comenzi = max(this->nr_comenzi, lista.nr_comenzi);
        if(this != &lista){
            for(int i = 0; i < this->nr_comenzi; i ++){
                this->lista_comenzi[i] = lista.lista_comenzi[i];
            }

        }
        return *this;
    }


    Comanda& operator[](int index){   /// OPERATOR INDEXARE PRELUAT DIN PROIECT PERSONAL SI MODIFICAT
        if(index > this->nr_comenzi){
            cout << "nu se poate!";
        }
        return this->lista_comenzi[index];
    }

};


int main()
{
    Vaccin vacc(120, 100, "dsadasdas dasdsadas", 2, "Andrei"), vacc1;
    //Vaccin* lista[3];
    VaccinAntigripal a("tulpina", true);
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;


    ListaVaccine lista;
    //cout << a;
    lista.adaugareVaccin(a);
    lista.adaugareVaccin(b);
    lista.adaugareVaccin(c);
    //cout << "\n";
    cout << lista[0];
    cin >> vacc1;
    //lista[0].afisareSchemaVaccinare();
    cout << vacc1;

    Comanda comanda1(10021, "01-01-01", "spitalx", "AntiSarsCov2", 1);
    ListaComenzi lista_comenzi;
    lista_comenzi = lista_comenzi + comanda1;
    cout << "\n";
    cout << lista_comenzi[0];

    return 0;
}
