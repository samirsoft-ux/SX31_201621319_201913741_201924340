#include "formwrong.h"
#include "ui_formwrong.h"
#include"ui_message.h"
#include "ui_users.h"
#include <QPixmap>
#include "calendar.h"
#include "friends.h"
#include "message.h"
#include "users.h"
#include "comentarios.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "queue.h"
#include "struct.h"
#include"avl.h"
#include "Publicaciones.h"
#include <vector>
#include <conio.h>
#include <string>
#include <string.h>
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


List<DATO> lst;//nombre, edad, ciudad
List<MENSAJE>lstMensaje;
using namespace std;
int contador=0;
int ct=1;
queue<int> qu(10);


FormWrong::FormWrong(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormWrong)
{
    ui->setupUi(this);

   connect(ui->BT_VerPublicacion,&QPushButton::clicked,this,&FormWrong::VerPublicaciones);
    QPixmap Upc("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/UPC_logo_transparente.png");
    int wUpc = ui->Picture->width();
    int hUpc = ui->Picture->height();
    ui->Picture->setPixmap(Upc.scaled(wUpc,hUpc,Qt::KeepAspectRatio));

    QPixmap Calendario("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/calendario.png");

    /*int wCalend = ui->Calendar->width();
    int hCalend = ui->Calendar->height();
    ui->Calendar->setPixmap(Calendario.scaled(wCalend,hCalend,Qt::KeepAspectRatio));*/

    QPixmap Amigos("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/amigos-1.png");

    /*int wFriends=ui->Friends->width();
    int hFriends=ui->Friends->height();
    ui->Friends->setPixmap(Amigos.scaled(wFriends,hFriends,Qt::KeepAspectRatio));*/

    QPixmap Home("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/home.png");

    /*int wHome=ui->Home->width();
    int hHome=ui->Home->height();
    ui->Home->setPixmap(Home.scaled(wHome,hHome,Qt::KeepAspectRatio));*/
    QPixmap Message("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/Imagenes/mensaje.png");

    //Imagen en buttons
    ui->HomeButton->setIcon(Home);
    ui->CalendarButton->setIcon(Calendario);
    ui->FriendsButton->setIcon(Amigos);
    ui->MensajesButton_2->setIcon(Message);

    //Leer archivo del Nick
    QFile fileNick("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/nick.txt");
    if(!fileNick.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    QTextStream inNick(&fileNick);
    QString textNick= inNick.readAll();
    fileNick.close();
    ui->Nombre->setText(textNick);

    //Leer archivo del codigo
    QFile fileCode("C:/Users/FLORES CAYETATANO/Desktop/ya funciona2/RedSocial(V 2.0) BackUp/code.txt");
    if(!fileCode.open(QFile::ReadOnly | QFile::Text)){
        return;
    }
    QTextStream inCode(&fileCode);
    QString textCode= inCode.readAll();
    fileCode.close();
    ui->Codigo->setText(textCode);
    char MENSAJERIA[20] = "MENSAJERIA";

    lstMensaje.load_file(MENSAJERIA);



        char Contacto[20] = "NEWCONTACTO";
          lst.load_file(Contacto);
          return ;

}

FormWrong::~FormWrong()
{
    delete ui;

    //página principal
}

int FormWrong::Indice(){
    return contador;

}
void FormWrong::VerPublicaciones(){

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
        int validar=Indice();

        if (p == nullptr||validar==10) return;
        QString titulo,desc,pubDate;
     QString orden;


        titulo = QString::fromStdString(p->getTitulo());
        desc = QString::fromStdString(p->getDesc());
        pubDate = QString::fromStdString(p->getPubDate());

        if(validar==0){
            QString s = QString::number(p->getIdPub());

           ui->txt_publicacion1->setPlainText(desc+"ID:"+s);
        }

            /*cout << setw(6) << p->getIdPub() << " || "
                   << setw(12) << p->getIdUser() << " || "
                   << setw(12) << p->getTitulo() << " || " //string
                   << setw(12) << p->getDesc() << " || "  //string
                   << setw(12) << p->getPubDate() << " || "  //string
                   << setw(12) << p->getNlikes() << endl;*/
        //ui->listWidget->addItem(QString::number(p->getIdPub())+"  "+titulo+"  "+desc+"  "+pubDate);
        //contador++;
    };


   idxPubDate->inOrder(print);
    delete idxPubDate;
    delete idxIdPub;
    delete idxIdUser;
    delete idxNlikes;

}
void FormWrong::on_HomeButton_clicked()
{

}
int FormWrong::SumarContador(){
    contador=contador+1;
    //contador++;
    return contador;
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



void FormWrong::on_MensajesButton_2_clicked()
{


    mensaje.setModal(true);
    mensaje.exec();
}

void FormWrong::on_NewUser_3_clicked()
{
    if(qu.size()>10){
        QMessageBox::warning(this,"Error","Muchos likes para la publicación");
    }else{
        qu.enqueue(ct);
        ct=ct+1;
    }
}



void FormWrong::on_MeGusta_clicked()
{

       // ui->label_3->setText(QString::number(qu.size()));
}


void FormWrong::on_MessageButton_clicked()
{

     tabla.setModal(true);
     tabla.exec();
}



void FormWrong::on_Bt_com_clicked()
{
    comentarios comentarios;
    comentarios.setModal(true);
    comentarios.exec();

}

void FormWrong::on_pushButton_clicked()
{
   /* ifstream file("data.tsv");

        if (!file.is_open()) {

            cerr << "No se pudo abrir el archivo";

        }

        bool titles = true;
        string email;
        string names;
        string lastname;
        string birthdate;
        string  height, city;
        while (getline(file, email, '\t')) {
            getline(file, names, '\t');
            getline(file, lastname, '\t');
            getline(file, birthdate, '\t');
            file >> height; file.get();
            getline(file, city);

            if (titles) {
                titles = false;
                continue;
            }

            cout << setw(20) << email
                << setw(15) << names
                << setw(15) << lastname
                << setw(12) << birthdate
                << setw(8) << height
                << setw(10) << city
                << endl;
        }
        file.close();*/
}
message::message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
    connect(ui->BT_VerListaAmigos,&QPushButton::clicked,this,&message::VerListaAmigos);
    connect(ui->BT_EnviarMensaje,&QPushButton::clicked,this,&message::EnviarMensaje);
    connect(ui->BT_VerMensaje,&QPushButton::clicked,this,&message::VerMensaje);
}

void message::VerMensaje(){
    QString nombres;
     char TEXT[500]=" ";
    MENSAJE mesage;
     nombres=ui->txt_NombreMensaje->text();

     char char_array[1000];
    strcpy(char_array,nombres.toStdString().c_str());
   strcpy(mesage.nombre,char_array);
    lstMensaje.Buscar(mesage,TEXT);
    ui->txt_VerMensajes->setPlainText(TEXT);
}
void message::EnviarMensaje(){
    char MENSAJERIA[20] = "MENSAJERIA";
        MENSAJE mensajito;
        QString mensaje,nombre;

        nombre=ui->txt_NombreMensaje->text();
        mensaje=ui->txt_EnviarMensaje->toPlainText();

        char char_array[1000];
       strcpy(char_array,nombre.toStdString().c_str());
      strcpy(mensajito.nombre,char_array);
        //const int d = ciudad.length();
        char char_array2[1000];
       strcpy(char_array2,mensaje.toStdString().c_str());
      strcpy(mensajito.mensaje,char_array2);
      lstMensaje.addLast(mensajito);
      lstMensaje.save_file(MENSAJERIA);

 ui->txt_EnviarMensaje->setPlainText("");







}

void message::VerListaAmigos(){
    char MENSAJE[500]=" ";
     lst.Mostrar(MENSAJE);
     ui->txt_ListaAmigos->setPlainText(MENSAJE);
}
void message::on_MessageButton_clicked()
{
    this->close();
}
message::~message()
{
    delete ui;
}







users::users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::users)
{
    ui->setupUi(this);
    connect(ui->BT_AgregarAmigo,&QPushButton::clicked,this,&users::AgregarAmigos);

}

users::~users()
{
    delete ui;
}


void users::AgregarAmigos(){
    DATO contacto;
        QString nombre,ciudad;
        int edad;

     nombre= ui->txt_AgregarNombre->text();
     ciudad= ui->txt_AgregarCiudad->text();
     edad= ui->txt_AgregarEdad->text().toInt();
     char char_array[1000];
    strcpy(char_array,nombre.toStdString().c_str());
   strcpy(contacto.nombre,char_array);
        char CONTACTO[20] = "NEWCONTACTO";
     //const int d = ciudad.length();
     char char_array2[1000];
    strcpy(char_array2,ciudad.toStdString().c_str());
   strcpy(contacto.ciudad,char_array2);
     contacto.edad=edad;
       lst.addLast(contacto);
      // lst.load_file(CONTACTO);
       lst.save_file(CONTACTO);
}
void users::on_MessageButton_clicked()
{
    this->close();
}
