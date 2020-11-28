#include "formforget.h"
#include "ui_formforget.h"
#include <QMessageBox>

FormForget::FormForget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForget)
{
    ui->setupUi(this);
}

FormForget::~FormForget()
{
    delete ui;
}

void FormForget::on_pushButton_clicked()
{
    QString displayValueCorr=ui->mail->text();
    if(displayValueCorr!=""){
        volver();
    }else{
        QMessageBox::warning(this,"Información no válida","Por favor vuelva a ingresar su correo electrónico e intentelo denuevo.");
    }

}

void FormForget::on_pushButton_2_clicked()
{
    volver();
}
