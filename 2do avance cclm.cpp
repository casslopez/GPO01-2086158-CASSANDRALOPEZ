#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdio.h>


using namespace std;

struct tienda {
    int numa;
    float pun;
    float imp;
    float tot;
    int a;

    string clas;
    string carac;
    string desc;
    string gen;
    string nom;
};

int main()
{
    tienda bd[3] = { 0 };//arreglo de la estructura
    int opc = 0, op = 0, busq , s ;//se usa para menejar los switch y la busqueda
    string bus;
    do
    {
        printf("    *** FUN STORE ***        \n");
        printf("Ingrese la opcion que desee\n");
        printf(" 1.-Agregar Articulo\n 2.-Modificar Articulo\n 3.-Eliminar Articulo\n 4.-Lista de Articulos vigentes\n 5.-Limpiar pantalla\n 6.-Salir\n");
        scanf_s("%d", &opc);

        switch (opc)
        {

        case 1://agregar articulo

            for (int i = 0; i < 3; i++) {
                do {
                    printf("ingresa el numero de articulo\n");
                    scanf_s("%d", &bd[i].numa);
                    if (bd[i].numa == bd[i - 1].numa || bd[i].numa == bd[i - 2].numa)
                    {
                        printf("el numero de articulo ya existe \n");

                    }
                    else
                    {
                        s = 2;
                    }
                } 
                while (s == 1);
                printf("ingresa el nombre del videojuego\n");
                cin.ignore();
                getline(cin, bd[i].nom);
                printf("ingresa el A%co de lanzamiento\n", 164);
                scanf_s("%d", &bd[i].a);
                printf("ingresa la clasificacion\n");
                cin.ignore();
                getline(cin, bd[i].clas);
                printf("ingresa las caracteristicas\n");
                getline(cin, bd[i].carac);
                printf("ingresa la descripcion\n");
                getline(cin, bd[i].desc);
                printf("ingresa el genero\n");
                getline(cin, bd[i].gen);
                printf("ingresa el precio unitario\n");
                scanf_s("%f", &bd[i].pun);
                bd[i].imp = bd[i].pun * .16;
                printf("El impuesto es de %f\n", bd[i].imp);

                bd[i].tot = bd[i].pun * 1.16;
                printf("El total es de %f\n", bd[i].tot);
            }

            break;
            
        case 2://modificar articulo
            printf("ingrese el numero de articulo que desea modificar\n");
            scanf_s("%d", &busq);

            for (int i = 0; i < 3; i++) {
                if (busq == bd[i].numa) {
                    printf("ingresa el nombre del videojuego\n");
                    cin.ignore();
                    getline(cin, bd[i].nom);
                    printf("ingresa el A%co de lanzamiento\n", 164);
                    scanf_s("%d", &bd[i].a);
                    printf("ingresa la clasificacion\n");
                    cin.ignore();
                    getline(cin, bd[i].clas);
                    printf("ingresa las caracteristicas\n");
                    getline(cin, bd[i].carac);
                    printf("ingresa la descripcion\n");
                    getline(cin, bd[i].desc);
                    printf("ingresa el genero\n");
                    getline(cin, bd[i].gen);
                    printf("ingresa el precio unitario\n");
                    scanf_s("%f", &bd[i].pun);
                    bd[i].imp = bd[i].pun * .16;
                    printf("El impuesto es de %f\n", bd[i].imp);
                    bd[i].tot = bd[i].pun * 1.16;
                    printf("El total es de %f\n", bd[i].tot);
                }
            }
            break;
            
        case 3://eliminar articulo
           
           
            printf("ingrese el numero de articulo que deseea eliminar\n");
            scanf_s("%d", &busq);
            busq = busq - 1;
            for (int i = busq; i == busq; i++)
            {
                
                    bd[i].numa = 0;
                    bd[i].pun = 0;
                    bd[i].imp = 0;
                    bd[i].tot = 0;
                    bd[i].a = 0;
                    bd[i].clas = " ";
                    bd[i].carac= " ";
                    bd[i].desc= " ";
                    bd[i].gen= " ";
                    bd[i].nom= " ";
                }
            break;
            
        case 4://lista de articulos
            do
            {
                
                printf("seleccione la opcion que desee ver\n 1.-clasificacion\n 2.-Genero\n 3.-Todos\n 4.-volver al menu principal\n");
                scanf_s("%d", &op);
                switch (op)
                {
                case 1://clasificacion
                   
                  for (int i = 0; i < 3; i++)
                    {
                        if (bd[i].numa == 0)
                        {
                            printf("Articulo eliminado\n");
                            printf("---------------------------------------------------------------------------------------- \n");
                        }
                        else
                        {
                            
                            printf("el numero de articulo: %d\n", bd[i].numa);
                             
                            printf("la clasificacion: %s\n", bd[i].clas.c_str());
                           
                            printf("---------------------------------------------------------------------------------------- \n");
                        }
                    }
                    break;
                    
                case 2://genero
                   
                    for (int i = 0; i < 3; i++) 
                    {

                        if (bd[i].numa == 0)
                        {
                            printf("Articulo eliminado\n");
                            printf("---------------------------------------------------------------------------------------- \n");
                        }
                        else
                        {
                            
                            printf("el numero de articulo: %d\n", bd[i].numa);
                          
                            printf("el genero: %s\n", bd[i].gen.c_str());
                            
                            printf("---------------------------------------------------------------------------------------- \n");
                        }
                    }
                    break;
                    
                case 3:
                    for (int i = 0; i < 3; i++) 
                    {

                        if (bd[i].numa == 0)
                        {
                            printf("Articulo eliminado\n");
                            printf("---------------------------------------------------------------------------------------- \n");
                        }
                        else
                        {
                            printf("el numero de articulo: %d\n", bd[i].numa);
                            printf("nombre del videojuego: %s\n", bd[i].nom.c_str());
                            printf("a%co de lanzamiento: %d\n", 164, bd[i].a);
                            printf("la clasificacion: %s\n", bd[i].clas.c_str());
                            printf("la caracteristicas: %s\n", bd[i].carac.c_str());
                            printf("la descripcion: %s\n", bd[i].desc.c_str());
                            printf("el genero: %s\n", bd[i].gen.c_str());
                            printf("el precio unitario: %f \n", bd[i].pun);
                            printf("el impuesto es de: %f \n", bd[i].imp);
                            printf("el total es: %f \n", bd[i].tot);
                            printf("---------------------------------------------------------------------------------------- \n");
                        }
                    }
                    break;
                case 4:
                
                    printf("volviendo...");
                    break;
                default:
                    printf("ingrese una opcion correcta\n");
                    break;
                }
            } while (op != 4);
            break;

        case 5://limpiar pantalla
            system("cls");
            break;
            
        case 6://salir
            printf("saiendo...");
            exit(1);
            break;
        default:
            printf("ingrese una opcion correcta\n");
            break;
        }

    } 
    
    while (opc != 6);
    system("pause");

}