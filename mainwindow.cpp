﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wlaczPolaczenia();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Zapisz");
    ui->buttonBox->button(QDialogButtonBox::Apply)->setText("Oblicz objetosc");
    ui->buttonBox->button(QDialogButtonBox::RestoreDefaults)->setText("Przywroc domyslne");
    ui->buttonBoxCardio->button(QDialogButtonBox::Ok)->setText("Zapisz");
    setCentralWidget(ui->stackedWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionDodaj_triggered()
{
     auto wpisek = m_ksiazka.stwozKontener();
     ui->listWidget->addItem(wpisek->getNazwaTreningu());
     auto listItem = ui->listWidget->item(ui->listWidget->count()-1);
     wpisMapa.insert(listItem, wpisek);

}

void MainWindow::on_actionDodaj_trening_cardio_triggered()
{
    auto wpisekcardio = m_ksiazka.stwozKontenerCardio();
    ui->listWidget->addItem(wpisekcardio->getNazwaTreningu());
    auto listItem = ui->listWidget->item(ui->listWidget->count()-1);
    wpisMapaCardio.insert(listItem, wpisekcardio);
}

void MainWindow::OkZapiszCardio()
{
    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapaCardio.value(listItem);

    listItem->setText((wpis->getDataTreninguCardio().toString())+" "+(wpis->getNazwaTreningu()));

    wpis->setRodzajTreninguCardio(ui->rodzajCardioEdit->currentText());
    wpis->setDystansTreninguCardio(ui->dystansCardioEdit->text().toDouble());
    wpis->setCzasTreninguCardio(ui->timeCardioEdit->time());
    wpis->setDataTreninguCardio(ui->dataCardioEdit->date());

    listItem->setText((wpis->getDataTreninguCardio().toString())+" "+(wpis->getNazwaTreningu()));
    listItem->setForeground(Qt::yellow);

    ui->calendarWidget->setSelectedDate(wpis->getDataTreninguCardio());

    QTextFormat obecnyKolor = ui->calendarWidget->dateTextFormat(wpis->getDataTreninguCardio());
    QTextCharFormat zaznaczonyKolor;
    if(obecnyKolor.background()==Qt::green||obecnyKolor.background()==Qt::darkCyan)
    {
        zaznaczonyKolor.setBackground(Qt::darkCyan);
    }
    else
    {
        zaznaczonyKolor.setBackground(Qt::yellow);
    }
    zaznaczonyKolor.setForeground(Qt::black);
    ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),zaznaczonyKolor);

    m_ksiazka.setDydtansWszystkichRodzaji();
    ui->bieganieCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichBiegow()));
    ui->bieganieDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichBiegow()));

    ui->spacerCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichSpacerow()));
    ui->spacerDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichSpacerow()));

    ui->rowerCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichRowerow()));
    ui->rowerDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichRowerow()));

    ui->plywanieCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichPlywan()));
    ui->plywanieDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichPlywan()));

    ui->lacznyCzasCardioEdit->setText(QString::number(m_ksiazka.getCzasWszystkichTreningowCardio()));
    ui->lacznyDystansCardioEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichTreningowCardio()));

    AnulujZapisz();

}

void MainWindow::PrzywrocDomyslneCardio()
{
    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapaCardio.value(listItem);

    ui->rodzajCardioEdit->setCurrentText(wpis->getRodzajTreninguCardio());
    ui->dataCardioEdit->setDate(wpis->getDataTreninguCardio());
    ui->timeCardioEdit->setTime(wpis->getCzasTreninguCardio());
    ui->dystansCardioEdit->setText(QString::number(wpis->getDystansTreninguCardio()));
    ui->dataCardioEdit->setDate(wpis->getDataTreninguCardio());
}

//void MainWindow::WczytajPoprzedniTrening()
//{

//    if (wpisMapa.size()>0)
//        {
//        int pozycja =0;
//        pozycja= ui->listWidget->currentRow();
//            for(int i =1;i<=pozycja;i++)
//            {
//            auto listItem = ui->listWidget->item(pozycja-i);
//            auto wpis = wpisMapa.value(listItem);
//            if(wpis)
//                {
//                ui->ostatniTreningSilowyDataEdit->setText(wpis->getDataCwiczenia().toString());
//                ui->ostatniTreningSilowyObjetoscEdit->setText(QString::number(wpis->getObjetoscTreningu()));
//                break;
//                }

//            }
//        }

//}

void MainWindow::on_actionUsun_triggered()
{
    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapa.value(listItem);

    if(wpis)
    {

        QMessageBox::StandardButton sprawdz;
        sprawdz = mojbox->question(this,"Dziennik treningowy","Czy usunac trening?",QMessageBox::Yes | QMessageBox::No);
        if(sprawdz == QMessageBox::Yes)
        {

            ui->calendarWidget->setSelectedDate(wpis->getDataCwiczenia());
            QTextFormat obecnyKolor = ui->calendarWidget->dateTextFormat(wpis->getDataCwiczenia());
            QTextCharFormat zaznaczonyKolor;
            if(obecnyKolor.background()==Qt::darkCyan)
            {
                zaznaczonyKolor.setBackground(Qt::yellow);
                zaznaczonyKolor.setForeground(Qt::black);
            }
            else
            {
                zaznaczonyKolor.setBackground(QColor(65, 65, 65));
                zaznaczonyKolor.setForeground(Qt::white);
            }
            ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),zaznaczonyKolor);

            m_ksiazka.skasujKontener(wpis);
            wpisMapa.remove(listItem);
            delete listItem;
            ui->wszystkieTreningiSiloweIloscEdit->setText(QString::number(m_ksiazka.getIloscTreningowSilowych()));
            m_ksiazka.setObjetoscWszystkichTreningowSilowych();
            ui->wszystkieTreningiSiloweObjetoscEdit->setText(QString::number(m_ksiazka.getObjetoscWszystkichTreningowSilowych()));
            AnulujZapisz();
        }
    }
    else
    {
        auto wpis2= wpisMapaCardio.value(listItem);
        QMessageBox::StandardButton sprawdz;
        sprawdz = mojbox->question(this,"Dziennik treningowy","Czy usunac trening?",QMessageBox::Yes | QMessageBox::No);
        QMessageBox msgBox;
        if(sprawdz == QMessageBox::Yes)
        {

            ui->calendarWidget->setSelectedDate(wpis2->getDataTreninguCardio());
            QTextFormat obecnyKolor = ui->calendarWidget->dateTextFormat(wpis2->getDataTreninguCardio());
            QTextCharFormat zaznaczonyKolor;
            if(obecnyKolor.background()==Qt::darkCyan)
            {
                zaznaczonyKolor.setBackground(Qt::green);
            }
            else
            {
                zaznaczonyKolor.setBackground(QColor(65, 65, 65));
            }

            zaznaczonyKolor.setForeground(Qt::white);
            ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),zaznaczonyKolor);

            m_ksiazka.skasujKontenerCardio(wpis2);
            wpisMapaCardio.remove(listItem);
            delete listItem;

            m_ksiazka.setDydtansWszystkichRodzaji();
            ui->bieganieCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichBiegow()));
            ui->bieganieDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichBiegow()));

            ui->spacerCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichSpacerow()));
            ui->spacerDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichSpacerow()));

            ui->rowerCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichRowerow()));
            ui->rowerDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichRowerow()));

            ui->plywanieCzasEdit->setText(QString::number(m_ksiazka.getCzasWszystkichPlywan()));
            ui->plywanieDystansEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichPlywan()));

            ui->lacznyCzasCardioEdit->setText(QString::number(m_ksiazka.getCzasWszystkichTreningowCardio()));
            ui->lacznyDystansCardioEdit->setText(QString::number(m_ksiazka.getDydtansWszystkichTreningowCardio()));

            AnulujZapisz();

        }
    }

}

void MainWindow::on_actionEdytuj_triggered()
{
    if(ui->listWidget->currentItem())
    {
        auto listItem = ui->listWidget->currentItem();
        auto wpis = wpisMapa.value(listItem);
        if(wpis)
        {
            PrzywrocDomyslne();
            ui->dataEdit->setDate(wpis->getDataCwiczenia());
            ui->stackedWidget->setCurrentWidget(ui->page_2);
            ui->menu->setEnabled(false);
            WyswietlObjetosc();
        }
        else
            {
            auto wpis2= wpisMapaCardio.value(listItem);
            ui->dataCardioEdit->setDate(wpis2->getDataTreninguCardio());
            ui->stackedWidget->setCurrentWidget(ui->page_3);
            ui->menu->setEnabled(false);
            PrzywrocDomyslneCardio();
            }
    }
}

void MainWindow::Okzapisz()
{

    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapa.value(listItem);

    wpis->setDataCwiczenia(ui->dataEdit->date());
    wpis->setNazwaCwiczenia(ui->nazwacwEdit->text(),0);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_2->text(),1);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_3->text(),2);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_4->text(),3);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_5->text(),4);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_6->text(),5);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_7->text(),6);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_8->text(),7);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_9->text(),8);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_10->text(),9);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_11->text(),10);
    wpis->setNazwaCwiczenia(ui->nazwacwEdit_12->text(),11);
    wpis->setIloscSerii(ui->iloscserEdit->currentIndex(),0);
    wpis->setIloscSerii(ui->iloscserEdit_3->currentIndex(),1);
    wpis->setIloscSerii(ui->iloscserEdit_4->currentIndex(),2);
    wpis->setIloscSerii(ui->iloscserEdit_5->currentIndex(),3);
    wpis->setIloscSerii(ui->iloscserEdit_6->currentIndex(),4);
    wpis->setIloscSerii(ui->iloscserEdit_7->currentIndex(),5);
    wpis->setIloscSerii(ui->iloscserEdit_8->currentIndex(),6);
    wpis->setIloscSerii(ui->iloscserEdit_9->currentIndex(),7);
    wpis->setIloscSerii(ui->iloscserEdit_10->currentIndex(),8);
    wpis->setIloscSerii(ui->iloscserEdit_11->currentIndex(),9);
    wpis->setIloscSerii(ui->iloscserEdit_12->currentIndex(),10);
    wpis->setIloscSerii(ui->iloscserEdit_13->currentIndex(),11);
    wpis->setIloscPowtorzen(ui->iloscpowEdit->currentIndex(),0);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_3->currentIndex(),1);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_4->currentIndex(),2);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_5->currentIndex(),3);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_6->currentIndex(),4);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_7->currentIndex(),5);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_8->currentIndex(),6);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_9->currentIndex(),7);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_10->currentIndex(),8);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_11->currentIndex(),9);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_12->currentIndex(),10);
    wpis->setIloscPowtorzen(ui->iloscpowEdit_13->currentIndex(),11);
    wpis->setCiezar(ui->ciezarEdit->text().toInt(),0);
    wpis->setCiezar(ui->ciezarEdit_3->text().toInt(),1);
    wpis->setCiezar(ui->ciezarEdit_4->text().toInt(),2);
    wpis->setCiezar(ui->ciezarEdit_5->text().toInt(),3);
    wpis->setCiezar(ui->ciezarEdit_6->text().toInt(),4);
    wpis->setCiezar(ui->ciezarEdit_7->text().toInt(),5);
    wpis->setCiezar(ui->ciezarEdit_8->text().toInt(),6);
    wpis->setCiezar(ui->ciezarEdit_9->text().toInt(),7);
    wpis->setCiezar(ui->ciezarEdit_10->text().toInt(),8);
    wpis->setCiezar(ui->ciezarEdit_11->text().toInt(),9);
    wpis->setCiezar(ui->ciezarEdit_12->text().toInt(),10);
    wpis->setCiezar(ui->ciezarEdit_13->text().toInt(),11);
    wpis->setCzyZaliczone(ui->czyzaliczonecw->checkState(),0);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_2->checkState(),1);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_3->checkState(),2);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_4->checkState(),3);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_5->checkState(),4);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_6->checkState(),5);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_7->checkState(),6);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_8->checkState(),7);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_9->checkState(),8);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_10->checkState(),9);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_11->checkState(),10);
    wpis->setCzyZaliczone(ui->czyzaliczonecw_12->checkState(),11);

    listItem->setText((wpis->getDataCwiczenia().toString())+" "+(wpis->getNazwaTreningu()));
    listItem->setForeground(Qt::green);

    ui->calendarWidget->setSelectedDate(wpis->getDataCwiczenia());

    QTextFormat obecnyKolor = ui->calendarWidget->dateTextFormat(wpis->getDataCwiczenia());
    QTextCharFormat zaznaczonyKolor;
    if(obecnyKolor.background()==Qt::yellow||obecnyKolor.background()==Qt::darkCyan)
    {
        zaznaczonyKolor.setBackground(Qt::darkCyan);
    }
    else
    {
        zaznaczonyKolor.setBackground(Qt::green);
    }

    zaznaczonyKolor.setForeground(Qt::black);
    ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),zaznaczonyKolor);
    ui->wszystkieTreningiSiloweIloscEdit->setText(QString::number(m_ksiazka.getIloscTreningowSilowych()));

    WyswietlObjetosc();
    wpis->setObjetoscTreningu(ui->objetosccalaEdit->text().toInt());

    ui->ostatniTreningSilowyDataEdit->setText(wpis->getDataCwiczenia().toString());
    ui->ostatniTreningSilowyObjetoscEdit->setText(QString::number(wpis->getObjetoscTreningu()));

    m_ksiazka.setObjetoscWszystkichTreningowSilowych();
    ui->wszystkieTreningiSiloweObjetoscEdit->setText(QString::number(m_ksiazka.getObjetoscWszystkichTreningowSilowych()));

    AnulujZapisz();
}

void MainWindow::AnulujZapisz()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->menu->setEnabled(true);
}

void MainWindow::PrzywrocDomyslne()
{
    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapa.value(listItem);
    ui->dataEdit->setDate(wpis->getDataCwiczenia());
    ui->nazwacwEdit->setText(wpis->getNazwaCwiczenia(0));
    ui->nazwacwEdit_2->setText(wpis->getNazwaCwiczenia(1));
    ui->nazwacwEdit_3->setText(wpis->getNazwaCwiczenia(2));
    ui->nazwacwEdit_4->setText(wpis->getNazwaCwiczenia(3));
    ui->nazwacwEdit_5->setText(wpis->getNazwaCwiczenia(4));
    ui->nazwacwEdit_6->setText(wpis->getNazwaCwiczenia(5));
    ui->nazwacwEdit_7->setText(wpis->getNazwaCwiczenia(6));
    ui->nazwacwEdit_8->setText(wpis->getNazwaCwiczenia(7));
    ui->nazwacwEdit_9->setText(wpis->getNazwaCwiczenia(8));
    ui->nazwacwEdit_10->setText(wpis->getNazwaCwiczenia(9));
    ui->nazwacwEdit_11->setText(wpis->getNazwaCwiczenia(10));
    ui->nazwacwEdit_12->setText(wpis->getNazwaCwiczenia(11));
    ui->iloscserEdit->setCurrentIndex(wpis->getIloscSerii(0));
    ui->iloscserEdit_3->setCurrentIndex(wpis->getIloscSerii(1));
    ui->iloscserEdit_4->setCurrentIndex(wpis->getIloscSerii(2));
    ui->iloscserEdit_5->setCurrentIndex(wpis->getIloscSerii(3));
    ui->iloscserEdit_6->setCurrentIndex(wpis->getIloscSerii(4));
    ui->iloscserEdit_7->setCurrentIndex(wpis->getIloscSerii(5));
    ui->iloscserEdit_8->setCurrentIndex(wpis->getIloscSerii(6));
    ui->iloscserEdit_9->setCurrentIndex(wpis->getIloscSerii(7));
    ui->iloscserEdit_10->setCurrentIndex(wpis->getIloscSerii(8));
    ui->iloscserEdit_11->setCurrentIndex(wpis->getIloscSerii(9));
    ui->iloscserEdit_12->setCurrentIndex(wpis->getIloscSerii(10));
    ui->iloscserEdit_13->setCurrentIndex(wpis->getIloscSerii(11));
    ui->iloscpowEdit->setCurrentIndex(wpis->getIloscPowtorzen(0));
    ui->iloscpowEdit_3->setCurrentIndex(wpis->getIloscPowtorzen(1));
    ui->iloscpowEdit_4->setCurrentIndex(wpis->getIloscPowtorzen(2));
    ui->iloscpowEdit_5->setCurrentIndex(wpis->getIloscPowtorzen(3));
    ui->iloscpowEdit_6->setCurrentIndex(wpis->getIloscPowtorzen(4));
    ui->iloscpowEdit_7->setCurrentIndex(wpis->getIloscPowtorzen(5));
    ui->iloscpowEdit_8->setCurrentIndex(wpis->getIloscPowtorzen(6));
    ui->iloscpowEdit_9->setCurrentIndex(wpis->getIloscPowtorzen(7));
    ui->iloscpowEdit_10->setCurrentIndex(wpis->getIloscPowtorzen(8));
    ui->iloscpowEdit_11->setCurrentIndex(wpis->getIloscPowtorzen(9));
    ui->iloscpowEdit_12->setCurrentIndex(wpis->getIloscPowtorzen(10));
    ui->iloscpowEdit_13->setCurrentIndex(wpis->getIloscPowtorzen(11));
    ui->ciezarEdit->setText(QString::number(wpis->getCiezar(0)));
    ui->ciezarEdit_3->setText(QString::number(wpis->getCiezar(1)));
    ui->ciezarEdit_4->setText(QString::number(wpis->getCiezar(2)));
    ui->ciezarEdit_5->setText(QString::number(wpis->getCiezar(3)));
    ui->ciezarEdit_6->setText(QString::number(wpis->getCiezar(4)));
    ui->ciezarEdit_7->setText(QString::number(wpis->getCiezar(5)));
    ui->ciezarEdit_8->setText(QString::number(wpis->getCiezar(6)));
    ui->ciezarEdit_9->setText(QString::number(wpis->getCiezar(7)));
    ui->ciezarEdit_10->setText(QString::number(wpis->getCiezar(8)));
    ui->ciezarEdit_11->setText(QString::number(wpis->getCiezar(9)));
    ui->ciezarEdit_12->setText(QString::number(wpis->getCiezar(10)));
    ui->ciezarEdit_13->setText(QString::number(wpis->getCiezar(11)));
    ui->czyzaliczonecw->setChecked(wpis->getCzyZaliczone(0));
    ui->czyzaliczonecw_2->setChecked(wpis->getCzyZaliczone(1));
    ui->czyzaliczonecw_3->setChecked(wpis->getCzyZaliczone(2));
    ui->czyzaliczonecw_4->setChecked(wpis->getCzyZaliczone(3));
    ui->czyzaliczonecw_5->setChecked(wpis->getCzyZaliczone(4));
    ui->czyzaliczonecw_6->setChecked(wpis->getCzyZaliczone(5));
    ui->czyzaliczonecw_7->setChecked(wpis->getCzyZaliczone(6));
    ui->czyzaliczonecw_8->setChecked(wpis->getCzyZaliczone(7));
    ui->czyzaliczonecw_9->setChecked(wpis->getCzyZaliczone(8));
    ui->czyzaliczonecw_10->setChecked(wpis->getCzyZaliczone(9));
    ui->czyzaliczonecw_11->setChecked(wpis->getCzyZaliczone(10));
    ui->czyzaliczonecw_12->setChecked(wpis->getCzyZaliczone(11));

    WyswietlObjetosc();

}

void MainWindow::WyswietlObjetosc()
{

    ui->objetoscEdit->setText(QString::number((ui->iloscserEdit->currentIndex()+1)*(ui->iloscpowEdit->currentIndex()+1)*ui->ciezarEdit->text().toInt()));
    ui->objetoscEdit_2->setText(QString::number((ui->iloscserEdit_3->currentIndex()+1)*(ui->iloscpowEdit_3->currentIndex()+1)*ui->ciezarEdit_3->text().toInt()));
    ui->objetoscEdit_3->setText(QString::number((ui->iloscserEdit_4->currentIndex()+1)*(ui->iloscpowEdit_4->currentIndex()+1)*ui->ciezarEdit_4->text().toInt()));
    ui->objetoscEdit_4->setText(QString::number((ui->iloscserEdit_5->currentIndex()+1)*(ui->iloscpowEdit_5->currentIndex()+1)*ui->ciezarEdit_5->text().toInt()));
    ui->objetoscEdit_5->setText(QString::number((ui->iloscserEdit_6->currentIndex()+1)*(ui->iloscpowEdit_6->currentIndex()+1)*ui->ciezarEdit_6->text().toInt()));
    ui->objetoscEdit_6->setText(QString::number((ui->iloscserEdit_7->currentIndex()+1)*(ui->iloscpowEdit_7->currentIndex()+1)*ui->ciezarEdit_7->text().toInt()));
    ui->objetoscEdit_7->setText(QString::number((ui->iloscserEdit_8->currentIndex()+1)*(ui->iloscpowEdit_8->currentIndex()+1)*ui->ciezarEdit_8->text().toInt()));
    ui->objetoscEdit_8->setText(QString::number((ui->iloscserEdit_9->currentIndex()+1)*(ui->iloscpowEdit_9->currentIndex()+1)*ui->ciezarEdit_9->text().toInt()));
    ui->objetoscEdit_9->setText(QString::number((ui->iloscserEdit_10->currentIndex()+1)*(ui->iloscpowEdit_10->currentIndex()+1)*ui->ciezarEdit_10->text().toInt()));
    ui->objetoscEdit_10->setText(QString::number((ui->iloscserEdit_11->currentIndex()+1)*(ui->iloscpowEdit_11->currentIndex()+1)*ui->ciezarEdit_11->text().toInt()));
    ui->objetoscEdit_11->setText(QString::number((ui->iloscserEdit_12->currentIndex()+1)*(ui->iloscpowEdit_12->currentIndex()+1)*ui->ciezarEdit_12->text().toInt()));
    ui->objetoscEdit_12->setText(QString::number((ui->iloscserEdit_13->currentIndex()+1)*(ui->iloscpowEdit_13->currentIndex()+1)*ui->ciezarEdit_13->text().toInt()));

    int suma=0;
    suma=(ui->objetoscEdit->text().toInt()+
          ui->objetoscEdit_2->text().toInt()+
          ui->objetoscEdit_3->text().toInt()+
          ui->objetoscEdit_4->text().toInt()+
          ui->objetoscEdit_5->text().toInt()+
          ui->objetoscEdit_6->text().toInt()+
          ui->objetoscEdit_7->text().toInt()+
          ui->objetoscEdit_8->text().toInt()+
          ui->objetoscEdit_9->text().toInt()+
          ui->objetoscEdit_10->text().toInt()+
          ui->objetoscEdit_11->text().toInt()+
          ui->objetoscEdit_12->text().toInt());

    ui->objetosccalaEdit->setText(QString::number(suma));
}

void MainWindow::wlaczPolaczenia()
{
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),&QPushButton::clicked,this,&MainWindow::AnulujZapisz);
    connect(ui->buttonBox->button(QDialogButtonBox::Ok),&QPushButton::clicked,this,&MainWindow::Okzapisz);
    connect(ui->buttonBox->button(QDialogButtonBox::RestoreDefaults),&QPushButton::clicked,this,&MainWindow::PrzywrocDomyslne);
    connect(ui->buttonBox->button(QDialogButtonBox::Apply),&QPushButton::clicked,this,&MainWindow::WyswietlObjetosc);
    connect(ui->buttonBoxCardio->button(QDialogButtonBox::Cancel),&QPushButton::clicked,this,&MainWindow::AnulujZapisz);
    connect(ui->buttonBoxCardio->button(QDialogButtonBox::Ok),&QPushButton::clicked,this,&MainWindow::OkZapiszCardio);
}

void MainWindow::on_listWidget_itemDoubleClicked()
{
    on_actionEdytuj_triggered();
}

void MainWindow::on_ZestawA_clicked()
{
    m_ksiazka.setWyznacznikZestawuCwiczen('A');
    ui->ZestawA->setDown(true);
    ui->ZestawB->setDown(false);
}

void MainWindow::on_ZestawB_clicked()
{
    m_ksiazka.setWyznacznikZestawuCwiczen('B');
    ui->ZestawB->setDown(true);
    ui->ZestawA->setDown(false);
}

void MainWindow::on_ZapiszZestaw_clicked()
{
    if(m_ksiazka.getWyznacznikZestawuCwiczen()=='A')
    {
        m_ksiazka.setZestawA(ui->nazwacwEdit->text(),0);
        m_ksiazka.setZestawA(ui->nazwacwEdit_2->text(),1);
        m_ksiazka.setZestawA(ui->nazwacwEdit_3->text(),2);
        m_ksiazka.setZestawA(ui->nazwacwEdit_4->text(),3);
        m_ksiazka.setZestawA(ui->nazwacwEdit_5->text(),4);
        m_ksiazka.setZestawA(ui->nazwacwEdit_6->text(),5);
        m_ksiazka.setZestawA(ui->nazwacwEdit_7->text(),6);
        m_ksiazka.setZestawA(ui->nazwacwEdit_8->text(),7);
        m_ksiazka.setZestawA(ui->nazwacwEdit_9->text(),8);
        m_ksiazka.setZestawA(ui->nazwacwEdit_10->text(),9);
        m_ksiazka.setZestawA(ui->nazwacwEdit_11->text(),10);
        m_ksiazka.setZestawA(ui->nazwacwEdit_12->text(),11);
    }
    if(m_ksiazka.getWyznacznikZestawuCwiczen()=='B')
    {
        m_ksiazka.setZestawB(ui->nazwacwEdit->text(),0);
        m_ksiazka.setZestawB(ui->nazwacwEdit_2->text(),1);
        m_ksiazka.setZestawB(ui->nazwacwEdit_3->text(),2);
        m_ksiazka.setZestawB(ui->nazwacwEdit_4->text(),3);
        m_ksiazka.setZestawB(ui->nazwacwEdit_5->text(),4);
        m_ksiazka.setZestawB(ui->nazwacwEdit_6->text(),5);
        m_ksiazka.setZestawB(ui->nazwacwEdit_7->text(),6);
        m_ksiazka.setZestawB(ui->nazwacwEdit_8->text(),7);
        m_ksiazka.setZestawB(ui->nazwacwEdit_9->text(),8);
        m_ksiazka.setZestawB(ui->nazwacwEdit_10->text(),9);
        m_ksiazka.setZestawB(ui->nazwacwEdit_11->text(),10);
        m_ksiazka.setZestawB(ui->nazwacwEdit_12->text(),11);
    }
}

void MainWindow::on_WczytajZestaw_clicked()
{
    if(m_ksiazka.getWyznacznikZestawuCwiczen()=='A')
    {
        ui->nazwacwEdit->setText(m_ksiazka.getZestawA(0));
        ui->nazwacwEdit_2->setText(m_ksiazka.getZestawA(1));
        ui->nazwacwEdit_3->setText(m_ksiazka.getZestawA(2));
        ui->nazwacwEdit_4->setText(m_ksiazka.getZestawA(3));
        ui->nazwacwEdit_5->setText(m_ksiazka.getZestawA(4));
        ui->nazwacwEdit_6->setText(m_ksiazka.getZestawA(5));
        ui->nazwacwEdit_7->setText(m_ksiazka.getZestawA(6));
        ui->nazwacwEdit_8->setText(m_ksiazka.getZestawA(7));
        ui->nazwacwEdit_9->setText(m_ksiazka.getZestawA(8));
        ui->nazwacwEdit_10->setText(m_ksiazka.getZestawA(9));
        ui->nazwacwEdit_11->setText(m_ksiazka.getZestawA(10));
        ui->nazwacwEdit_12->setText(m_ksiazka.getZestawA(11));
    }
    if(m_ksiazka.getWyznacznikZestawuCwiczen()=='B')
    {
        ui->nazwacwEdit->setText(m_ksiazka.getZestawB(0));
        ui->nazwacwEdit_2->setText(m_ksiazka.getZestawB(1));
        ui->nazwacwEdit_3->setText(m_ksiazka.getZestawB(2));
        ui->nazwacwEdit_4->setText(m_ksiazka.getZestawB(3));
        ui->nazwacwEdit_5->setText(m_ksiazka.getZestawB(4));
        ui->nazwacwEdit_6->setText(m_ksiazka.getZestawB(5));
        ui->nazwacwEdit_7->setText(m_ksiazka.getZestawB(6));
        ui->nazwacwEdit_8->setText(m_ksiazka.getZestawB(7));
        ui->nazwacwEdit_9->setText(m_ksiazka.getZestawB(8));
        ui->nazwacwEdit_10->setText(m_ksiazka.getZestawB(9));
        ui->nazwacwEdit_11->setText(m_ksiazka.getZestawB(10));
        ui->nazwacwEdit_12->setText(m_ksiazka.getZestawB(11));
    }
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        m_ksiazka.readFromFile(fileName);
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty())
        m_ksiazka.writeToFile(fileName);
}

void MainWindow::on_actionWczytaj_triggered()
{
    openFile();
}

void MainWindow::on_actionZapisz_triggered()
{
    saveFile();
}
