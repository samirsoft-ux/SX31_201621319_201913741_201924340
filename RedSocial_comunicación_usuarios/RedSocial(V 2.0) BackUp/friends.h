#ifndef FRIENDS_H
#define FRIENDS_H

#include <QDialog>

namespace Ui {
class Friends;
}

class Friends : public QDialog
{
    Q_OBJECT

public:
    explicit Friends(QWidget *parent = nullptr);
    ~Friends();

private slots:
    void on_HomeButton_clicked();

    void on_EnviarSolicitud_clicked();

    void on_CancelarSolicitud_clicked();

    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

public:
    Ui::Friends *ui;
};

#endif // FRIENDS_H
