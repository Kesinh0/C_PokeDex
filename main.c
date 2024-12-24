#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//variables globales
#define MAX_POKEMON 151 //primera generacion solo tenia 151.
#define MAX_LINE_LENGTH 35 //para que salte linea automaticamente.

//librerias
#include "struct/pokemon.h"
#include "func/pokemon_func.h"
#include "func/Textos_func.h"
#include "func/ver_func.h"


//test

int main(){
	
    PKMN pokemonList[MAX_POKEMON];
    DAT pokemonList_est[MAX_POKEMON];
    int totalStatsPokemons = readtxt2("bd/bd_stats.txt", pokemonList_est);
	int totalPokemons = readtxt("bd/bd.txt", pokemonList);
	int i, opcion;
    if (totalPokemons < 0) {
    	printf("\nERROR al leer archivo\n");
        return 1; // Error al leer el archivo
    }
	do {
        printf("\nMenu:\n");
        printf("1. Mostrar Pokedex\n");
        printf("2. Agregar Nuevo Pokemon\n");
        printf("3. Mostrar Pokemon especifico\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
            	system("cls");
            	MostrarPokedex(totalPokemons, pokemonList);
                break;
            case 2:
                addPokemon("bd/bd.txt", pokemonList, &totalPokemons);
                system("cls");
				break;
			case 3:
				printf("Que pokemon desea ver?\nid: ");
				scanf("%d", &i);
				VerPokemon(pokemonList, i);
				system("cls");
				break;
            case 4:
            	system("cls");
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida.\n");
                sleep(1);
        		system("cls");
		}
    } while (opcion != 4);
	return 0;
}
