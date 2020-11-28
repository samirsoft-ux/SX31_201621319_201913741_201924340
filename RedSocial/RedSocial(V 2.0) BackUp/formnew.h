#ifndef FORMNEW_H
#define FORMNEW_H

#include <QWidget>

namespace Ui {
class FormNew;
}

class FormNew : public QWidget
{
    Q_OBJECT

public:
    explicit FormNew(QWidget *parent = nullptr);
    ~FormNew();

private slots:
    void on_Registrarse_clicked();

signals:
    void volver();

private:
    Ui::FormNew *ui;
};

#endif // FORMNEW_H
