#ifndef KSIAZKAKONTENER_H
#define KSIAZKAKONTENER_H

#include <QObject>
#include <QVector>
#include "kontener.h"
#include "kontenercardio.h"

class KsiazkaKontener : public QObject
{
    Q_OBJECT
public:
    explicit KsiazkaKontener(QObject *parent = nullptr);
    QVector<Kontener*> wynikWKsiazce;
    QVector<KontenerCardio*> wynikWKsiazceCardio;

    Kontener* stwozKontener();
    void skasujKontener(Kontener* wpis);

    KontenerCardio* stwozKontenerCardio();
    void skasujKontenerCardio(KontenerCardio* wpis);

    QString getZestawA(int miejsceWTablicy) const;
    void setZestawA(const QString &value, int miejsceWTablicy);

    QString getZestawB(int miejsceWTablicy) const;
    void setZestawB(const QString &value, int miejsceWTablicy);

    char getWyznacznikZestawuCwiczen() const;
    void setWyznacznikZestawuCwiczen(char value);

    void dodajIloscTreningowSilowych();
    void usunIloscTreningowSilowych();


    int getIloscTreningowSilowych() const;

    int getObjetoscWszystkichTreningowSilowych() const;
    void setObjetoscWszystkichTreningowSilowych();

    int getCzasWszystkichSpacerow() const;
    double getDydtansWszystkichSpacerow() const;

    int getCzasWszystkichRowerow() const;
    double getDydtansWszystkichRowerow() const;

    int getCzasWszystkichPlywan() const;
    double getDydtansWszystkichPlywan() const;

    int getCzasWszystkichTreningowCardio() const;
    double getDydtansWszystkichTreningowCardio() const;

    int getCzasWszystkichBiegow() const;
    double getDydtansWszystkichBiegow() const;

    void setDydtansWszystkichRodzaji();

signals:
public slots:
private:
    QString zestawA[12] = {nullptr};
    QString zestawB[12] = {nullptr};
    char wyznacznikZestawuCwiczen = 'z';

    int iloscTreningowSilowych = 0;
    int objetoscWszystkichTreningowSilowych = 0;

    int czasWszystkichBiegow;
    double dydtansWszystkichBiegow ;
    int czasWszystkichSpacerow;
    double dydtansWszystkichSpacerow = 0;
    int czasWszystkichRowerow;
    double dydtansWszystkichRowerow = 0;
    int czasWszystkichPlywan;
    double dydtansWszystkichPlywan = 0;
    int czasWszystkichTreningowCardio;
    double dydtansWszystkichTreningowCardio = 0;
};

#endif // KSIAZKAKONTENER_H
