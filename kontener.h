#ifndef KONTENER_H
#define KONTENER_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QVector>
#include <QtCore>


class Kontener : public QObject
{
    Q_OBJECT
public:
    explicit Kontener(QObject *parent = nullptr);
    ~Kontener();

    QString getNazwaTreningu() const;
    void setNazwaTreningu(const QString &value);

    QDate getDataCwiczenia() const;
    void setDataCwiczenia(const QDate &value);

    QString getNazwaCwiczenia(int miejsceWTablicy) const;
    void setNazwaCwiczenia(const QString &value, int miejsceWTablicy);

    int getIloscSerii(int miejsceWTablicy) const;
    void setIloscSerii(const int &value, int miejsceWTablicy);

    int getIloscPowtorzen(int miejsceWTablicy) const;
    void setIloscPowtorzen(const int &value, int miejsceWTablicy);

    int getCiezar(int miejsceWTablicy) const;
    void setCiezar(const int &value, int miejsceWTablicy);

    bool getCzyZaliczone(int miejsceWTablicy) const;
    void setCzyZaliczone(const bool &value, int miejsceWTablicy);

    int getObjetoscTreningu() const;
    void setObjetoscTreningu(int value);


signals:

public slots:

    public:

    int iloscSerii[12]={0};
    int iloscPowtorzen[12]={0};
    int ciezar[12]={0};
    int objetoscTreningu=0;
    QString nazwaCwiczenia[12]={nullptr};
    QString nazwaTreningu="";
    QDate dataCwiczenia;
    bool czyZaliczone[12]={false};

};
//inline QDataStream operator<<(QDataStream &stream,Kontener &daneKontener)
//{

//    for(int i=0;i<12;i++)
//    {
//        stream << daneKontener.iloscSerii[i];
//    }
//    for(int i=0;i<12;i++)
//    {
//        stream << daneKontener.iloscPowtorzen[i];
//    }
//    for(int i=0;i<12;i++)
//    {
//        stream << daneKontener.ciezar[i];
//    }
//    stream << daneKontener.objetoscTreningu;
//    for(int i=0;i<12;i++)
//    {
//        stream << daneKontener.nazwaCwiczenia[i];
//    }
//    stream << daneKontener.nazwaTreningu;
//    stream << daneKontener.dataCwiczenia;
//    for(int i=0;i<12;i++)
//    {
//        stream << daneKontener.czyZaliczone[i];
//    }
//    return stream;
//}
//inline QDataStream &operator>>(QDataStream &stream, Kontener &daneKontener)
//{

//    for(int i=0;i<12;i++)
//    {
//        stream >> daneKontener.iloscSerii[i];
//    }
//    for(int i=0;i<12;i++)
//    {
//        stream >> daneKontener.iloscPowtorzen[i];
//    }
//    for(int i=0;i<12;i++)
//    {
//        stream >> daneKontener.ciezar[i];
//    }
//    stream >> daneKontener.objetoscTreningu;
//    for(int i=0;i<12;i++)
//    {
//        stream >> daneKontener.nazwaCwiczenia[i];
//    }
//    stream >> daneKontener.nazwaTreningu;
//    stream >> daneKontener.dataCwiczenia;
//    for(int i=0;i<12;i++)
//    {
//        stream >> daneKontener.czyZaliczone[i];
//    }
//    return stream;
//}

#endif // KONTENER_H
