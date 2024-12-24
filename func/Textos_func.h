void printDesc(const char *str) {
    int len = strlen(str);
    int start = 0;
    while (start < len) {
        // Imprimir hasta MAX_LINE_LENGTH caracteres o hasta el final de la cadena
        int lineLength = (len - start < MAX_LINE_LENGTH) ? len - start : MAX_LINE_LENGTH;
        
		// Si la l�nea corta una palabra, buscar el �ltimo espacio antes de MAX_LINE_LENGTH
        
		if (lineLength == MAX_LINE_LENGTH) {
            int lastSpace = start + MAX_LINE_LENGTH;
            while (lastSpace > start && str[lastSpace] != ' ') {
                lastSpace--;
            }
            // Si no se encontr� un espacio, se imprime el segmento completo
            if (lastSpace == start) {
                lastSpace = start + MAX_LINE_LENGTH;
            }
            lineLength = lastSpace - start;
        }
        // Imprimir la l�nea
        printf("%.*s\n", lineLength, str + start);
        start += lineLength;
    }
}

void printDesc(const char *str) {
    int len = strlen(str);
    int start = 0;
    while (start < len) {
        // Imprimir hasta MAX_LINE_LENGTH caracteres o hasta el final de la cadena
        int lineLength = (len - start < MAX_LINE_LENGTH) ? len - start : MAX_LINE_LENGTH;
        
		// Si la l�nea corta una palabra, buscar el �ltimo espacio antes de MAX_LINE_LENGTH
        
		if (lineLength == MAX_LINE_LENGTH) {
            int lastSpace = start + MAX_LINE_LENGTH;
            while (lastSpace > start && str[lastSpace] != ' ') {
                lastSpace--;
            }
            // Si no se encontr� un espacio, se imprime el segmento completo
            if (lastSpace == start) {
                lastSpace = start + MAX_LINE_LENGTH;
            }
            lineLength = lastSpace - start;
        }
        // Imprimir la l�nea
        printf("%.*s\n", lineLength, str + start);
        start += lineLength;
    }
}
