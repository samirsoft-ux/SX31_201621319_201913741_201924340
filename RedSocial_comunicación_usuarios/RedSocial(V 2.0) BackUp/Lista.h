#ifndef LISTA_H
#define LISTA_H
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>

using namespace std;
template <typename Tipo>
class List {
    struct Node;

    Node* head;
    int     len;
public:
    List() : head(NULL), len(0) {}
    ~List();

    int     size();
    bool    empty();

    void    addFirst(Tipo elem);
    void    addPos(Tipo elem, int pos);
    void    addLast(Tipo elem);

    void    removeFirst();
    void    Eliminar(Tipo elem);
    void    removePos(int pos);
    void    removeLast();

    void    editFirst(Tipo elem);
    void    editPos(Tipo elem, int pos);
    void    editLast(Tipo elem);
    void    EliminarMensaje(Tipo elem);
    //El editar seria, como agregar, si es igual
    Tipo   getFirst();
    Tipo   get(int pos);
    Tipo   getLast();
    int BuscarPosicion(Tipo elem);
    int     find(Tipo elem);
    void Buscar(Tipo elem, char*men);
    int* findAll(Tipo elem);
    //**********PARA CARGA Y LECTURA DE DATOS DESDE EL FILE************POR IMPLEMENTAR
  void load_file(char*); //string sera el nombre del archivo para cargar a la Lista enlazada
  void save_file(char*);
  //string sera el nombre del archivo a crear con elementos de la lista enlazada
    void Mostrar(char *n);
    bool ValidarCuenta(Tipo elem);
};

template <typename Tipo>
struct List<Tipo>::Node {
    Tipo elem;
    Node* next;
    Node(Tipo elem, Node* next = NULL) : elem(elem), next(next) {}


};


template <typename Tipo>
List<Tipo>::~List() {
    while (head != NULL) {
        Node* aux = head;
        head = head->next;
        delete aux;
    }
}

template <typename Tipo>
int     List<Tipo>::size() {
    return len;
}

template <typename Tipo>
bool    List<Tipo>::empty() {
    return len == 0;
}

template <typename Tipo>
void    List<Tipo>::addFirst(Tipo elem) {
    head = new Node(elem, head);
    ++len;
}

/*template <typename Tipo>
void    List<Tipo>::addPos(Tipo elem, int pos) {
    if (pos < 0 || pos > len) return;
    if (pos == 0) {
        addFirst(elem);
    }
    else {
        Node* aux = head;
        for (int i = 1; i < pos; ++i) {
            aux = aux->next;
        }
        aux->next = new Node(elem, aux->next);
        ++len;
    }
}*/
template <typename Tipo>
void    List<Tipo>::addPos(Tipo elem, int pos) {
    if (pos < 0 || pos > len) return;
    if (pos == 0) {
        addFirst(elem);
    }
    else {
        Node* aux = head;
        for (int i = 1; i < pos; ++i) {
            aux = aux->next;
        }
        aux->next = new Node(elem, aux->next);
        ++len;
    }
}

template <typename Tipo>
void    List<Tipo>::addLast(Tipo elem) {
    addPos(elem, len);
}


template <typename Tipo>
void    List<Tipo>::removeFirst() {
    if (len > 0) {
        Node* aux = head;
        head = head->next;
        delete aux;
        --len;
    }
}

template <typename Tipo>
void    List<Tipo>::removePos(int pos) {
    //if (pos < 0 || pos >= len) return;
    if (pos == 0) {
        removeFirst();
    }
    else {
        Node* aux = head;
        for (int i = 1; i < pos; ++i) {
            aux = aux->next;
        }
        Node* aux2 = aux->next;
        aux->next = aux2->next;
        delete aux2;
        --len;
    }
}

template <typename Tipo>
void    List<Tipo>::removeLast() {
    removePos(len - 1);
}

template <typename Tipo>
void    List<Tipo>::editFirst(Tipo elem) {
    if (len > 0) {
        head->elem = elem;
    }
}

template <typename Tipo>
void    List<Tipo>::editPos(Tipo elem, int pos) {
    if (pos < 0 || pos >= len) return;
    Node* aux = head;
    for (int i = 0; i < pos; ++i) {
        aux = aux->next;
    }
    aux->elem = elem;
}

template <typename Tipo>
void    List<Tipo>::editLast(Tipo elem) {
    editPos(elem, len - 1);
}

template <typename Tipo>
Tipo   List<Tipo>::getFirst() {
    if (len > 0) {
        return head->elem;
    }
    else {
        -.0;
    }
}

template <typename Tipo>
Tipo   List<Tipo>::get(int pos) {
    if (pos < 0 || pos >= len) - .0;
    Node* aux = head;
    for (int i = 0; i < pos; ++i) {
        aux = aux->next;
    }
    return aux->elem;
}

template <typename Tipo>
Tipo   List<Tipo>::getLast() {
    return get(len - 1);
}

template <typename Tipo>
int     List<Tipo>::find(Tipo elem) {

    Node* aux = head;
    for (int i = 0; i < len; ++i) {

        if (strcmp(aux->elem.nombre,elem.nombre)) {
            //aux->elem.Mostrar();
            return i;
        }
        aux = aux->next;
    }
    return -1;
}
template <typename Tipo>
void    List<Tipo>::Buscar(Tipo elem, char *men) {

    Node* aux = head;

    for (int i = 0; i < len; ++i) {
//strncat(n, aux->elem.mensaje+"\n",5000);
        if (strcmp(aux->elem.nombre, elem.nombre)==0) {
        strncat(men,   aux->elem.mensaje,5000);
                strncat(men,  "\n",5000);


        }
        aux = aux->next;
    }

}
template <typename Tipo>
void    List<Tipo>::EliminarMensaje(Tipo elem) {

    Node* aux = head;

    for (int i = 0; i < len; i++) {

        if (strcmp(aux->elem.nombre, elem.nombre) == 0) {
           // aux->elem.Mostrar();
            removePos(i);

        }
        aux = aux->next;
    }

}
template <typename Tipo>
int   List<Tipo>::BuscarPosicion(Tipo elem) {

    Node* aux = head;
    int contador = 0;
    for (int i = 0; i < len; ++i) {

        if (strcmp(aux->elem.nombre, elem.nombre) == 0) {
           // aux->elem.Mostrar();

            break;//para romper el bucle
        }
        aux = aux->next;
        contador++;
    }
    return contador;
}

template <typename Tipo>
void List<Tipo>::load_file (char* file)
{//file nombre del archivo bdinario

    FILE* fich;

   if (( fich = fopen(file, "rb")) == NULL) {
       printf("\n Fichero no existe ");return;
    }


        Tipo elem;
        fread(&elem, sizeof(elem), 1, fich);

        while (!feof(fich)) {


            addFirst(elem);


            fread(&elem, sizeof(elem), 1, fich);

        }
        fclose(fich);





}

template <typename Tipo>

bool List<Tipo>::ValidarCuenta(Tipo elem)
{
    Node* aux = head;
    bool validar;
    int contador = 0;
   for (int i = 0; i < len; ++i)
   {

       if (strcmp(aux->elem.ID, elem.ID) == 0) {
           // aux->elem.Mostrar();
          ++ contador;


       }
       aux = aux->next;
   }

   if (contador > 0)
   {
       validar = true;
   }
   else {
       validar = false;
   }
        /*

        if (aux->elem.Login(elem.ID, elem.clave)==true) {
            //validar = true;

           // break;//para romper el bucle
            ya = true;
            cout << " Es verdadero";
        }
        else {
            ya = false;
        }*/

    return validar;

}

template<typename Tipo>
void List<Tipo>::save_file(char* file)//file es el nombre del archivo
{
   FILE* fich;
   fich = fopen(file,"wb");
    //cout << file<<"nOMBRE DEL arihivo"<<endl;


        //cout << "ENTRO AL Else" << endl;
        Node* aux2 = head;
        while (head != NULL)
        {

            Node* aux = head;
            fwrite(&aux->elem, sizeof(aux->elem), 1, fich);
            head = head->next;
        }
        //cout << "Esta saliendo" << endl;
        fclose(fich);
        head = aux2;


}


template <typename Tipo>
int* List<Tipo>::findAll(Tipo elem) {
    return NULL;
}

template <typename Tipo>
void List<Tipo>::Mostrar(char*n) {
    Node* aux2 = head;
    while (head != NULL)
    {
//1000 tamño de caracteres
        Node* aux = head;
       strncat(n, aux->elem.nombre,5000);
         strncat(n, "\n",5000);
        head = head->next;
    }
    head = aux2;
   // char funcion(char *n) {
     //  strncat(n,"ever",1000);
      // return *n



}
#endif // LISTA_H
