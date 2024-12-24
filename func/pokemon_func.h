
int readtxt(const char *filename, PKMN *pokemonList) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    int count = 0;
    while (count < MAX_POKEMON){
    	int result = fscanf(file, "%d %s %s %s %s %d %d %d %s", 
           &pokemonList[count].id,
           pokemonList[count].name,
           pokemonList[count].type1,
           pokemonList[count].type2,
           pokemonList[count].habitat,
		   &pokemonList[count].evo_1,
		   &pokemonList[count].evo_2,
		   &pokemonList[count].evo_3,
		   pokemonList[count].desc);
	    if (result == EOF) {
	        break; // Fin del archivo
	    } else if (result < 5) {
	        printf("Error al leer la línea %d. Resultados: %d\n", count + 1, result);
	        break; // Error al leer, puede que la línea esté mal formada
	    }
	
	    // Manejar el caso donde type2 puede estar vacío
	    if (strcmp(pokemonList[count].type2, "-") == 0) {
	        strcpy(pokemonList[count].type2, "----"); // Asignar cadena vacía si es un guion
	    }
	    count++;
	}
    return count; // Retorna la cantidad de Pokémon leídos
}
int addPokemon(const char *filename, PKMN *pokemonList, int *totalPokemons) {
    if (*totalPokemons >= MAX_POKEMON) {
        printf("Error: No se pueden agregar mas Pokemon, limite alcanzado.\n");
        return -1;
    }

    PKMN newPokemon;

    // Pedir datos al usuario
    printf("Introduce el ID del Pokemon: ");
    scanf("%d", &newPokemon.id);

    printf("Introduce el nombre del Pokemon: ");
    scanf("%s", newPokemon.name);

    printf("Introduce el primer tipo del Pokemon: ");
    scanf("%s", newPokemon.type1);

    printf("Introduce el segundo tipo del Pokemon (o '-' si no tiene): ");
    scanf("%s", newPokemon.type2);

    printf("Introduce el habitat del Pokemon: ");
    scanf("%s", newPokemon.habitat);
    
    printf("ingrese el id de la evolucion base:\n");
    scanf("%d", &newPokemon.evo_1);
    
    printf("ingrese el id de la segunda evolucion de la linea (si no tiene ingresa 152):\n");
    scanf("%d", &newPokemon.evo_2);
    
    printf("ingrese el id de la tercera evolucion de la linea (si no tiene ingresa 152):\n");
    scanf("%d", &newPokemon.evo_3);
    
    printf("Introduce la descripcion del pokemon: \n");
    scanf("%s", newPokemon.desc);

    // Si el segundo tipo es "-", lo dejamos vacío
    if (strcmp(newPokemon.type2, "-") == 0) {
        strcpy(newPokemon.type2, "");
    }

    // Añadir el Pokémon al arreglo
    pokemonList[*totalPokemons] = newPokemon;
    (*totalPokemons)++;

    // Guardar el nuevo Pokémon en el archivo
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error al abrir el archivo para añadir el Pokémon");
        return -1;
    }
    fprintf(file, "%d %s %s %s %s %d %d %d %s\n", 
        newPokemon.id, 
        newPokemon.name, 
        newPokemon.type1, 
        strlen(newPokemon.type2) > 0 ? newPokemon.type2 : "-", 
        newPokemon.habitat,
		newPokemon.evo_1,
		newPokemon.evo_2,
		newPokemon.evo_3,
		newPokemon.desc);
    fclose(file);

    printf("Pokémon añadido con éxito.\n");
    return 0;
}

int readtxt2(const char *filename, DAT *pokemonList) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    int count = 0;
    while (count < MAX_POKEMON){
    	int result = fscanf(file, "%d %d %d %d %d %d %d ", 
           &pokemonList[count].id,
           &pokemonList_est[count].HP,
           &pokemonList_est[count].Atk,
           &pokemonList_est[count].Def,
           &pokemonList_est[count].SpA,
		   &pokemonList_est[count].SpD,
		   &pokemonList_est[count].Spe);
	    if (result == EOF) {
	        break; // Fin del archivo
	    } else if (result < 5) {
	        printf("Error al leer la línea %d. Resultados: %d\n", count + 1, result);
	        break; // Error al leer, puede que la línea esté mal formada
	    }
	   
	    count++;
	}
    return count; // Retorna la cantidad de Pokémon leídos
}
