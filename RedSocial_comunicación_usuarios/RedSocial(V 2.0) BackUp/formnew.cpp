#include "formnew.h"
#include "ui_formnew.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

FormNew::FormNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormNew)
{
    ui->setupUi(this);

}

FormNew::~FormNew()
{
    delete ui;
}

void FormNew::on_Registrarse_clicked()
{
    QString ValueUsuario=ui->Name->text();
    QString ValueContra=ui->CPass->text();
    QString Total=ValueUsuario+ValueContra;
    QFile file("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/myfile.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","File not open");
    }
    QTextStream out(&file);
    out<<Total;
    file.flush();
    file.close();

    QString ValueNick=ui->Nick->text();
    QFile fileNick("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/nick.txt");
    if(!fileNick.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","File not open");
    }
    QTextStream outNick(&fileNick);
    outNick<<ValueNick;
    file.flush();
    file.close();

    QString ValueCode=ui->Code->text();
    QFile fileCode("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/code.txt");
    if(!fileCode.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","File not open");
    }
    QTextStream outCode(&fileCode);
    outCode<<ValueCode;
    file.flush();
    file.close();
    if(ui->Pass->text()!=ui->CPass->text()){
        QMessageBox::warning(this,"Información no válida","Porfavor verifique que haya ingresado correctamente su contraseña.");
    }else if(ui->Name->text()==""||ui->Code->text()==""||ui->Nick->text()==""||ui->Pass->text()==""||ui->CPass->text()==""){
        QMessageBox::warning(this,"Información no válida","Porfavor rellene todos los campos.");
    }else{
        volver();
    }
}
