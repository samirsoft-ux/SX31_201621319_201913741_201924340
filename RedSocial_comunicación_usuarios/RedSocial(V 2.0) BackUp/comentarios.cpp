
#include "ui_comentarios.h"
#include "comentarios.h"
#include "formwrong.h"
#include "ui_formwrong.h"
#include <string>
#include <QMessageBox>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
using namespace std;
comentarios::comentarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comentarios)
{
    ui->setupUi(this);
}

comentarios::~comentarios()
{
    delete ui;
}

void comentarios::setDatosLog(QString renglon)
{
    QString contAnt;
    QString contAct;
    QFile log("log.txt");
    if(log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        contAnt.append(leer.readAll());
        log.close();
    }

    if(log.open(QIODevice::WriteOnly)){
        QTextStream escribir(&log);
        escribir<<contAnt;
        escribir<<renglon;
        log.close();
    }

    if(log.open(QIODevice::ReadOnly)){
        QTextStream leer(&log);
        contAct.append(leer.readAll());
        log.close();
    }

   ui->ver_com->setPlainText(contAct);

}


void comentarios::ComentarPubli(){
    string publicacion, comentario;
    Ui::FormWrong *ui_formwrong;
    //publicacion=ui_formwrong->publicacion1->toPlainText().toStdString();
    //comentario=ui->escribir_com->text().toStdString();
   // comentario=ui->EnviarComent->text().toStdString();
}

void comentarios::on_EnviarComent_clicked()
{

    QString nd;
    nd.append(QDateTime::currentDateTime().toString("hh mm ss"));
    nd.append(" ");
    nd.append(ui->escribir_com->text());
    nd.append("\n");

    setDatosLog(nd);
}

void comentarios::on_pushButton_clicked()
{
   this->close();
}
