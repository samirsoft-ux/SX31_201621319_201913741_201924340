#include "friends.h"
#include "ui_friends.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "queue.h"

int c=1;
queue<int> q(10);
Friends::Friends(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Friends)
{
    ui->setupUi(this);
    ui->listWidget->addItem(QString::number(1)+". "+"Aaron Gonzalo Silva Silvera");
    ui->listWidget->addItem(QString::number(2)+". "+"Luz Iliana Silvera Herrera");
    ui->listWidget->addItem(QString::number(3)+". "+"Italo Gonzalo Silva Falcón");
    ui->listWidget->addItem(QString::number(4)+". "+"Vilma Herrera Palamino");
    ui->listWidget->addItem(QString::number(5)+". "+"Motta");
    QPixmap enviarSolicitud("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/enviarsolicitud.png");
    QPixmap cancelarSolicitud("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/cancelarsolicitud.png");
    ui->EnviarSolicitud->setIcon(enviarSolicitud);
    ui->CancelarSolicitud->setIcon(cancelarSolicitud);
    //-----------------------------------------------------------------------------------------
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

Friends::~Friends()
{
    delete ui;
}

void Friends::on_HomeButton_clicked()
{
    this->close();
}

void Friends::on_EnviarSolicitud_clicked()
{
    if(q.size()>10){
        QMessageBox::warning(this,"Error","Sobrepaso el limite de solicitudes enviadas por día.");
    }else{
        q.enqueue(c);
        c=c+1;
    }
}

void Friends::on_CancelarSolicitud_clicked()
{
    if(q.size()==0){
        QMessageBox::warning(this,"Error","No posee ninguna solicitud de amistad enviada.");
    }else{
        q.dequeue();
    }
}
//tamaño
void Friends::on_pushButton_clicked()
{
    ui->label->setText(QString::number(q.size()));
}
