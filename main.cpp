#include <iostream>

using namespace std;

class ListaAutomobile{
protected:
    int **lista;
    string marca;
    string model;
    int nrAutomobile;
public:
    ListaAutomobile(){
        this->marca = "Necunoscut";
        this-> model = "Necunoscut";
        this->nrAutomobile ++;
    }
    ListaAutomobile(string marca, string model){
        this->marca = marca;
        this->model = model;
        this->nrAutomobile ++;
    }


};

class AutomobilUndercover: public ListaAutomobile{
    float topSpeed;
    float indiceProtectie;
public:

    AutomobilUndercover():ListaAutomobile(){
        this->topSpeed = 0;
        this->indiceProtectie = 0;

    }
    AutomobilUndercover(float topSpeed, float indiceProtectie):ListaAutomobile(marca, model){
        this->topSpeed = topSpeed;
        this->indiceProtectie = indiceProtectie;

    }


};

class AutomobilInterventie: public ListaAutomobile{
    int maxPersoane;
    int nrCartuse;
    bool boolArma;
    string arma;
public:
    AutomobilInterventie():ListaAutomobile(){
        this->maxPersoane = 0;
        this->nrCartuse = 0;
        this->boolArma = false;
        this->arma = "necunoscut";

    }
    AutomobilInterventie(int maxPersoane, int nrCartuse, bool boolArma, string arma):ListaAutomobile(marca, model){
        this->maxPersoane = maxPersoane;
        this->nrCartuse = nrCartuse;
        this->boolArma = boolArma;
        this->arma = arma;

    }


};

class AutomobilEmisieReceptie: public ListaAutomobile{
    float distantaAcustic, distantaVideo;
public:
    AutomobilEmisieReceptie():ListaAutomobile(){
        this->distantaAcustic = 0;
        this->distantaVideo = 0;

    }
    AutomobilEmisieReceptie(float distantaAcustic, float distantaVideo):ListaAutomobile(marca, model){
        this-> distantaAcustic = distantaAcustic;
        this->distantaVideo = distantaVideo;

    }

    ListaAutomobile& operator+(AutomobilEmisieReceptie automobil){
        int a[100];
        this->nrAutomobile ++;
        for(int i = 0; i < this->nrAutomobile; i ++){
            this->lista[i] = a[i];
        }
        this->lista[this->nrAutomobile - 1] = automobil;
        return *this;
    }

};


int main()
{
    ListaAutomobile *a;
    AutomobilUndercover m;
    AutomobilInterventie m1;
    AutomobilEmisieReceptie m2;

}
