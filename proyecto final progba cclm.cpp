
#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <locale.h> //libreria que permite caracteres en español como la "ñ"

using namespace std;
//declarar las variables

int * year, regi, * numa, sn, n=1;
float* impu, * preun, * total;
string* caracte, * descue, * nombre, * gene, * clasif;

void alta();
void listas();
void elimin();
void modi();
void archi();

int main() {
    setlocale(LC_ALL,"Spanish");
    int opc;
    do {
        printf("        FUN STORE        \n");
        printf("Ingrese la opcion que desee:\n");
        printf(" 1.-Agregar Articulo\n 2.-Modificar Articulo\n 3.-Eliminar Articulo\n 4.-Lista de Articulos vigentes\n 5.-Limpiar pantalla\n 6.-Salir\n");
        scanf_s("%d", &opc);

        switch (opc) 
        {
        case 1://agregar articulo
            alta();
            system("pause");
            return main();
            break;
        case 2://modificar articulo
            modi();
            system("pause");
        return main();
        break;

        case 3://eliminar articulo
            elimin();
            system("pause");
        return main();
        break;

        case 4://lista de articulos
            listas();
            system("pause");
        return main();
        break;

        case 5://limpiar pantalla
            system("cls");
        return main();
        break;

        case 6://salir
            archi();
            exit(1);
        break;

        default:
            printf("Opcion incorrecta\n");
            return main();
        }
    } while (opc != 6);
}


void alta() {
    sn = 0;
    printf("ingresa la cantidad de registros\n");
    scanf_s("%d", &regi);
    year = new int[regi];
    numa = new int[regi];
    impu = new float[regi];
    preun = new float[regi];
    total = new float[regi];
    caracte = new string[regi];// se usa new para asignarle memoria dinamica a los punteros
    descue = new string[regi];
    nombre = new string[regi];
    gene = new string[regi];
    clasif = new string[regi];
    
    for (int i = 0; i < regi; i++) 
    
    {
        printf("ingresa el numero de articulo\n");
        scanf_s("%d", &numa[i]);
        
        if (i > 0) 
        {
            do {
                if (numa[i] == numa[i - n]) {
                    printf("ingrese otro numero de articulo\n");
                    scanf_s("%d", &numa[i]);
                }
                else {
                    n = n + 1;
                }
            } while (n < regi);
        }
        printf("ingresa el año de lanzamiento\n");
        scanf_s("%d", &year[i]);
        printf("ingresa el nombre del videojuego\n");
        cin.ignore();
        getline(cin, nombre[i]);
        printf("ingresa la clasificacion *Mantenga un mismo formato al ingresar los datos*\n");
        getline(cin, clasif[i]);
        printf("ingresa las caracteristicas\n");
        getline(cin, caracte[i]);
        printf("ingresa la descripcion\n");
        getline(cin, descue[i]);
        printf("ingresa el genero *Mantenga un mismo formato al ingresar los datos*\n");
        getline(cin, gene[i]);
        printf("ingresa el precio unitario\n");
        scanf_s("%f", &preun[i]);
        impu[i] = preun[i] * .16;
        printf("El impuesto es de %f\n", impu[i]);
        total[i] = preun[i] + impu[i];
        printf("El total es de %f\n", total[i]);
        if ((regi - 1) == i) {
            do {
                printf("¿Desea agregar otro articulo?\n 1.si\n 2.no\n");
                scanf_s("%d", &sn);
                if (sn == 1) {
                    regi = regi + 1;
                }
            } while (sn != 1 && sn!=2);
        }
    }
}

void listas() {
    int op1;
    string bus;
    do {
        printf("1.Clasificacion\n 2.Genero\n 3.Salir\n");
        scanf_s("%d", &op1);
        switch (op1) {
        case 1:
            printf("ingrese la clasificacion a buscar\n");
            cin.ignore();
            getline(cin, bus);
            for (int i = 0; i < regi; i++) {
                if (bus == clasif[i] && numa[i] != 0) {
                    printf("el numero de articulo: %d\n", numa[i]);
                    printf("nombre del videojuego: %s\n", nombre[i].c_str());
                    printf("año de lanzamiento: %d\n", year[i]);
                    printf("la clasificacion: %s\n", clasif[i].c_str());
                    printf("la caracteristicas: %s\n", caracte[i].c_str());
                    printf("la descripcion: %s\n", descue[i].c_str());
                    printf("el genero: %s\n", gene[i].c_str());
                    printf("el precio unitario: %f \n", preun[i]);
                    printf("el impuesto es de: %f \n", impu[i]);
                    printf("el total es: %f \n", total[i]);
                }
            }
            break;
        case 2:
            printf("ingrese el genero a buscar\n");
            cin.ignore();
            getline(cin, bus);
            for (int i = 0; i < regi; i++) {
                if (bus == gene[i] && numa[i] != 0) {
                    printf("el numero de articulo: %d\n", numa[i]);
                    printf("nombre del videojuego: %s\n", nombre[i].c_str());
                    printf("año de lanzamiento: %d\n", year[i]);
                    printf("la clasificacion: %s\n", clasif[i].c_str());
                    printf("la caracteristicas: %s\n", caracte[i].c_str());
                    printf("la descripcion: %s\n", descue[i].c_str());
                    printf("el genero: %s\n", gene[i].c_str());
                    printf("el precio unitario: %f \n", preun[i]);
                    printf("el impuesto es de: %f \n", impu[i]);
                    printf("el total es: %f \n", total[i]);;
                }
            }
            break;
        case 3:
            break;
        default:
            printf("ingresa una opcion correta\n");
            break;
        }
    } while (op1 != 3);
}

void elimin() {
    int eliminar,no=0;
    do {
        printf("ingrese el numero de articulo a eliminar\n");
        scanf_s("%d", &eliminar);
        for (int i = 0; i < regi; i++) {
            if (eliminar == numa[i]) {
                numa[i] = 0;
                no = no + 1;
            }
        }
        if (no == 0) {
            printf("Numero de articulo no existe\n");
        }
    } while (no == 0);
}

void modi() {
    int modifi, opcion;
    do {
        printf("ingrese el numero de articulo a modificar\n");
        scanf_s("%d", &modifi);
    } while (modifi < 0);
    do {
        printf("¿Que desea modificar?\n1.Numero de articulo\n2.Nombre del videojuego\n3.Año de lanzamiento\n4.Clasificacion\n5.Caracteristicas\n6.Descripcion\n7.Genero\n8.Precio unitario\n9.Salir\n");
        scanf_s("%d", &opcion);
        switch (opcion) 
        {
        case 1:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    scanf_s("%d", &numa[i]);
                }
            }
            break;
        case 2:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, nombre[i]);
                }
            }
            break;
        case 3:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    scanf_s("%d", &year[i]);
                }
            }
            break;
        case 4:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, clasif[i]);
                }
            }
            break;
        case 5:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, caracte[i]);
                }
            }
            break;
        case 6:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, descue[i]);
                }
            }
            break;
        case 7:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    cin.ignore();
                    getline(cin, gene[i]);
                }
            }
            break;
        case 8:
            for (int i = 0; i < regi; i++) {
                if (modifi == numa[i]) {
                    printf("ingresa el nuevo dato\n");
                    scanf_s("%d", &preun[i]);
                    impu[i] = preun[i] * .16;
                    total[i] = preun[i] + impu[i];
                }
            }
            break;
        case 9://salir
            break;
        default:
            printf("Ingrese una opcion correcta\n");
            break;
        }
    } while (opcion != 9);

}

void archi() {
    ofstream archivo;
    string nombres;
    nombres = "LISTAS FUN STORE";
    archivo.open(nombres.c_str(), ios::out);

    if (archivo.fail()) {
        printf("ERROR AL CREAR ARCHIVO\n");
        system("pause");
        exit(1);
    }
    archivo << "Se seguira este formato" << "\n";
    archivo << "Numero de articulo" << "\t";
    archivo << "Nombre del videojuego" << "\t";
    archivo << "Año de lanzamiento" << "\t";
    archivo << "Clasificacion" << "\t";
    archivo << "Caracteristicas" << "\t";
    archivo << "Descripción" << "\t";
    archivo << "Genero" << "\t";
    archivo << "Precio unitario" << "\t";
    archivo << "Impuesto" << "\t";
    archivo << "Total" << "\n";
    for (int i = 0; i < regi; i++) {
        archivo << numa[i] << "\t";
        archivo << nombre[i].c_str() << "\t";
        archivo << year[i] << "\t";
        archivo << clasif[i].c_str() << "\t";
        archivo << caracte[i].c_str() << "\t";
        archivo << descue[i].c_str() << "\t";
        archivo << gene[i].c_str() << "\t";
        archivo << preun[i] << "\t";
        archivo << impu[i] << "\t";
        archivo << total[i] << "\n";

    }
}
