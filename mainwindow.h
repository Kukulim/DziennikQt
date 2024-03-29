#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QMessageBox>

#include "ksiazkakontener.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QListWidgetItem;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDodaj_triggered();

    void on_actionUsun_triggered();

    void on_actionEdytuj_triggered();

    void Okzapisz();

    void AnulujZapisz();

    void PrzywrocDomyslne();

    void WyswietlObjetosc();

    void on_actionDodaj_trening_cardio_triggered();

    void OkZapiszCardio();

    void PrzywrocDomyslneCardio();

    //void WczytajPoprzedniTrening(); Narazie niepotrzebne

    void on_listWidget_itemDoubleClicked();

    void on_ZestawA_clicked();

    void on_ZestawB_clicked();

    void on_ZapiszZestaw_clicked();

    void on_WczytajZestaw_clicked();

    void openFile();

    void saveFile();

    void on_actionWczytaj_triggered();

    void on_actionZapisz_triggered();

private:
    Ui::MainWindow *ui;
    KsiazkaKontener m_ksiazka;
    QHash<QListWidgetItem*,Kontener*> wpisMapa;
    QHash<QListWidgetItem*,KontenerCardio*> wpisMapaCardio;
    QMessageBox *mojbox= new QMessageBox(this);


    void wlaczPolaczenia();

};
#endif // MAINWINDOW_H
