void printDesc(const char *str) {
    int len = strlen(str);
    int start = 0;
    while (start < len) {
        // Imprimir hasta MAX_LINE_LENGTH caracteres o hasta el final de la cadena
        int lineLength = (len - start < MAX_LINE_LENGTH) ? len - start : MAX_LINE_LENGTH;
        
		// Si la línea corta una palabra, buscar el último espacio antes de MAX_LINE_LENGTH
        
		if (lineLength == MAX_LINE_LENGTH) {
            int lastSpace = start + MAX_LINE_LENGTH;
            while (lastSpace > start && str[lastSpace] != ' ') {
                lastSpace--;
            }
            // Si no se encontró un espacio, se imprime el segmento completo
            if (lastSpace == start) {
                lastSpace = start + MAX_LINE_LENGTH;
            }
            lineLength = lastSpace - start;
        }
        // Imprimir la línea
        printf("%.*s\n", lineLength, str + start);
        start += lineLength;
    }
}
