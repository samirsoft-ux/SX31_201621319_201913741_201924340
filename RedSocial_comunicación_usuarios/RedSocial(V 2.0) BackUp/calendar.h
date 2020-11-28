#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_HomeButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);
    void on_Agregar_clicked();

    void on_Eliminar_clicked();

    void on_pushButton_clicked();

    void on_EliminarUltimo_clicked();

    public:
    Ui::Calendar *ui;
};

#endif // CALENDAR_H
