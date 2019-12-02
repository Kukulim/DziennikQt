#include "ksiazkakontener.h"

KsiazkaKontener::KsiazkaKontener(QObject *parent) : QObject(parent)
{

}

Kontener *KsiazkaKontener::stwozKontener()
{
    auto wynik = new Kontener(this);
    if(wynik!=nullptr){
    wynikWKsiazce.push_back(wynik);
    emit kontenerStworzony(wynik);
    wynik->setNazwaTreningu("Trening silowy");
    QDate date = QDate::currentDate();
    wynik->setDataCwiczenia(date);
    }
    return wynik;

}

void KsiazkaKontener::skasujKontener(Kontener *wpis)
{
        emit kontenerUsuniety();
        wynikWKsiazce.removeOne(wpis);
        delete wpis;

}
