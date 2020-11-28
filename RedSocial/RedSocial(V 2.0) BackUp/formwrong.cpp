#include "formwrong.h"
#include "ui_formwrong.h"

#include <QPixmap>
#include "calendar.h"
#include "friends.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "avl.h"
#include "publicaciones.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int contadorMostrar = 0;
int visualizaciones = 0;
int likes = 0;

//------------------------------------------------------------------------
auto k1 = [](Publicaciones* p) { return p->getIdPub(); };
auto k2 = [](Publicaciones* p) { return p->getIdUser(); };
auto k3 = [](Publicaciones* p) { return p->getTitulo(); };
auto k4 = [](Publicaciones* p) { return p->getDesc(); };
auto k5 = [](Publicaciones* p) { return p->getPubDate(); };
auto k6 = [](Publicaciones* p) { return p->getNlikes(); };
AVLBST<Publicaciones*, int, nullptr>* idxIdPub =
        new AVLBST<Publicaciones*, int, nullptr>(k1);
AVLBST<Publicaciones*, int, nullptr>* idxIdUser =
        new AVLBST<Publicaciones*, int, nullptr>(k2);
AVLBST<Publicaciones*, string, nullptr>* idxTitulo =
        new AVLBST<Publicaciones*, string, nullptr>(k3);
AVLBST<Publicaciones*, string, nullptr>* idxDesc =
        new AVLBST<Publicaciones*, string, nullptr>(k4);
AVLBST<Publicaciones*, string, nullptr>* idxPubDate =
        new AVLBST<Publicaciones*, string, nullptr>(k5);
AVLBST<Publicaciones*, int, nullptr>* idxNlikes =
        new AVLBST<Publicaciones*, int, nullptr>(k6);

vector<Publicaciones*> pubs;
//-----------------------------------------------------------------------
bool loadData(string filename, vector<Publicaciones*>& pubs) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool titles = true;
    string title, desc, pubDate, idPub, idUser, nlikes;
    while (file >> idPub) {
        file.get();
        file >> idUser; file.get();
        getline(file, title, '\t');
        getline(file, desc, '\t');
        getline(file, pubDate, '\t');
        file >> nlikes; file.get();
        if (titles) {
            titles = false;
            continue;
        }
        /*pubs.push_back(new Pub(title, desc, pubDate,
            stoi(idPub), stoi(idUser), stoi(nlikes)));*/
        pubs.push_back(new Publicaciones(stoi(idPub), stoi(idUser), title, desc, pubDate, stoi(nlikes)));
    }
    file.close();
    return true;
}

FormWrong::FormWrong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormWrong)
{
    ui->setupUi(this);
    //-------------------------------------------------------------------------------------------------




    loadData("publications.tsv", pubs);

    for (auto al : pubs) {
        idxIdPub->add(al);
        idxIdUser->add(al);
        idxTitulo->add(al);
        idxDesc->add(al);
        idxPubDate->add(al);
        idxNlikes->add(al);
    }

    //
    auto print = [=](Publicaciones* p) {
        if (p == nullptr) return;
        QString titulo, desc, pubDate, numLikes;
        titulo = QString::fromStdString(p->getTitulo());
        desc = QString::fromStdString(p->getDesc());
        pubDate = QString::fromStdString(p->getPubDate());
        int nLikes=p->getNlikes();
        numLikes=QString::number(nLikes);
        if(contadorMostrar < 50){
            ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"\t"+desc+"\t"+pubDate+"\t"+numLikes);
            contadorMostrar++;
        }
    };

    idxIdPub->inOrder(print);
    contadorMostrar = 0;

    //-------------------------------------------------------------------------------------------------
    /*QPixmap Post("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/post.jpg");
    int wPost = ui->label->width();
    int hPost = ui->label->height();
    ui->label->setPixmap(Post.scaled(wPost,hPost,Qt::KeepAspectRatio));*/

    QPixmap Upc("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/UPC_logo_transparente.png");
    int wUpc = ui->Picture->width();
    int hUpc = ui->Picture->height();
    ui->Picture->setPixmap(Upc.scaled(wUpc,hUpc,Qt::KeepAspectRatio));

    QPixmap Calendario("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/calendario.png");

    /*int wCalend = ui->Calendar->width();
    int hCalend = ui->Calendar->height();
    ui->Calendar->setPixmap(Calendario.scaled(wCalend,hCalend,Qt::KeepAspectRatio));*/

    QPixmap Amigos("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/amigos-1.png");

    /*int wFriends=ui->Friends->width();
    int hFriends=ui->Friends->height();
    ui->Friends->setPixmap(Amigos.scaled(wFriends,hFriends,Qt::KeepAspectRatio));*/

    QPixmap Home("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/home.png");

    /*int wHome=ui->Home->width();
    int hHome=ui->Home->height();
    ui->Home->setPixmap(Home.scaled(wHome,hHome,Qt::KeepAspectRatio));*/
    //**********************************
    QPixmap Busqueda("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/search.png");
    ui->pushButton->setIcon(Busqueda);
    QPixmap Ordenar("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/order.png");
    ui->Btt_IgualA->setIcon(Ordenar);
    QPixmap like("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/Imagenes/like.png");
    ui->Btt_Relevant->setIcon(like);
    //**********************************
    //Imagen en buttons
    ui->HomeButton->setIcon(Home);
    ui->CalendarButton->setIcon(Calendario);
    ui->FriendsButton->setIcon(Amigos);

    //Leer archivo del Nick
    QFile fileNick("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/nick.txt");
    if(!fileNick.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    QTextStream inNick(&fileNick);
    QString textNick= inNick.readAll();
    fileNick.close();
    ui->Nombre->setText(textNick);

    //Leer archivo del codigo
    QFile fileCode("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/code.txt");
    if(!fileCode.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    QTextStream inCode(&fileCode);
    QString textCode= inCode.readAll();
    fileCode.close();
    ui->Codigo->setText(textCode);

    //*********
    ui->comboBox->addItem("Igual a             ");
    ui->comboBox->addItem("Inicia con          ");
    ui->comboBox->addItem("Finaliza con        ");
    ui->comboBox->addItem("Está contenido en   ");
    ui->comboBox->addItem("No está contenido en");
    //*********
    ui->CBB_Criterios->addItem("Recientemente publicadas");
    ui->CBB_Criterios->addItem("Con más likes           ");
    ui->CBB_Criterios->addItem("Más relevantes          ");
}

FormWrong::~FormWrong()
{
    delete ui;
    //página principal
}

void FormWrong::on_HomeButton_clicked()
{

}

void FormWrong::on_CalendarButton_clicked()
{
    //this->hide();
    Calendar calendario;
    calendario.setModal(true);
    calendario.exec();
    //calendario =new Calendar(this);
    //calendario->show();
    /*this->hide();
    Calendar calendario;
    calendario.setModal(true);
    calendario.exec();*/
}

void FormWrong::on_FriendsButton_clicked()
{
    Friends amigos;
    amigos.setModal(true);
    amigos.exec();
}

//+likes
void FormWrong::on_Btt_IgualA_clicked()
{
    ui->listWidget->clear();
    auto print = [=](Publicaciones* p) {
        if (p == nullptr) return;
        QString titulo, desc, pubDate, numLikes;
        titulo = QString::fromStdString(p->getTitulo());
        desc = QString::fromStdString(p->getDesc());
        pubDate = QString::fromStdString(p->getPubDate());
        int nLikes=p->getNlikes();
        numLikes=QString::number(nLikes);
        if(contadorMostrar < 50){
            ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"\t"+desc+"\t"+pubDate+"\t"+numLikes);
            contadorMostrar++;
        }
    };

    switch (ui->CBB_Criterios->currentIndex()) {
        case 0:
                idxPubDate->inOrderRev(print);
                contadorMostrar = 0;
                break;
        case 1: idxNlikes->inOrderRev(print);
                contadorMostrar = 0;
                break;
        case 2: idxIdUser->inOrderRev(print);
                contadorMostrar = 0;
                break;
    }
}

void FormWrong::on_pushButton_clicked()
{
    ui->listWidget->clear();

    QString busqueda = ui->LE_Filtrado->text();
    std::string str = busqueda.toStdString();
    str.c_str();

    auto printIgualA = [=](Publicaciones* p) {
        if (p == nullptr) return;
        QString titulo,desc,pubDate,numLikes;
        int nLikes;
        string palabraComparar = p->getTitulo();
        size_t found = palabraComparar.find(str);
        if(found != string::npos && str.size()==palabraComparar.size() && contadorMostrar < 50){
            titulo = QString::fromStdString(p->getTitulo());
            desc = QString::fromStdString(p->getDesc());
            pubDate = QString::fromStdString(p->getPubDate());
            nLikes=p->getNlikes();
            numLikes=QString::number(nLikes);
            ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"\t"+desc+"\t"+pubDate+"\t"+numLikes);

            contadorMostrar++;
        }
    };

    auto printEc = [=](Publicaciones* p){
        if (p == nullptr) return;
        QString titulo,desc,pubDate,numLikes;
        int nLikes;
        string palabraComparar = p->getTitulo();
        size_t found = palabraComparar.find(str);
        if(found != string::npos && contadorMostrar < 50){
            titulo = QString::fromStdString(p->getTitulo());
            desc = QString::fromStdString(p->getDesc());
            pubDate = QString::fromStdString(p->getPubDate());
            nLikes=p->getNlikes();
            numLikes=QString::number(nLikes);
            ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"\t"+desc+"\t"+pubDate+"\t"+numLikes);
            contadorMostrar++;
        }
    };

    auto printNoEc = [=](Publicaciones* p){
        if (p == nullptr) return;
        QString titulo,desc,pubDate,numLikes;
        int nLikes;
        string palabraComparar = p->getTitulo();
        size_t found = palabraComparar.find(str);
        if(found == string::npos && contadorMostrar < 50){
            titulo = QString::fromStdString(p->getTitulo());
            desc = QString::fromStdString(p->getDesc());
            pubDate = QString::fromStdString(p->getPubDate());
            nLikes=p->getNlikes();
            numLikes=QString::number(nLikes);
            ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"\t"+desc+"\t"+pubDate+"\t"+numLikes);
            contadorMostrar++;
        }
    };

    auto printIni = [=](Publicaciones* p){
        if (p == nullptr) return;
        QString titulo,desc,pubDate,numLikes;
        int nLikes;
        string palabraComparar = p->getTitulo();
        size_t found = palabraComparar.find(str);
        if(found != string::npos && found < 1 && contadorMostrar < 50){
            titulo = QString::fromStdString(p->getTitulo());
            desc = QString::fromStdString(p->getDesc());
            pubDate = QString::fromStdString(p->getPubDate());
            nLikes=p->getNlikes();
            numLikes=QString::number(nLikes);
            ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"\t"+desc+"\t"+pubDate+"\t"+numLikes);
            contadorMostrar++;
        }
    };

    auto printFin = [=](Publicaciones* p){
        if (p == nullptr) return;
        QString titulo,desc,pubDate,numLikes;
        int nLikes;
        char PFinal=p->getTitulo().back();
        string palabraComparar(1,PFinal);
        if(str==palabraComparar && contadorMostrar < 50){
            titulo = QString::fromStdString(p->getTitulo());
            desc = QString::fromStdString(p->getDesc());
            pubDate = QString::fromStdString(p->getPubDate());
            nLikes=p->getNlikes();
            numLikes=QString::number(nLikes);
            ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"\t"+desc+"\t"+pubDate+"\t"+numLikes);
            contadorMostrar++;
        }
    };

    switch (ui->comboBox->currentIndex()) {
        case 0: idxIdPub->inOrder(printIgualA);
                contadorMostrar = 0;
                break;
        case 1: idxIdPub->inOrder(printIni);
                contadorMostrar = 0;
                break;
        case 2: idxIdPub->inOrder(printFin);
                contadorMostrar = 0;
                break;
        case 3: idxIdPub->inOrder(printEc);
                contadorMostrar = 0;
                break;
        case 4: idxIdPub->inOrder(printNoEc);
                contadorMostrar = 0;
                break;
    }
}
//comentar
void FormWrong::on_Btt_Recien_clicked()
{
    QFile mFile("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/comentarios.txt");

    QString comentario = ui->LE_Comentar->text();
    QString linea=ui->listWidget->currentItem()->text();
    string lineas = linea.toStdString();
    string firstword = lineas.substr(0, lineas.find(" "));
    QString qstr = QString::fromStdString(firstword);
    QMessageBox::information(this,"Comentario","Se agrego correctamente su comentario a la publicacion con indice "+qstr);

    if(mFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&mFile);
        out << "idPub\tComment";
        out << qstr << '\t';
        out << comentario << '\t';
    }
    mFile.flush();
    mFile.close();

}
//likes
void FormWrong::on_Btt_Relevant_clicked()
{
    likes++;
    QFile mFile("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/likes.txt");

    QString linea=ui->listWidget->currentItem()->text();
    string lineas = linea.toStdString();
    string firstword = lineas.substr(0, lineas.find(" "));
    QString qstr = QString::fromStdString(firstword);
    QMessageBox::information(this,"Correcto","Se agrego correctamente su like a la publicacion con indice "+qstr);

    if(mFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&mFile);
        out << "idPub\tnumLik";
        out << qstr << '\t';
        out << likes << '\t';
    }
    mFile.flush();
    mFile.close();
}

void FormWrong::on_PB_Ver_clicked()
{
    visualizaciones++;
    QFile mFile("D:/Qt Projects/Trabajo Parcial/RedSocial/RedSocial(V 2.0) BackUp/visualizaciones.txt");

    QString linea=ui->listWidget->currentItem()->text();
    string lineas = linea.toStdString();
    string firstword = lineas.substr(0, lineas.find(" "));
    QString qstr = QString::fromStdString(firstword);
    QMessageBox::information(this,"Visualizar publicacion "+qstr,linea);
    if(mFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&mFile);
        out << "idPub\tnumDisp";
        out << qstr << '\t'; //id de la pub
        out << visualizaciones << '\t'; //numero de visualizaciones
    }

    mFile.flush();
    mFile.close();
}
