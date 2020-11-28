#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include <QMainWindow>
#include <formforget.h>
#include <formnew.h>
#include <formwrong.h>

QT_BEGIN_NAMESPACE
namespace Ui { class RedSocial; }
QT_END_NAMESPACE

class RedSocial : public QMainWindow
{
    Q_OBJECT

public:
    RedSocial(QWidget *parent = nullptr);
    ~RedSocial();

private slots:
    void on_Login_clicked();

    void on_ForgetPass_clicked();

    void on_NewUser_clicked();

    void volverI();

    void volverH();

public:
    Ui::RedSocial *ui;
    FormNew FN;
    FormForget FF;
    FormWrong FW; //PáginaPrincipal
};
#endif // REDSOCIAL_H
