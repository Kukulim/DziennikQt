#include "kontenercardio.h"

KontenerCardio::KontenerCardio(QObject *parent) : QObject(parent)
{

}

KontenerCardio::~KontenerCardio()
{

}

QString KontenerCardio::getNazwaTreningu() const
{
    return nazwaTreningu;
}

void KontenerCardio::setNazwaTreningu(const QString &value)
{
    nazwaTreningu = value;
}

QString KontenerCardio::getRodzajTreninguCardio() const
{
    return rodzajTreninguCardio;
}

void KontenerCardio::setRodzajTreninguCardio(const QString &value)
{
    rodzajTreninguCardio = value;
}

QDate KontenerCardio::getDataTreninguCardio() const
{
    return dataTreninguCardio;
}

void KontenerCardio::setDataTreninguCardio(const QDate &value)
{
    dataTreninguCardio = value;
}

QTime KontenerCardio::getCzasTreninguCardio() const
{
    return czasTreninguCardio;
}

void KontenerCardio::setCzasTreninguCardio(const QTime &value)
{
    czasTreninguCardio = value;
}

double KontenerCardio::getDystansTreninguCardio() const
{
    return dystansTreninguCardio;
}

void KontenerCardio::setDystansTreninguCardio(double value)
{
    dystansTreninguCardio = value;
}
