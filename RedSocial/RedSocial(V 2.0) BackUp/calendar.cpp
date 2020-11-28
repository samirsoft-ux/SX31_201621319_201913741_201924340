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
List<int>* lst=new List<int>;
Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);

    QPixmap Upc("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/UPC_logo_transparente.png");
    int wUpc = ui->Picture->width();
    int hUpc = ui->Picture->height();
    ui->Picture->setPixmap(Upc.scaled(wUpc,hUpc,Qt::KeepAspectRatio));
    QPixmap Home("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/home.png");
    QPixmap Amigos("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/amigos-1.png");
    QPixmap Calendario("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/calendario.png");
    ui->HomeButton->setIcon(Home);
    ui->CalendarButton->setIcon(Calendario);
    ui->FriendsButton->setIcon(Amigos);

    //Leer archivo del Nick
    QFile fileNick("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/nick.txt");
    if(!fileNick.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    QTextStream inNick(&fileNick);
    QString textNick= inNick.readAll();
    fileNick.close();
    ui->Nombre->setText(textNick);

    //Leer archivo del codigo
    QFile fileCode("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/code.txt");
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
    delete lst;
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
    lst->addFirst(i);
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
    lst->removeFirst();
}



void Calendar::on_pushButton_clicked()
{
    ui->label->setText(QString::number(lst->size()));
}

void Calendar::on_EliminarUltimo_clicked()
{
    QList<QListWidgetItem*> items=ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item,items){
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
    lst->removeLast();
}
