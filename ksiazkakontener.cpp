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

KontenerCardio *KsiazkaKontener::stwozKontenerCardio()
{
    auto wynik = new KontenerCardio(this);
    if(wynik!=nullptr){
        wynikWKsiazceCardio.push_back(wynik);
        wynik->setNazwaTreningu("Trening cardio");
        QDate date = QDate::currentDate();
        wynik->setDataTreninguCardio(date);
    }
    return wynik;
}

void KsiazkaKontener::skasujKontenerCardio(KontenerCardio* wpis)
{
    wynikWKsiazceCardio.removeOne(wpis);
    delete wpis;
}
