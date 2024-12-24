//cambiado
void prthabitat(PKMN pokemonList[], int i){
	
	//habilitar soporte para color en windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING, eso.
    SetConsoleMode(hOut, dwMode);
	int hab;
	if(strcmp(pokemonList[i].habitat, "Bosque") == 0){
        hab = 1;
    }else if(strcmp(pokemonList[i].habitat, "Montana") == 0){
        hab = 2;
    }else if(strcmp(pokemonList[i].habitat, "Lago") == 0){
        hab = 3;
    }else if(strcmp(pokemonList[i].habitat, "Pradera") == 0){
        hab = 4;
    }else if(strcmp(pokemonList[i].habitat, "Pantano") == 0){
        hab = 5;
    }else if(strcmp(pokemonList[i].habitat, "Oceano") == 0){
        hab = 6;
    }else if(strcmp(pokemonList[i].habitat, "Cueva") == 0){
        hab = 7;
    }else if(strcmp(pokemonList[i].habitat, "Ciudad") == 0){
        hab = 8;
    }else if(strcmp(pokemonList[i].habitat, "Planta_Electrica") == 0){
        hab = 9;
    }else if(strcmp(pokemonList[i].habitat, "Playa") == 0){
        hab = 10;
    }else if(strcmp(pokemonList[i].habitat, "Dojo") == 0){
        hab = 11;
    }else if(strcmp(pokemonList[i].habitat, "Centro_Pokemon") == 0){
        hab = 12;
    }else{
        hab = 13;
    }
    switch(hab){
        case 1:
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 2:
            printf("%s\n", pokemonList[i].habitat);
            break;
        case 3:
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 4:
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 5:
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 6:
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 9:
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 10:
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 11:
            printf("%s\n", pokemonList[i].habitat);
            break;
        case 12:
            printf("%s\n", pokemonList[i].habitat);
            break;
        case 13:
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE);
            printf("%s\n", pokemonList[i].habitat);
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        default:
            printf("%s(error)\n", pokemonList[i].habitat);
            break;
    }
    
    printf("\e[0m");
}
void VerPokemon(PKMN pokemonList[], int i){
	int op;
	system("cls");
	do{
		printf("\nPokemon N:%d \nNombre: %s \nTipo: %s | %s \nHabitat: ", 
	    pokemonList[i].id, 
	    pokemonList[i].name, 
	    pokemonList[i].type1, 
	    pokemonList[i].type2);
	    
	    //habitat
	    prthabitat(pokemonList, i);
	    
	    
	    //
	    
		//linea evolutiva
	    printf("linea evolutiva: \n");
	    if(pokemonList[i].evo_2==152){
	    	printf("%s", pokemonList[pokemonList[i].evo_1-1].name);	
		}else if(pokemonList[i].evo_3==152){
			printf("%s -> %s", pokemonList[pokemonList[i].evo_1-1].name, pokemonList[pokemonList[i].evo_2-1].name);
		}else{
			printf("%s -> %s -> %s", 
			pokemonList[pokemonList[i].evo_1-1].name,
			pokemonList[pokemonList[i].evo_2-1].name,
			pokemonList[pokemonList[i].evo_3-1].name);	
		}
		//
		
	    printf("\nDescripcion: \n");
	    printDesc(pokemonList[i].desc);
		printf("Desea volver? (1.si)\n R:");
		scanf("%d", &op);	
	}while(op != 1);
	
		
}


void MostrarPokedex(int totalPokemons, PKMN pokemonList[]){
	int i=0, op2;
	while(i != totalPokemons){
		printf("\nPokemon N:%d \nNombre: %s \nTipo: %s | %s \nHabitat: %s \n", 
	    pokemonList[i].id, 
	    pokemonList[i].name, 
	    pokemonList[i].type1, 
	    pokemonList[i].type2, 
	    pokemonList[i].habitat);
	    printf("linea evolutiva: \n");
	    if(pokemonList[i].evo_2==152){
	    	printf("%s", pokemonList[pokemonList[i].evo_1-1].name);	
		}else if(pokemonList[i].evo_3==152){
			printf("%s -> %s", pokemonList[pokemonList[i].evo_1-1].name, pokemonList[pokemonList[i].evo_2-1].name);
		}else{
			printf("%s -> %s -> %s", 
			pokemonList[pokemonList[i].evo_1-1].name,
			pokemonList[pokemonList[i].evo_2-1].name,
			pokemonList[pokemonList[i].evo_3-1].name);	
		}
	    printf("\nDescripcion: \n");
	    printDesc(pokemonList[i].desc);
	    printf("____________________________\n");
		printf("1.[anterior] | 2.[siguiente]\n");
		printf("3.[Ver Stats]| 4.[salir]    \n");
		printf("Opcion: ");	
		scanf("%d", &op2);
		switch(op2){
		case 1:
			if(i>0){
				i--;	
			}
			system("cls");
			break;
		case 2:
			if(i!=totalPokemons-1){
				i++;	
			}
			system("cls");
			break;
		case 3:
			printf("\nno implementado todavia");
			system("cls");
			break;
		case 4:
			i=totalPokemons;
			printf("\nsaliendo.....");
			sleep(1);
			system("cls");
			break;
		default:
			printf("\nERROR opcion invalida\n");
			sleep(1);
			system("cls");
			break;
		}
	}
}
