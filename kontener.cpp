#include "kontener.h"
#include <QDebug>

Kontener::Kontener(QObject *parent) : QObject(parent)
{
    qDebug()<<"stworzony";
}

Kontener::~Kontener()
{
    qDebug()<<"usuniety";
}

QString Kontener::getNazwaTreningu() const
{
    return nazwaTreningu;
}

void Kontener::setNazwaTreningu(const QString &value)
{
    nazwaTreningu = value;
}

QDate Kontener::getDataCwiczenia() const
{
    return dataCwiczenia;
}

void Kontener::setDataCwiczenia(const QDate &value)
{
    dataCwiczenia = value;
}

QString Kontener::getNazwaCwiczenia(const int miejsceWTablicy) const
{
    return nazwaCwiczenia[miejsceWTablicy];
}

void Kontener::setNazwaCwiczenia(const QString &value, int miejsceWTablicy)
{
    nazwaCwiczenia[miejsceWTablicy]=value;
}

int Kontener::getIloscSerii(int miejsceWTablicy) const
{
    return iloscSerii[miejsceWTablicy];
}

void Kontener::setIloscSerii(const int &value, int miejsceWTablicy)
{
    iloscSerii[miejsceWTablicy]=value;
}

int Kontener::getIloscPowtorzen(int miejsceWTablicy) const
{
    return iloscPowtorzen[miejsceWTablicy];
}

void Kontener::setIloscPowtorzen(const int &value, const int miejsceWTablicy)
{
    iloscPowtorzen[miejsceWTablicy]=value;
}

int Kontener::getCiezar(int miejsceWTablicy) const
{
    return ciezar[miejsceWTablicy];
}

void Kontener::setCiezar(const int &value, const int miejsceWTablicy)
{
    ciezar[miejsceWTablicy]=value;
}

int Kontener::getObjetoscTreningu() const
{
    return objetoscTreningu;
}

void Kontener::setObjetoscTreningu()
{
    for (int i = 0; i<12 ;++i)
    {
        objetoscTreningu+=getObjetoscCwiczenia(i);
    }
}

bool Kontener::getCzyZaliczone(int miejsceWTablicy) const
{
    if (czyZaliczone[miejsceWTablicy]==true)
        return true;
    else
        return false;
}

void Kontener::setCzyZaliczone(const bool &value, int miejsceWTablicy)
{
    czyZaliczone[miejsceWTablicy]=value;
}

int Kontener::getObjetoscCwiczenia(int miejsceWTablicy) const
{
    return objetoscCwiczenia[miejsceWTablicy];
}

void Kontener::setObjetoscCwiczenia(int miejsceWTablicy)
{
    objetoscCwiczenia[miejsceWTablicy]=(iloscSerii[miejsceWTablicy]+1)*(iloscPowtorzen[miejsceWTablicy]+1)*ciezar[miejsceWTablicy];
}

