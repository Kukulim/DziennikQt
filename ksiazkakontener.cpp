#include "ksiazkakontener.h"

KsiazkaKontener::KsiazkaKontener(QObject *parent) : QObject(parent)
{

}

Kontener *KsiazkaKontener::stwozKontener()
{
    auto wynik = new Kontener(this);
    if(wynik!=nullptr){
    wynikWKsiazce.push_back(wynik);
    wynik->setNazwaTreningu("Trening silowy");
    QDate date = QDate::currentDate();
    wynik->setDataCwiczenia(date);
    dodajIloscTreningowSilowych();
    }
    return wynik;

}

void KsiazkaKontener::skasujKontener(Kontener *wpis)
{

        wynikWKsiazce.removeOne(wpis);
        delete wpis;
        usunIloscTreningowSilowych();

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
QString KsiazkaKontener::getZestawA(int miejsceWTablicy) const
{
    return zestawA[miejsceWTablicy];
}
void KsiazkaKontener::setZestawA(const QString &value, int miejsceWTablicy)
{
    zestawA[miejsceWTablicy]=value;
}
QString KsiazkaKontener::getZestawB(int miejsceWTablicy) const
{
    return zestawB[miejsceWTablicy];
}
void KsiazkaKontener::setZestawB(const QString &value, int miejsceWTablicy)
{
    zestawB[miejsceWTablicy]=value;
}
char KsiazkaKontener::getWyznacznikZestawuCwiczen() const
{
    return wyznacznikZestawuCwiczen;
}

void KsiazkaKontener::setWyznacznikZestawuCwiczen(char value)
{
    wyznacznikZestawuCwiczen = value;
}

void KsiazkaKontener::dodajIloscTreningowSilowych()
{
    iloscTreningowSilowych++;
}

void KsiazkaKontener::usunIloscTreningowSilowych()
{
    iloscTreningowSilowych--;
}
