#include "mensaje.h"
#include "ui_mensaje.h"

mensaje::mensaje(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mensaje)
{
    ui->setupUi(this);
}

mensaje::~mensaje()
{
    delete ui;
}
void mensaje::on_HomeButton_clicked()
{
    this->close();
}

