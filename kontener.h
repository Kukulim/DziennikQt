#ifndef KONTENER_H
#define KONTENER_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QVector>


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

private:

    int iloscSerii[12]={0};
    int iloscPowtorzen[12]={0};
    int ciezar[12]={0};
    int objetoscTreningu=0;
    QString nazwaCwiczenia[12]={nullptr};
    QString nazwaTreningu="";
    QDate dataCwiczenia;
    bool czyZaliczone[12]={false};

};

#endif // KONTENER_H
