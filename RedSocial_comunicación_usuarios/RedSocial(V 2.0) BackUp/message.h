#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDialog>

namespace Ui {
class message;
}

class message : public QDialog
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = nullptr);
    ~message();

public slots:
    void on_MessageButton_clicked();
    void VerListaAmigos();
    void EnviarMensaje();
    void VerMensaje();

public:
    Ui::message *ui;
};

#endif // MESSAGE_H
