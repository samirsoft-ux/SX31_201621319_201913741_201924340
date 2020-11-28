#include "calendar.h"
#include "ui_calendar.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "list.h"
#include <QDebug>
#include <string>
#include <iostream>
//métodos de la lista

int i=1;
Lista<int>* lsta=new Lista<int>;
Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);

    QPixmap Upc("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/UPC_logo_transparente.png");
    int wUpc = ui->Picture->width();
    int hUpc = ui->Picture->height();
    ui->Picture->setPixmap(Upc.scaled(wUpc,hUpc,Qt::KeepAspectRatio));
    QPixmap Home("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUpImagenes/home.png");
    QPixmap Amigos("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/amigos-1.png");
    QPixmap Calendario("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/calendario.png");
    ui->HomeButton->setIcon(Home);
    ui->CalendarButton->setIcon(Calendario);
    ui->FriendsButton->setIcon(Amigos);

    //Leer archivo del Nick
    QFile fileNick("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/nick.txt");
    if(!fileNick.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    QTextStream inNick(&fileNick);
    QString textNick= inNick.readAll();
    fileNick.close();
    ui->Nombre->setText(textNick);

    //Leer archivo del codigo
    QFile fileCode("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/code.txt");
    if(!fileCode.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    QTextStream inCode(&fileCode);
    QString textCode= inCode.readAll();
    fileCode.close();
    ui->Codigo->setText(textCode);
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_HomeButton_clicked()
{
    this->close();
    delete lsta;
}

void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    ui->listWidget->clear();
    ui->EscribirAgregar->setText("");
    ui->Hora->displayFormat();
    i=1;
}

void Calendar::on_Agregar_clicked()
{
    lsta->addFirst(i);
    QString agregarTarea = ui->EscribirAgregar->text();
    QString agregarHora=ui->Hora->time().toString();
    QString s = QString::number(i);
    ui->listWidget->addItem(s+" "+agregarHora+" "+agregarTarea);
    i=i+1;
}
//Eliminar primero
void Calendar::on_Eliminar_clicked()
{
    QList<QListWidgetItem*> items=ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item,items){
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
    lsta->removeFirst();
}



void Calendar::on_pushButton_clicked()
{
    ui->label->setText(QString::number(lsta->size()));
}

void Calendar::on_EliminarUltimo_clicked()
{
    QList<QListWidgetItem*> items=ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item,items){
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
    lsta->removeLast();
}
