#include "ksiazkakontener.h"

#include <QMessageBox>

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

int KsiazkaKontener::getIloscTreningowSilowych() const
{
    return iloscTreningowSilowych;
}

int KsiazkaKontener::getObjetoscWszystkichTreningowSilowych() const
{
    return objetoscWszystkichTreningowSilowych;
}

void KsiazkaKontener::setObjetoscWszystkichTreningowSilowych()
{
    int wynik=0;
    for(int i=0;i<wynikWKsiazce.size();i++)
    {
        wynik+=wynikWKsiazce[i]->getObjetoscTreningu();
    }
    objetoscWszystkichTreningowSilowych=wynik;


}

int KsiazkaKontener::getCzasWszystkichSpacerow() const
{
    return czasWszystkichSpacerow/60;
}

double KsiazkaKontener::getDydtansWszystkichSpacerow() const
{
    return dydtansWszystkichSpacerow;
}

int KsiazkaKontener::getCzasWszystkichRowerow() const
{
    return czasWszystkichRowerow/60;
}

double KsiazkaKontener::getDydtansWszystkichRowerow() const
{
    return dydtansWszystkichRowerow;
}

int KsiazkaKontener::getCzasWszystkichPlywan() const
{
    return czasWszystkichPlywan/60;
}

double KsiazkaKontener::getDydtansWszystkichPlywan() const
{
    return dydtansWszystkichPlywan;
}

int KsiazkaKontener::getCzasWszystkichTreningowCardio() const
{
    return czasWszystkichTreningowCardio/60;
}

double KsiazkaKontener::getDydtansWszystkichTreningowCardio() const
{
    return dydtansWszystkichTreningowCardio;
}
int KsiazkaKontener::getCzasWszystkichBiegow() const
{
    return czasWszystkichBiegow/60;
}

double KsiazkaKontener::getDydtansWszystkichBiegow() const
{
    return dydtansWszystkichBiegow;
}

void KsiazkaKontener::setDydtansWszystkichRodzaji()
{
    double wynikBieganie=0;
    double wynikSpacer=0;
    double wynikRower=0;
    double wynikPlywanie=0;
    int czasBiegow=0;
    int czasSpacerow=0;
    int czasRowerow=0;
    int czasPlywan=0;
    for(int i=0;i<wynikWKsiazceCardio.size();i++)
    {
        if(wynikWKsiazceCardio[i]->getRodzajTreninguCardio()=="Bieganie")
        {
            wynikBieganie+=wynikWKsiazceCardio[i]->getDystansTreninguCardio();
            czasBiegow+=QTime(0, 0, 0).secsTo(wynikWKsiazceCardio[i]->getCzasTreninguCardio());
        }
        if(wynikWKsiazceCardio[i]->getRodzajTreninguCardio()=="Spacer")
        {
            wynikSpacer+=wynikWKsiazceCardio[i]->getDystansTreninguCardio();
            czasSpacerow+=QTime(0, 0, 0).secsTo(wynikWKsiazceCardio[i]->getCzasTreninguCardio());
        }
        if(wynikWKsiazceCardio[i]->getRodzajTreninguCardio()=="Jazda na rowerze")
        {
            wynikRower+=wynikWKsiazceCardio[i]->getDystansTreninguCardio();
            czasRowerow+=QTime(0, 0, 0).secsTo(wynikWKsiazceCardio[i]->getCzasTreninguCardio());
        }
        if(wynikWKsiazceCardio[i]->getRodzajTreninguCardio()=="Plywanie")
        {
            wynikPlywanie+=wynikWKsiazceCardio[i]->getDystansTreninguCardio();
            czasPlywan+=QTime(0, 0, 0).secsTo(wynikWKsiazceCardio[i]->getCzasTreninguCardio());
        }
        dydtansWszystkichBiegow=wynikBieganie;
        dydtansWszystkichSpacerow=wynikSpacer;
        dydtansWszystkichRowerow=wynikRower;
        dydtansWszystkichPlywan=wynikPlywanie;
        dydtansWszystkichTreningowCardio=wynikRower+wynikSpacer+wynikBieganie+wynikPlywanie;

        czasWszystkichBiegow=czasBiegow;
        czasWszystkichSpacerow=czasSpacerow;
        czasWszystkichRowerow=czasRowerow;
        czasWszystkichPlywan=czasPlywan;
        czasWszystkichTreningowCardio=czasWszystkichBiegow+czasWszystkichPlywan+czasWszystkichRowerow+czasWszystkichSpacerow;
    }
}
void KsiazkaKontener::readFromFile(const QString &fileName)
{


    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QVector<Kontener>nowy;
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_5);

    //in >> nowy; TODO

}

void KsiazkaKontener::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_5);
    out << wynikWKsiazce;
}

