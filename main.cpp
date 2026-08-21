
#include <iostream>

using namespace std;

class Tablero{
    
    public:
        Tablero();
        Tablero(char casilla);
        void Mostrar();
        void PonerFicha(int posX, int posY, char tipo);
        char interno[3][3];
    
};

Tablero::Tablero(){
    
    for(int i=0; i<3 ;i++){
        for(int j=0; j<3 ;j++){
            interno[i][j] = ' ';
        }
    }
    
}

Tablero::Tablero(char casilla){
    
    for(int i=0; i<3 ;i++){
        for(int j=0; j<3 ;j++){
            interno[i][j] = casilla;
        }
    }
    
}

void Tablero::PonerFicha(int posX, int posY, char tipo){
    
    interno[posX][posY] = tipo;
    
}

void Tablero::Mostrar(){
    
    for(int i=0; i<3 ;i++){
        cout << " | ";
        for(int j=0; j<3 ;j++){
            cout << interno[i][j] << " | ";
        }
        cout << endl;
    }
    
}

class Jugador{
    
    private:
        int ID;
        char tipoFicha;
        Tablero* tablero;
        
    public: 
        Jugador(int ID_, Tablero* miTablero, char tipoFicha_);
        void PonerFicha(int posX, int posY);
        
};

Jugador::Jugador(int ID_, Tablero* miTablero, char tipoFicha_){
    
    ID = ID_;
    tablero = miTablero;
    tipoFicha = tipoFicha_;
}


void Jugador::PonerFicha(int posX, int posY){
    
    if(tablero->interno[posX][posY] == ' '){
        
        tablero->interno[posX][posY] = tipoFicha;
        
    }else{
        cout << "casilla ocupada." << endl;
    }
    
}

int main()
{
    Tablero miTablero;
    miTablero.Mostrar();
    cout << endl;
    Jugador primerJugador(1, &miTablero, 'X');
    Jugador segundoJugador(2, &miTablero, 'O');
    
    primerJugador.PonerFicha(0,0);
    segundoJugador.PonerFicha(1,1);
    
    miTablero.Mostrar();

    return 0;
}

