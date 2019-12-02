#ifndef KSIAZKAKONTENER_H
#define KSIAZKAKONTENER_H

#include <QObject>
#include <QVector>
#include "kontener.h"

class KsiazkaKontener : public QObject
{
    Q_OBJECT
public:
    explicit KsiazkaKontener(QObject *parent = nullptr);
    QVector<Kontener*> wynikWKsiazce;

    Kontener* stwozKontener();
    void skasujKontener(Kontener* wpis);

signals:

    void kontenerStworzony(Kontener *kontener);
    void kontenerUsuniety();

public slots:
};

#endif // KSIAZKAKONTENER_H
