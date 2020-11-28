#ifndef FORMWRONG_H
#define FORMWRONG_H

#include <QWidget>
//#include "calendar.h"
//#include "friends.h"

namespace Ui {
class FormWrong;
}

class FormWrong : public QWidget
{
    Q_OBJECT

public:
    explicit FormWrong(QWidget *parent = nullptr);
    ~FormWrong();

private slots:
    void on_HomeButton_clicked();

    void on_CalendarButton_clicked();

    void on_FriendsButton_clicked();

    void on_Btt_IgualA_clicked();

    void on_pushButton_clicked();

    void on_Btt_Recien_clicked();

    void on_Btt_Relevant_clicked();

    void on_PB_Ver_clicked();

private:
    Ui::FormWrong *ui;
    //Calendar *calendario;
};

#endif // FORMWRONG_H
