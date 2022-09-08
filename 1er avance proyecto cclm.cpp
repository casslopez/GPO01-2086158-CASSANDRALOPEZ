#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>

using namespace std;
int main()

{
    int numarti, opcion;
    float precio_uni,iva,preciof;
    string arti, descrip, cate;

    cout << "\t ***FUN STORE*** \n";
    cout << " 1.-Agregar Articulo \n 2.-Modificar Articulo\n 3.-Eliminar Articulo\n 4.-Lista Articulo\n 5.-Limpiar Pantalla\n 6.-Salir\n";
    cin >> opcion;

    switch (opcion)
    
    {
        
     case 1: //Agregar Articulo
        cout << "Ingrese el numero de articulo \n";
        cin >> numarti;
        cout << "Ingrese el nombre del articulo\n";
        cin.ignore();//No me tome el espacio 
        getline(cin, arti); //Permite ejecutar los espacios en la variable
        cout << "Ingrese el año de lanzamiento del articulo\n";
        cin.ignore();
        getline(cin, descrip);//Permite ejecutar los espacios en la variable
        cout << "Ingrese la clasificacion del articulo\n";
        cin.ignore();
        getline(cin, descrip);//Permite ejecutar los espacios en la variable
        cout << "Ingrese la categoria del articulo\n";
        cin.ignore();
        getline(cin, cate);//Permite ejecutar los espacios en la variable
        cout << "Ingrese la descripcion del articulo\n";
        cin.ignore();
        getline(cin, descrip);//Permite ejecutar los espacios en la variable
        cout << "Ingrese las caracteristicas del articulo\n";
        cin.ignore();
        getline(cin, descrip);//Permite ejecutar los espacios en la variable
        cout << "Ingrese el genero del articulo\n";
        cin.ignore();
        getline(cin, descrip);//Permite ejecutar los espacios en la variable
        cout << "Ingrese el precio unitario del articulo\n";
        cin >> precio_uni;
        iva=precio_uni*0.16;
        preciof=precio_uni+iva;
        cout << "El precio con IVA es de:"<<preciof;
        return main();
        break;

    case 2: //Modificar Articulo
        break;

    case 3://Eliminar Articulo
        break;

    case 4: //Lista de Articulos
        break;

    case 5: //Limpiar Pantalla
        system ("clear"); //clear  se utiliza en web para limpiar pantalla
        return main();
        break;

    case 6: //Salir
        cout << "Gracias por utilizar el programa \n";
        break;

    default:
        cout << "ingrese una opcion correcta \n";
        return main();

    }
}
