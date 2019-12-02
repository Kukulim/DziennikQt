#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>

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


private:
    Ui::MainWindow *ui;
    KsiazkaKontener m_ksiazka;
    QHash<QListWidgetItem*,Kontener*> wpisMapa;

    void wlaczPolaczenia();

};
#endif // MAINWINDOW_H
