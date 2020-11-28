#ifndef FORMFORGET_H
#define FORMFORGET_H

#include <QWidget>

namespace Ui {
class FormForget;
}

class FormForget : public QWidget
{
    Q_OBJECT

public:
    explicit FormForget(QWidget *parent = nullptr);
    ~FormForget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void volver();

private:
    Ui::FormForget *ui;
};

#endif // FORMFORGET_H
