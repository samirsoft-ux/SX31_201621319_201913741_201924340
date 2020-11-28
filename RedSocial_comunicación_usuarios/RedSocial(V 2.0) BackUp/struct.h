#ifndef STRUCT_H
#define STRUCT_H
#include"Lista.h"
struct datos {
    char nombre[30];
    int edad;
    char ciudad[30];
    void Mostrar() {
    printf("\n _______ENCONTRADO__________");
    printf("\n Nombre......: %s", nombre);
    printf("\n Edad........: %i", edad);
    printf("\n Ciudad......: %s", ciudad);
    printf("\n ____________________________");
    }
};
typedef struct datos DATO;

struct mensaje {
    char mensaje[200];
    char nombre[30];
   // void Mostrar() {
     // printf("\n Mensaje......: %s", mensaje);
   // }

};
typedef struct mensaje MENSAJE;


struct Usuario{
    char ID[30];
    char clave[30];
    char nombre[30];
    int edad;
    char ciudad[30];
    char Sexo[30];
    void Mostrar() {

        printf("\n Nombre......: %s",nombre);
        printf("\n Nombre......: %i", edad);
        printf("\n Nombre......: %s", nombre);

    }
   bool Login(char* otroid,char* otraclave)
    {
       if (strcmp(ID, otroid) == 0 && strcmp(clave, otraclave)) {
           return true;
       }
       else
           return false;
    }
};
typedef struct Usuario USUARIO;

struct Estado {
    char mensaje[300];
    void Mostrar() {
        printf("\n MI ESTADO......: %s", mensaje);
    }
};
typedef struct Estado ESTADO;
#endif // STRUCT_H
