#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wlaczPolaczenia();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Zapisz");
    ui->buttonBox->button(QDialogButtonBox::Apply)->setText("Oblicz objetosc");
    ui->buttonBox->button(QDialogButtonBox::RestoreDefaults)->setText("Przywroc domyslne");
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

void MainWindow::on_actionUsun_triggered()
{
    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapa.value(listItem);

    if(wpis)
    {
        QMessageBox::StandardButton sprawdz;
        sprawdz = QMessageBox::question(this,"Dziennik treningowy","Czy usunac trening?",QMessageBox::Yes | QMessageBox::No);
        if(sprawdz == QMessageBox::Yes)
        {
        m_ksiazka.skasujKontener(wpis);
        wpisMapa.remove(listItem);
        delete listItem;
        }
    }
    else
    {
        auto wpis2= wpisMapaCardio.value(listItem);
        QMessageBox::StandardButton sprawdz;
        sprawdz = QMessageBox::question(this,"Dziennik treningowy","Czy usunac trening?",QMessageBox::Yes | QMessageBox::No);
        if(sprawdz == QMessageBox::Yes)
        {
        m_ksiazka.skasujKontenerCardio(wpis2);
        wpisMapaCardio.remove(listItem);
        delete listItem;
        }
    }

}

void MainWindow::on_actionEdytuj_triggered()
{
    if(ui->listWidget->currentItem())
    {
    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapa.value(listItem);
    PrzywrocDomyslne();
    ui->dataEdit->setDate(wpis->getDataCwiczenia());
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->menu->setEnabled(false);
    WyswietlObjetosc();
    }
}

void MainWindow::Okzapisz()
{

    auto listItem = ui->listWidget->currentItem();
    auto wpis = wpisMapa.value(listItem);
    wpis->setDataCwiczenia(ui->dataEdit->date());
    wpis->setIloscSerii(ui->iloscserEdit->currentText().toInt(),(ui->listWidget->count()-1));
    listItem->setText((wpis->getDataCwiczenia().toString())+" "+(wpis->getNazwaTreningu()));
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
    wpis->setIloscSerii(ui->iloscserEdit_13->currentIndex(),10);
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
    ui->objetoscEdit->setText(QString::number(wpis->getObjetoscCwiczenia(0)));
    ui->objetoscEdit_2->setText(QString::number(wpis->getObjetoscCwiczenia(1)));
    ui->objetoscEdit_3->setText(QString::number(wpis->getObjetoscCwiczenia(2)));
    ui->objetoscEdit_4->setText(QString::number(wpis->getObjetoscCwiczenia(3)));
    ui->objetoscEdit_5->setText(QString::number(wpis->getObjetoscCwiczenia(4)));
    ui->objetoscEdit_6->setText(QString::number(wpis->getObjetoscCwiczenia(5)));
    ui->objetoscEdit_7->setText(QString::number(wpis->getObjetoscCwiczenia(6)));
    ui->objetoscEdit_8->setText(QString::number(wpis->getObjetoscCwiczenia(7)));
    ui->objetoscEdit_9->setText(QString::number(wpis->getObjetoscCwiczenia(8)));
    ui->objetoscEdit_10->setText(QString::number(wpis->getObjetoscCwiczenia(9)));
    ui->objetoscEdit_11->setText(QString::number(wpis->getObjetoscCwiczenia(10)));
    ui->objetoscEdit_12->setText(QString::number(wpis->getObjetoscCwiczenia(11)));
    //ui->objetosccalaEdit->setText(QString::number(wpis->getObjetoscTreningu()));
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

}

void MainWindow::WyswietlObjetosc()
{

    ui->objetoscEdit->setText(QString::number((ui->iloscserEdit->currentIndex()+1)*(ui->iloscserEdit->currentIndex()+1)*ui->ciezarEdit->text().toInt()));
    ui->objetoscEdit_2->setText(QString::number((ui->iloscserEdit_3->currentIndex()+1)*(ui->iloscserEdit_3->currentIndex()+1)*ui->ciezarEdit_3->text().toInt()));
    ui->objetoscEdit_3->setText(QString::number((ui->iloscserEdit_4->currentIndex()+1)*(ui->iloscserEdit_4->currentIndex()+1)*ui->ciezarEdit_4->text().toInt()));
    ui->objetoscEdit_4->setText(QString::number((ui->iloscserEdit_5->currentIndex()+1)*(ui->iloscserEdit_5->currentIndex()+1)*ui->ciezarEdit_5->text().toInt()));
    ui->objetoscEdit_5->setText(QString::number((ui->iloscserEdit_6->currentIndex()+1)*(ui->iloscserEdit_6->currentIndex()+1)*ui->ciezarEdit_6->text().toInt()));
    ui->objetoscEdit_6->setText(QString::number((ui->iloscserEdit_7->currentIndex()+1)*(ui->iloscserEdit_7->currentIndex()+1)*ui->ciezarEdit_7->text().toInt()));
    ui->objetoscEdit_7->setText(QString::number((ui->iloscserEdit_8->currentIndex()+1)*(ui->iloscserEdit_8->currentIndex()+1)*ui->ciezarEdit_8->text().toInt()));
    ui->objetoscEdit_8->setText(QString::number((ui->iloscserEdit_9->currentIndex()+1)*(ui->iloscserEdit_9->currentIndex()+1)*ui->ciezarEdit_9->text().toInt()));
    ui->objetoscEdit_9->setText(QString::number((ui->iloscserEdit_10->currentIndex()+1)*(ui->iloscserEdit_10->currentIndex()+1)*ui->ciezarEdit_10->text().toInt()));
    ui->objetoscEdit_10->setText(QString::number((ui->iloscserEdit_11->currentIndex()+1)*(ui->iloscserEdit_11->currentIndex()+1)*ui->ciezarEdit_11->text().toInt()));
    ui->objetoscEdit_11->setText(QString::number((ui->iloscserEdit_12->currentIndex()+1)*(ui->iloscserEdit_12->currentIndex()+1)*ui->ciezarEdit_12->text().toInt()));
    ui->objetoscEdit_12->setText(QString::number((ui->iloscserEdit_13->currentIndex()+1)*(ui->iloscserEdit_13->currentIndex()+1)*ui->ciezarEdit_13->text().toInt()));

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
}



