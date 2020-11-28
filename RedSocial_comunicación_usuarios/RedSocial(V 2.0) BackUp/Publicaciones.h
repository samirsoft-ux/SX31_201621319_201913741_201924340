#ifndef PUBLICACIONES_H
#define PUBLICACIONES_H
#include <string>

using std::string;

class Publicaciones {
    int idPub;
    int idUser;
    string titulo;
    string desc;
    string pubDate;
    int nlikes;
public:
    Publicaciones(int idPub = 0,
        int idUser = 0,
        string titulo = "",
        string desc = "",
        string pubDate = "",
        int nlikes = 0) : idPub(idPub), idUser(idUser), titulo(titulo), desc(desc), pubDate(pubDate), nlikes(nlikes) {}

    int getIdPub() { return idPub; }
    int getIdUser() { return idUser; }
    string getTitulo() { return titulo; }
    string getDesc() { return desc; }
    string getPubDate() { return pubDate; }
    int getNlikes() { return nlikes; }

    void setIdPub(int idPub) { this->idPub = idPub; }
    void setIdUser(int idUser) { this->idUser = idUser; }
    void setTitulo(string titulo) { this->titulo = titulo; }
    void setDesc(string desc) { this->desc = desc; }
    void setPubDate(string pubDate) { this->pubDate = pubDate; }
    void setNlikes(int nlikes) { this->nlikes = nlikes; }
};




#endif // PUBLICACIONES_H
