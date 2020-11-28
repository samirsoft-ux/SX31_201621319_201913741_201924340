#ifndef MENSAJE_H
#define MENSAJE_H

#include <QWidget>

namespace Ui {
class mensaje;
}

class mensaje : public QWidget
{
    Q_OBJECT

public:
    explicit mensaje(QWidget *parent = nullptr);
    ~mensaje();


private slots:
    void on_HomeButton_clicked();
    void on_MessageButton_clicked();
    void on_MessageButton_2_clicked();

private:
    Ui::mensaje *ui;


};

#endif // MENSAJE_H
