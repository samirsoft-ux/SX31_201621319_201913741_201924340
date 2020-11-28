#ifndef USERS_H
#define USERS_H

#include <QDialog>

namespace Ui {
class users;
}

class users : public QDialog
{
    Q_OBJECT

public:
    explicit users(QWidget *parent = nullptr);
    ~users();

private slots:
    void on_pushButton_clicked();

    void on_Mostrar_clicked();

    void on_MessageButton_clicked();
    void AgregarAmigos();
public:
    Ui::users *ui;
};

#endif // USERS_H
