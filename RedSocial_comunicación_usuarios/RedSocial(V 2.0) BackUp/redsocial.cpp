#include "redsocial.h"
#include "ui_redsocial.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

RedSocial::RedSocial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RedSocial)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(&FN);
    ui->stackedWidget->addWidget(&FF);
   // ui->stackedWidget->addWidget(&FW);  //Página principal
    connect(&FF,SIGNAL(volver()),this,SLOT(volverI()));
    connect(&FN,SIGNAL(volver()),this,SLOT(volverH()));
}

RedSocial::~RedSocial()
{
    delete ui;
}


void RedSocial::on_Login_clicked()
{
    QFile file("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/myfile.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","File not open");
    }
    QTextStream in(&file);
    QString text= in.readAll();
    file.close();

    QString displayValUser = ui->NombreUsuario->text();
    QString displayValPass= ui->Contrasena->text();
    QString total=displayValUser+displayValPass;
    if(displayValUser==""&&displayValPass==""){
        QMessageBox::warning(this,"Información no válida","Por favor verifique que su nombre de usuario o cantraseña sean correctos.");
    }else if (displayValUser==""||displayValPass==""){
        QMessageBox::warning(this,"Información no válida","Por favor verifique que su nombre de usuario o cantraseña sean correctos.");
    }else if(text==total){
        //ui->stackedWidget->setCurrentIndex(3);
        FW.show();
    }

}

void RedSocial::on_ForgetPass_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);

}

void RedSocial::on_NewUser_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//Para regresar a "iniciar sesión" de "olvido su pass"
void RedSocial::volverI(){
    ui->stackedWidget->setCurrentIndex(0);
}
//Para regresar a "iniciar sesión" de "registrarse"
void RedSocial::volverH(){
    ui->stackedWidget->setCurrentIndex(0);
}
