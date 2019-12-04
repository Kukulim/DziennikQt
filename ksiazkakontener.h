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



signals:

    void kontenerStworzony(Kontener *kontener);
    void kontenerUsuniety();

public slots:
};

#endif // KSIAZKAKONTENER_H
