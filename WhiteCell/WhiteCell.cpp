
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{

    string username;
    string databaserecord;
    string personaldatarecord;
    char Eleccion;
    int i=0;
    int i2=0;

Inicio:
    system("CLS");
    fstream InfoFile("database.txt",ios::in);

    if (InfoFile.fail()) {

        if (i != 1) {
            i++;
            fstream InfoFile("database.txt", ios::app);

            InfoFile.close();
            goto Inicio;
        }

        cout << "El archivo no se puede abrir, pulse cualquier tecla para reintentar.";
        cin.ignore();

        fstream InfoFile("database.txt", ios::app);

        InfoFile.close();
        goto Inicio;

    }
    i = 0;
    cout << "Introduce el nombre de a quien desees buscar\n";
    getline(cin, username);

    

    while (getline(InfoFile, databaserecord)) {

        if (username == databaserecord) {

                    
            cout << "Se ha encontrado el usuario " + databaserecord + " en la base de datos\n-------------------------------------------\n";
            getline(InfoFile, databaserecord); 
            cout << databaserecord << "\n-------------------------------------------\n";
            

            cin.ignore();
            system("CLS");
            goto Inicio;
        }
        i++;
    }
    InfoFile.close();
    InfoFile.open("database.txt", ios::app);
    if (username!=databaserecord){
    
        cout << "No se ha encontrado el usuario " + username + " en la base de datos\nDesea registrarlo? [Y/N]\n";
        cin >> Eleccion;


        if (Eleccion == 'Y') {
            
            cout << "Introduce información personal si lo desea=\n";


            string TemInfo;
            
            getline(cin>>ws,TemInfo);

            InfoFile << username << "\n:" << TemInfo << "\n";
            username = "";
        }

    }
    InfoFile.close();
    cin.ignore();
    system("CLS");
    goto Inicio;
    









}
