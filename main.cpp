#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

class Bikes                   ///*************************************//BIKES//*****************************************///
{
    static int nrBiciclete;
    const int ID = rand() % INT_MAX + 1000000;
    char *bikeName;
    bool used;
    float lungime_cadru;
    char tip[105];
    double price;

public:
    Bikes(char* bikeName, bool used, float lungime_cadru, char tip[105], double price){
        this->bikeName = new char[strlen(bikeName) + 1];
        strcpy(this->bikeName, bikeName);
        this->used = used;
        this->lungime_cadru = lungime_cadru;
        strcpy(this->tip, tip);
        this->price = price;
        nrBiciclete ++;
    }
    Bikes(){
        cout << "CA SA STII S-A APELAT CONSTRUCTORUL FARA PARAMETRII  \n";
        nrBiciclete ++;
        this->used = false;
        this->lungime_cadru = 0;
        this->price = 0;
        }

    Bikes &operator =(const Bikes& bike){        ///*********************************SUPRAINCARCARE OPERATOR =***********************///

        if(this != &bike){

            this->bikeName = new char[strlen(bike.bikeName) + 1];
            strcpy(this->bikeName, bike.bikeName);
            this->used = bike.used;
            this->lungime_cadru = bike.lungime_cadru;
            strcpy(this->tip, bike.tip);
            this->price = bike.price;
        }

        return *this;

    };
    ~Bikes(){           ///***********************************DESTRUCTOR***************************///

        if(this->bikeName != NULL){

            delete []this->bikeName;
            //cout << "AM STERS NUMELE!!! \n";
        }
        this->used = 0;
        this->lungime_cadru = 0;
        this->price = 0;
    }

    void setName(char* bikeName){

        if(this->bikeName != NULL){
            delete []this->bikeName;
        }

        this->bikeName = new char[strlen(bikeName) + 1];
        strcpy(this->bikeName, bikeName);
    }


    char* getName(){
        return bikeName;
    }

    void getID(){
        cout << hex << ID;
    }

    float getLungimeCadru(){
        return lungime_cadru;
    }
    void setLungimeCadru(float lungime_cadru){
        this->lungime_cadru = lungime_cadru;
    }

    bool getUsed(){
        return used;
    }

    void setUsed(bool used){
        this->used = used;
    }

    double getPrice(){
        return this->price;
    }

    void setPrice(double price){
        this->price = price;
    }

    int getNr(){
        return nrBiciclete;
    }

    char* getTip(){
        return tip;
    }


    Bikes(const Bikes& bikee){                    ///***********************************CONSTRUCTOR COPIERE***************************///
        this->bikeName = new char[strlen(bikee.bikeName) + 1];
        strcpy(this->bikeName, bikee.bikeName);
        this->used = bikee.used;
        this->lungime_cadru = bikee.lungime_cadru;
        strcpy(this->tip, bikee.tip);
        this->price = bikee.price;

    }

    void citire(istream &in){
        char tmp[256];
        cout << "Numele Bicicletei: ";
        in >> tmp;
        this->bikeName = new char[strlen(tmp) + 1];
        strcpy(this->bikeName, tmp);
        cout << "Folosita?:";
        in >> this->used;
        cout << "lungime cadru: ";
        in >> this->lungime_cadru;
        cout << "tip bicicleta:";
        in >> this->tip;
        cout << "pret: ";
        in >> this->price;
        nrBiciclete ++;
    };

    void afisare(ostream &out){
        out << "Numele Biclei: " << this->bikeName << "\n";
        out << "Folosita?:" << this->used << "\n";
        out << "Lungime cadru: " << this->lungime_cadru << "\n";
        out << "Tip Bicla: " << this->tip << '\n';
        out << "Pret in €: " << this->price << "\n";
        out << "\n";
    }

    friend istream& operator >>(istream &in, Bikes &bike);

    friend ostream& operator <<(ostream &out, Bikes &bike);

    const Bikes operator++(int){
        this->nrBiciclete ++;
        return *this;
    }



};

class MountainStonks             ///******************************************MOUNTAIN*************************************///
{
    int nr = 0;
    double total_price = 0;
    vector<Bikes> lista;
public:

    MountainStonks(Bikes &bike){
        nr ++;
        this->total_price = bike.getPrice();
        lista.push_back(bike);
    }

    MountainStonks(){
        this->nr = 0;
        this->total_price = 0;
    }

    void addBike(Bikes &bike){
        nr ++;
        this->total_price += bike.getPrice();
        lista.push_back(bike);
    }

    void getBikes(ostream &out){
        for(int i = 0; i < nr; i ++){
            out << lista[i];
        }
    }

     void getTotalPrice(){
        cout << total_price;

    }

    friend ostream& operator <<(ostream &out, MountainStonks &mstoc){
        for(int i = 0; i < mstoc.nr; i ++){
            out << mstoc.lista[i];
        }
        return out;
    };

    MountainStonks& operator =(const MountainStonks& mstoc){
        this->nr = max(this->nr, mstoc.nr);
        this->total_price = mstoc.total_price;
        if(this != &mstoc){

            for(int i = 0; i < this->nr; i ++){
                //cout << "AM INTRAT AICIA SA STII!!!!!!";
                this->lista[i] = mstoc.lista[i];
            }

        }
        return *this;
    }

    float getPricePerBike(){

        float price_per_bike = total_price / nr;
        return price_per_bike;
    }


    MountainStonks& operator +(Bikes &bike){
        nr ++;
        this->total_price += bike.getPrice();
        lista.push_back(bike);

    }

    MountainStonks& operator >(double price){

        for(int i = 0; i < this->nr; i ++){
            if(this->lista[i].getPrice() > price){
                cout << this->lista[i];
            }

        }

    }

    MountainStonks& operator <(double price){

        for(int i = 0; i < this->nr; i ++){
            if(this->lista[i].getPrice() < price){
                cout << this->lista[i];
            }

        }

    }


};

class RoadStonks             ///******************************************ROAD*************************************///
{
    int nr = 0;
    double total_price = 0;
    vector<Bikes> lista;
public:

    RoadStonks(Bikes &bike){
        nr ++;
        this->total_price = bike.getPrice();
        lista.push_back(bike);
    }

    RoadStonks(){
        this->nr = 0;
        this->total_price = 0;
    }

    void addBike(Bikes &bike){
        nr ++;
        this->total_price += bike.getPrice();
        lista.push_back(bike);
    }

    void getBikes(ostream &out){
        for(int i = 0; i < nr; i ++){
            out << lista[i];
        }
    }

     void getTotalPrice(){
        cout << total_price;

    }

    friend ostream& operator <<(ostream &out, RoadStonks &rstoc){
        for(int i = 0; i < rstoc.nr; i ++){
            out << rstoc.lista[i];
        }
        return out;
    };

    RoadStonks& operator =(const RoadStonks& rstoc){
        this->nr = max(this->nr, rstoc.nr);
        this->total_price = rstoc.total_price;
        if(this != &rstoc){

            for(int i = 0; i < this->nr; i ++){
                //cout << "AM INTRAT AICIA SA STII!!!!!!";
                this->lista[i] = rstoc.lista[i];
            }

        }
        return *this;
    }

    float getPricePerBike(){

        float price_per_bike = total_price / nr;
        return price_per_bike;
    }


    RoadStonks& operator +(Bikes &bike){
        nr ++;
        this->total_price += bike.getPrice();
        lista.push_back(bike);

    }

    RoadStonks& operator >(double price){

        for(int i = 0; i < this->nr; i ++){
            if(this->lista[i].getPrice() > price){
                cout << this->lista[i];
            }

        }

    }

    RoadStonks& operator <(double price){

        for(int i = 0; i < this->nr; i ++){
            if(this->lista[i].getPrice() < price){
                cout << this->lista[i];
            }

        }

    }

};

class ElectricStonks             ///******************************************ELECTRIC*************************************///
{
    int nr = 0;
    double total_price = 0;
    vector<Bikes> lista;
public:

    ElectricStonks(Bikes &bike){
        nr ++;
        this->total_price = bike.getPrice();
        lista.push_back(bike);
    }

    ElectricStonks(){
        this->nr = 0;
        this->total_price = 0;
    }

    void addBike(Bikes &bike){
        nr ++;
        this->total_price += bike.getPrice();
        lista.push_back(bike);
    }

    void getBikes(ostream &out){
        for(int i = 0; i < nr; i ++){
            out << lista[i];
        }
    }

     void getTotalPrice(){
        cout << total_price;

    }

    friend ostream& operator <<(ostream &out, ElectricStonks &estoc){
        for(int i = 0; i < estoc.nr; i ++){
            out << estoc.lista[i];
        }
        return out;
    };

    ElectricStonks& operator =(const ElectricStonks& estoc){
        this->nr = max(this->nr, estoc.nr);
        this->total_price = estoc.total_price;
        if(this != &estoc){

            for(int i = 0; i < this->nr; i ++){
                //cout << "AM INTRAT AICIA SA STII!!!!!!";
                this->lista[i] = estoc.lista[i];
            }

        }
        return *this;
    }

    float getPricePerBike(){

        float price_per_bike = total_price / nr;
        return price_per_bike;
    }


    ElectricStonks& operator +(Bikes &bike){
        nr ++;
        this->total_price += bike.getPrice();
        lista.push_back(bike);

    }

    ElectricStonks& operator >(double price){

        for(int i = 0; i < this->nr; i ++){
            if(this->lista[i].getPrice() > price){
                cout << this->lista[i];
            }

        }

    }

    ElectricStonks& operator <(double price){

        for(int i = 0; i < this->nr; i ++){
            if(this->lista[i].getPrice() < price){
                cout << this->lista[i];
            }

        }

    }


};

int Bikes::nrBiciclete = 0;

class Employs
{
    const int ID = rand() % INT_MAX + 1000000;
    char* nume;
    double salariu;
    char sectie[256];
    bool friendly;
    pair<int, int> rating_from_costumers;            /// FROM 1 TO 10;
    bool privacy;

public:
    Employs(){
        cout << "SA STII CA S-A APELAT CONSTRUCTORUL DE INITIALIZARE PENTRU EMPLOYS UWU";
        this->salariu = 0;
        strcpy(this->nume, "AnOnYm");
        strcpy(this->sectie, "Undefined");
        this->friendly = false;
        this->privacy = false;
        this->rating_from_costumers.first = 0;
        this->rating_from_costumers.second = 0;
    }
    Employs(char* nume, double salariu, char sectie[256], bool friendly, pair<int, int> rating_from_costumers, bool privacy){
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        strcpy(this->sectie, sectie);
        this->salariu = salariu;
        this->friendly = friendly;
        this->rating_from_costumers.first = rating_from_costumers.first;
        this->rating_from_costumers.second = rating_from_costumers.second;
        this->privacy = privacy;
    }
    ~Employs(){
        if(this->nume != NULL){
            delete []nume;
        }
        strcpy(this->sectie, "Undefined");
        this->salariu = 0;
        this->friendly = false;
        this->rating_from_costumers.first = 0;
        this->rating_from_costumers.second = 0;
        this->privacy = false;
    }

    Employs(const Employs &nenea){
        this->nume = new char[strlen(nenea.nume) + 1];
        strcpy(this->nume, nenea.nume);
        strcpy(this->sectie, nenea.sectie);
        this->salariu = nenea.salariu;
        this->friendly = nenea.friendly;
        this->rating_from_costumers = nenea.rating_from_costumers;
        this->privacy = nenea.privacy;

    }

    friend ostream& operator<<(ostream& out, const Employs& nenea){

        out << "Nume angajat: " << nenea.nume << ";\n";
        out << "Sectie: " << nenea.sectie << ";\n";
        out << "Salariu: ";
        if(nenea.privacy == true){
            out << "**Acest angajat nu doreste sa ii fie vizualizate aceste date**;\n";
        }else{
            out << nenea.salariu << ";\n";
        }
        out << "Prietenos: " << nenea.friendly << ";\n";
        out << "Rating from costumers(from 1 to 10): ";
        if(nenea.privacy == true){
            out << "**Acest angajat nu doreste sa ii fie vizualizate aceste date**;\n";
        }else{
            out << "Nota " << nenea.rating_from_costumers.first << " din " << nenea.rating_from_costumers.second << " recenzii;\n";
        }

        return out;

    }

    friend istream& operator>> (istream& in, Employs& nenea){

        char aux[256];

        cout << "Introduceti numele Angajatului: ";
        in >> aux;

        if(nenea.nume != NULL){
            delete[] nenea.nume;
        }
        nenea.nume = new char[strlen(aux) + 1];
        strcpy(nenea.nume, aux);

        cout << "Introduceti sectia: ";
        in >> nenea.sectie;
        cout << "\n";

        cout << "Introduceti salariul: ";
        in >> nenea.salariu;
        cout << "\n";

        cout << "Este prietenos?: ";
        in >> nenea.friendly;
        cout << "\n";

        cout << "Rating: ";
        in >> nenea.rating_from_costumers.first;
        cout << "\n";

        cout << "Numarul de recenzii: ";
        in >> nenea.rating_from_costumers.second;
        cout << "\n";

    }

    Employs& operator =(const Employs& nenea){

        if(this != &nenea){
            if(this->nume != NULL)delete []this->nume;
            this->nume = new char[strlen(nenea.nume) + 1];
            strcpy(this->nume, nenea.nume);
            strcpy(this->sectie, nenea.sectie);
            this->salariu = nenea.salariu;
            this->friendly = nenea.friendly;
            this->rating_from_costumers.first = nenea.rating_from_costumers.first;
            this->rating_from_costumers.second = nenea.rating_from_costumers.second;
            this->privacy = nenea.privacy;

        }
        return *this;


    }

    bool operator ==(Employs& nenea){

        if(strcmp(this->sectie, nenea.sectie) == 0 && this->salariu == nenea.salariu && this->rating_from_costumers.first == nenea.rating_from_costumers.first){
            return true;
        }else{
            return false;
        }
    }



};

///  ***WORK IN PROGRESS**  ///
/*class Clienti{

    const int ID = rand() % INT_MAX + 1000000;
    char* nume;
    float buget;
    vector<Bikes> lista_cumparaturi;

};*/
///  ***WORK IN PROGRESS**  ///


istream& operator >>(istream &in, Bikes &bike){
    bike.citire(in);
    return in;
}

ostream& operator <<(ostream &out, Bikes &bike){
    bike.afisare(out);
    return out;
}


int main()
{
    char text[10005];
    char name[105], tip[105];
    bool used, exit = false;
    float lungime;
    double price;
    int n, comanda;

    ifstream file("file.txt");
    file >> n;

    Bikes bike1("dsadas", true, 14.2, "mountain", 9500);
    Bikes bike2("DASDASDASDASas", true, 14.2, "mountain", 9200);
    Bikes bike3(bike1);

    bike1 = bike2;


    ///bike1(bike2);     ///constructor copiere
    ///bike2++;          ///post incrementare

    MountainStonks mstoc;
    RoadStonks rstoc;
    ElectricStonks estoc;

    //Employs Gigel("Gigel", 1530, "mountain", true, make_pair(7, 10), false);
    //Employs Ionel("Ionel", 1230, "road", false, make_pair(5, 3), true);
    //Gigel = Ionel;

    //cout << Gigel << "\n";
    //cout << Ionel << "\n";
    //bool da = Gigel == Ionel;
    //cout << da;


    for(int i = 0; i < n; i ++){
        file >> name >> used >> lungime >> tip >> price;
        Bikes bike(name, used, lungime, tip, price);
        if(strcmp("mountain", tip) == 0){
            mstoc.addBike(bike);
        }else if(strcmp("road", tip) == 0){
            rstoc.addBike(bike);
        }else if(strcmp("electric", tip) == 0){
            //cout << "AM ADAUGAT!!!!!!!!" << "\n";
            estoc.addBike(bike);
        }
    }
    cout << "    ****Bun venit la fima de biciclete Andrei Trache SRL, unde gasiti biciclete exact pe gustul dumneavoastra, de la biciclete noi, pana la biciclete second-hand. You are invited to take a look: ***\n";
    while(exit == false){
        cout << "**Lista comenzi: \n";
        cout << "**______________________________________________________**\n";
        cout << "->> Apasa 1 pentru a vedea listele de stocuri disponibile; \n";
        cout << "->> Apasa 2 pentru a adauga o bicicleta in stoc; \n";
        cout << "->> Apasa 0 pentru a parasi meniul; \n";
        cout << "**______________________________________________________**\n";
        cin >> comanda;
        switch(comanda){
        case 1:{
            bool exit1 = false;
            while(exit1 == false){
                cout << "**__________________________________________________**\n";
                cout << "->> Apasa 1 pentru a vedea stocurile Mountain Bikes; \n";
                cout << "->> Apasa 2 pentru a vedea stocurile Road Bikes; \n";
                cout << "->> Apasa 3 pentru a vedea stocurile Electric Bikes; \n";
                cout << "->> Apasa 0 pentru a parasi meniul de Stocuri; \n";
                cout << "**__________________________________________________**\n";
                cin >> comanda;
                switch(comanda){
                case 1:
                    cout << "Mountain Bikes STONKS: \n";
                    cout << mstoc;
                    break;
                case 2:
                    cout << "Road Bikes STONKS: \n";
                    cout << rstoc;
                    break;
                case 3:
                    cout << "Electric Bikes STONKS: \n";
                    cout << estoc;
                    break;
                case 0:
                    exit1 = true;
                }

            }
            break;
        }
        case 2:{
            bool exitt = false;
            while(exitt == false){

                cout << "**__________________________________________________**\n";
                cout << "1 -- ADD MOUNTAIN BIKE; \n";
                cout << "2 -- ADD ROAD BIKE; \n";
                cout << "3 -- ADD ELECTRIC BIKE \n";
                cout << "->> Apasa 0 pentru a parasi meniul; \n";
                cout << "**__________________________________________________**\n";
                cin >> comanda;
                bool exit2 = false;
                //if(comanda == 0){cout << "PLMMMDMASDASD";exit2 = true;}
                while(exit2 == false){
                    switch(comanda){
                    case 1:{
                        Bikes bike;
                        cout << "Introdu Informatiile despre bicicleta mountain: \n";
                        cin >> bike;
                        mstoc + bike;
                        cout << "**Bicicleta a fost adaugata cu succes**. \n";
                        exit2 = true;
                        break;
                    }
                    case 2:{
                        Bikes bike;
                        cout << "Introdu Informatiile despre bicicleta road: \n";
                        cin >> bike;
                        rstoc + bike;
                        cout << "**Bicicleta a fost adaugata cu succes**. \n";
                        exit2 = true;
                        break;
                    }
                    case 3:{
                        Bikes bike;
                        cout << "Introdu Informatiile despre bicicleta electrica: \n";
                        cin >> bike;
                        estoc + bike;
                        cout << "**Bicicleta a fost adaugata cu succes**. \n";
                        exit2 = true;
                        break;
                    }
                    case 0:{exit2 = true; exit = false; exitt = true;}
                    }
                }
            }
            break;
            }
        case 0:{
            exit = true;
            break;}

        }
    }

    return 0;
}
