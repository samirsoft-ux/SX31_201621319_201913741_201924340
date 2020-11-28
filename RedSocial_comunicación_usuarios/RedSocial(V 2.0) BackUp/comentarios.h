#ifndef COMENTARIOS_H
#define COMENTARIOS_H
#include <QFile>
#include <QTextStream>
#include <QScrollBar>
#include <QDateTime>
#include <QDialog>

namespace Ui {
class comentarios;
}

class comentarios : public QDialog
{
    Q_OBJECT

public:
    explicit comentarios(QWidget *parent = nullptr);
    ~comentarios();
    void setDatosLog(QString renglon);



public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_EnviarComent_clicked();
    void ComentarPubli();

public:
    Ui::comentarios *ui;
};

#endif // COMENTARIOS_H
