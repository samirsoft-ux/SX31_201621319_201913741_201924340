#ifndef FORMWRONG_H
#define FORMWRONG_H

#include <QWidget>
#include <message.h>
#include<users.h>
namespace Ui {
class FormWrong;
}

class FormWrong : public QWidget
{
    Q_OBJECT

public:
     message mensaje;
     users tabla;
    explicit FormWrong(QWidget *parent = nullptr);
    ~FormWrong();
public:
    // int contador=0;
public slots:


    void on_HomeButton_clicked();

    void on_CalendarButton_clicked();

    void on_FriendsButton_clicked();

    void on_FriendsButton_2_clicked();

    void on_MensajesButton_2_clicked();

    void on_NewUser_3_clicked();

    void on_EnviarSolicitud_clicked();

    void on_MeGusta_clicked();



    void on_comentarios_clicked();

    void on_MessageButton_clicked();

    void on_Bt_com_clicked();
    void view_publi();

    void on_pushButton_clicked();
    void VerPublicaciones();
    int Indice();
    int SumarContador();


public:
    Ui::FormWrong *ui;
    //Calendar *calendario;
};

#endif // FORMWRONG_H
