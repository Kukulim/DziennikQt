#ifndef KONTENERCARDIO_H
#define KONTENERCARDIO_H

#include <QObject>
#include <QtCore>

class KontenerCardio : public QObject
{
    Q_OBJECT
public:
    explicit KontenerCardio(QObject *parent = nullptr);
    ~KontenerCardio();

    QString getNazwaTreningu() const;
    void setNazwaTreningu(const QString &value);

    QString getRodzajTreninguCardio() const;
    void setRodzajTreninguCardio(const QString &value);

    QDate getDataTreninguCardio() const;
    void setDataTreninguCardio(const QDate &value);

    QTime getCzasTreninguCardio() const;
    void setCzasTreninguCardio(const QTime &value);

    double getDystansTreninguCardio() const;
    void setDystansTreninguCardio(double value);

signals:

public slots:
private:

    QString nazwaTreningu="";
    QString rodzajTreninguCardio;
    QDate dataTreninguCardio;
    QTime czasTreninguCardio;
    double dystansTreninguCardio=0;
};

#endif // KONTENERCARDIO_H
