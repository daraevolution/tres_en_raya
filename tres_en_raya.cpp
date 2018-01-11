/**************************************\ Juegos simple en C++: Tres en raya(gato) *Creado el 19/11/16-5:40PM * * * 
 * \**************************************/ 
#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include <time.h> 

using namespace std;

void loop(char c[3][3]);
void Intro_primero(char c[3][3]); 
void tablero(char c[3][3]); 
void Intro_Yo(char c[3][3]); 
void Intro_IA(char c[3][3]); 
int Ganador(char c[3][3]);

int main()
{ 
    char c[3][3]; //tablero 
    loop(c); //llaman a todas las funciones fundamentales y hace un refresco de pantalla 
    cout << "\n"; 
    system ("read button"); 
    return 0; 
} 

void loop(char c[3][3])
{ 
    int i = 0, j = 0; 
    Intro_primero(c); 
    tablero(c); 
    do
    { 
        system("clear");
        tablero(c); 
        if (i % 2 == 0)
        { 
            Intro_Yo(c);     
        } 
        else
        { 
            Intro_IA(c); 
        } 
        j = Ganador(c); 
        i++; 
    }while ((i < 9) && (j == 2)); 
    system ("clear"); 
    tablero(c); 
    if (j == 0)
    { 
        cout << endl << "Felicidades. Ganaste!!\n"; 
    } 
    else if (j == 1)
    { 
        cout << endl << "Oh, no! Has perdidido :C.\n"; 
    } 
    else
    { 
        cout << endl << "Has empatado :/.\n"; 
    } 
} 

void Intro_primero(char c[3][3])
{ 
    char aux; 
    aux = '1'; 
    for (int i = 0; i < 3; i++)
    { 
        for (int j = 0; j< 3; j++)
        { 
            c[i][j] = aux++; 
        } 
    } 
} 

void Intro_Yo(char c[3][3])
{
    int i, j, k, aux; /*en estos bucles se solucionan 2 problemas graves que son: -La introduccion de fichas invalidas - El que el programa reconozca si el usuario quiere pone una ficha ya puesta antes. */ 
    do
    { 
        k = 0; 
        do
        { 
            cout << endl << "Coloca ficha: "; 
            fflush(stdin); 
            cin >> aux; 
        }
        while((aux < 1) || (aux > 9)); 
        switch(aux)
        { 
            case 1: 
                i = 0; 
                j = 0; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                {
                    k = 1; 
                    cout << endl << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                } 
                break; 
            case 2: 
                i = 0; 
                j = 1; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                { 
                    k = 1; 
                    cout << endl << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                } 
                break; 
            case 3: 
                i = 0; 
                j = 2; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                { 
                    k = 1; 
                    cout << endl << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                } 
                break; 
            case 4: 
                i = 1; 
                j = 0; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                { 
                    k = 1; 
                    cout << endl << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                } 
                break; 
            case 5: 
                i = 1; 
                j = 1; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                { 
                    k = 1; 
                    cout << endl << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                } 
                break; 
            case 6: 
                i = 1; 
                j = 2; 
                break; 
            case 7: 
                i = 2; 
                j = 0; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                { 
                    k = 1; 
                    cout << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                } 
                break; 
            case 8: 
                i = 2; 
                j = 1; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                { 
                    k = 1; 
                    cout << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                }
                break; 
            case 9: 
                i = 2; 
                j =2; 
                if (c[i][j] == 'X' || c[i][j] == 'O')
                { 
                    k = 1; 
                    cout << "La casilla esta ocupada. Intentalo con otro numero." <<endl; 
                } 
                break; 
            } 
        }while(k == 1); 
        c[i][j] = 'X'; 
} 

//El pc pone fichas 
void Intro_IA(char c[3][3])
{ 
    int i,j,k; 
    srand(time(NULL));//Semilla 
    do
    { 
        i = rand() % 3; 
        j = rand () % 3; 
        k = 0; 
        if (c[i][j] == 'X' || c[i][j] == 'O')
        { 
            k = 1; 
        } 
    }while(k == 1); 
    c[i][j] = 'O'; 
} 

void tablero(char c[3][3])
{ 
    for (int i = 0; i<3;i++)
    { 
        for (int j = 0; j<3; j++)
        { 
            if (j < 2)
            { 
                cout << " " << c[i][j] << " |"; 
            } 
            else
            { 
                cout << " " << c[i][j];
            } 
        } 
        if(i < 3)
        { 
            cout << endl << "---------" <<endl; 
        } 
    } 
} //Return 0 = jugador gano, return 1 = maquina gano 

int Ganador(char c[3][3])
{ 
    //ficha inicial(1) 
    if (c[0][0] == 'X' || c[0][0] == 'O')
    { 
        if (c[0][0] == c[0][1] && c[0][0] == c[0][2])
        { 
            if (c[0][0] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
        } 
        if (c[0][0] == c[1][0] && c[0][0] == c[2][0])
        { 
            if (c[0][0] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
        }
        if(c[1][1] == c[0][0] && c[2][2] == c[0][0]) //fichas 1 5 9
        {
            if (c[0][0] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
        }
    }
    else if(c[0][1] == 'X' || c[0][1] == 'O') //ficha inicial 2
    {
        //fichas 2 5 8
        if(c[1][1] == c[0][1] && c[2][1] == c[0][1])
        {
            if (c[0][1] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][1] == 'O')
            { 
                return 1; 
            } 
        }
    } 
    else if (c[1][1] == 'X' || c[1][1] == 'O') //Ficha central(5)
    {
        //fichas 1 5 9 
        if (c[1][1] == c[0][0] && c[2][2] == c[0][0])
        { 
            if (c[0][0] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
        } //fichas 2 5 8 
        if (c[1][1] == c[0][1] && c[1][1] == c[2][1])
        { 
            if (c[1][1] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
        } //Fichas 4 5 6 
        if (c[1][1] == c[1][0] && c[1][1] == c[1][2])
        { 
            if (c[1][1] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
        } //fichas 7 5 3 
        if (c[1][1] == c[2][0] && c[1][1] == c[0][2])
        { 
            if (c[1][1] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
        } 
    }
    else if(c[2][0] == 'O' || c[2][0] == 'X') //Ficha 7
    {
        //fichas 7 5 3
        if(c[1][1] == c[2][0] && c[0][2] == c[1][1])
        {
            if (c[2][0] == 'X')
            { 
                return 0; 
            } 
            else if (c[2][0] == 'O')
            { 
                return 1; 
            } 
        }
    }  
    else if(c[3][3] == 'X' || c[3][3] == 'O') //Ficha final (9)
    {
        if (c[3][3] == c[1][2] && c[3][3] == c[0][2])
        { 
            if (c[3][3] == 'X')
            { 
                return 0; 
            } 
            else if (c[0][0] == 'O')
            { 
                return 1; 
            } 
            if (c[3][3] == c[2][1] && c[3][3] == c[2][0])
            { 
                if (c[3][3] == 'X')
                { 
                    return 0; 
                } 
                else if (c[0][0] == 'O')
                { 
                    return 1; 
                } 
            } 
        } 
    } 
    return 2; 
}