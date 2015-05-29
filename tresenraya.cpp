#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop (char matriz[3][3]);
void intro_numeros (char matriz[3][3]);
void tablero (char matriz[3][3]);
void intro_usuario (char matriz[3][3]);
void intro_maquina (char matriz[3][3]);
int ganador (char matriz[3][3]);
void presentacion();

int main () {

    char matriz [3][3];

    loop (matriz);

    }    

void loop (char matriz [3][3]){
    int i, j;

    i = 0;

    presentacion();

    intro_numeros (matriz);

    do{
	system("clear");
	system("figlet Tres en Raya");
	tablero (matriz);

	if (i % 2 == 0){
	    intro_usuario (matriz);
	}
	else{
	    intro_maquina (matriz);
	}
	j = ganador (matriz);
	i++;

    }while (i <= 9 && j == 2);

    system("clear");
    tablero (matriz);

    if (j == 0){
printf ("Enhorabuena. Has ganado!!!\n\n");
    }
    else if (j == 1){
	printf ("Has perdido!!! Vuelve a intentarlo paquete\n\n");
    }
    else{
	printf("Has empatado!!!\n\n");
    }


}

void presentacion(){
    system("clear");
    system("figlet Tres en Raya");
}

void intro_numeros (char matriz[3][3]){
    int i, j;
    char aux;

    aux = '1';

    for (int i=0; i<3; i++){
	for (int j=0; j<3; j++){
	    matriz[i][j] = aux++;
	}

    }

}

void intro_usuario (char matriz[3][3]){
    int i, j, k;
    char aux;

    do{
	do{
	    printf ("Selecciona una posición: \n");
	    fflush (stdin);
	    scanf("%c", &aux);
	}while (aux < '1' || aux > '9');

	k = 0;

	switch (aux){
	    case '1': {
		i = 0;
		j = 0;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	     }
		     
	     case '2': {
		i = 0;
		j = 1;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }

            case '3': {
		i = 0;
		j = 2;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }

	    case '4': {
		i = 1;
		j = 0;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }

            case '5': {
		i = 1;
		j = 1;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }

	    case '6': {
		i = 1;
		j = 2;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }

	    case '7': {
		i = 2;
		j = 0;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }

	    case '8': {
		i = 2;
		j = 1;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }

	    case '9': {
		i = 2;
		j = 2;
		if (matriz[i][j] == 'X' || matriz [i][j] == 'O'){
		    k = 1;
		    printf ("Esta casilla esta ocupada. Prueba otra casilla\n\n");
		}
		break;
	    }
	}
    }while (k == 1);

    matriz[i][j] = 'X';
}

void intro_maquina (char matriz [3][3]){
    int i, j, k;

    srand (time(NULL));
    do{
	 i = rand() % 3;
    	 j = rand() % 3;// numeros aleatorios de la i y la j
	 k = 0; // cero para darle la oportunidad de salir del bucle

	 if (matriz[i][j] == 'X' || matriz[i][j] == 'O'){
	     k = 1;
	 }
    }while (k == 1);// el bucle se repite cuando k = 1, cuando k sea = a 0 saldra del bucle

    matriz[i][j] = 'O';
}

void tablero (char matriz [3][3]){
    int i, j;

    for (int i=0; i<3; i++){
	for (int j=0; j<3; j++){
	    if (j<2){
		printf (" %c |", matriz[i][j]);
	    }
	    else {
		printf (" %c ", matriz[i][j]);
	    }
	}
	if (i<2){
	    printf ("\n-----------\n");
	}
    }
    printf ("\n\n");
}

int ganador (char matriz[3][3]){
    if (matriz[0][0] == 'X' || matriz[0][0] == 'O'){
	if (matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2]){
	    if (matriz[0][0] == 'X'){
		return 0;
	    }
	    else {
		return 1;
	    }
	}
	if(matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0]){
	    if (matriz[0][0] == 'X'){
		return 0;
	    }
	    else {
		return 1;
	    }
	}
    }

    if (matriz[1][1] == 'X' || matriz[1][1] == 'O'){
	if (matriz[1][1] == matriz[0][0] && matriz[1][1] == matriz[2][2]) {
	    if (matriz[1][1] == 'X'){
		return 0;
	    }
	    else {
		return 1;
	    }
	}
	if (matriz[1][1] == matriz[1][0] && matriz[1][1] == matriz[1][2]){
	    if (matriz[1][1] == 'X'){
		return 0;
	    }
	    else{
		return 1;
	    }
	}
	if (matriz[1][1] == matriz[2][0] && matriz[1][1] == matriz[0][2]){
	    if (matriz[1][1] == 'X'){
	       return 0;
	    }
	    else{
	        return 1;
	    }
	}
	if (matriz[1][1] == matriz[0][1] && matriz[1][1] == matriz[2][1]){
	    if (matriz[1][1] == 'X'){
		return 0;
	    }
	    else{
		return 1;
	    }
	}
    }		
    if (matriz[2][2] == 'X' || matriz[2][2] == 'O'){
	if (matriz[2][2] == matriz[2][0] && matriz[2][2] == matriz[2][1]){
	    if (matriz[2][2] == 'X'){
		return 0;
	    }
	    else{
		return 1;
	    }
	}
	if (matriz[2][2] == matriz[0][2] && matriz[2][2] == matriz[1][2]){
	    if (matriz[2][2] == 'X'){
		return 0;
	    }
	    else{
		return 1;
	    }
	}
    }
    return 2;
}
