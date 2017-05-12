#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_SIZE 50

char *flat_text(char **words, int n) {
	char *temp = NULL, *result = NULL;
	result = malloc(sizeof(char));
	if ( result == NULL ) {
		return NULL;
	}
	strcpy(result,"");
	for(int i = 0; i < n; i++) {
	    temp = malloc(sizeof(char) * (strlen(result)+ 1));
		if ( temp == NULL ) {
			free(result);
			return NULL;
		}
	    if ( temp == NULL) {
	    	return NULL;
	    }
	    strcpy(temp, result);
		free(result);
	    result = malloc(sizeof(char) * (strlen(words[i])+ strlen(temp)+ 1));
	    if ( result == NULL) {
			free(temp);
	    	return NULL;
	    }
	    strcpy(result, temp);
	    strcpy(result+strlen(temp), words[i]);
	    //free(words[i]);
	    free(temp);
	}
	return result;
}

int main(int argc, char **argv) {

	char* word = malloc(sizeof(char) * MAX_SIZE);
    if ( word == NULL) {
    	return 1;
    }
	char *words[MAX_WORDS];
	strcpy(word, "");
	int result = 1, i = 0;
	result = fscanf(stdin, "%99[^\n]%*c", word);
    while ( result == 1 ) {
		words[i] = malloc(sizeof(char) * (strlen(word) + 1));
	    if ( words[i] == NULL) {
	    	for(int j = 0; j < i - 1; j++) {
	    		free(words[j]);
	    	}
	    	free(word);
	    	return 1;
	    }
		strcpy(words[i], word);
		i++;
		if ( i >= MAX_WORDS ) {
			break;
		}
    	result = fscanf(stdin, "%99[^\n]%*c", word);
    }
    free(word);
	char *p = flat_text(words, i);
	for(int j = 0; j < i; j++) {
		free(words[j]);
	}
	if ( p != NULL) {
		printf("\n%s\n", p);
	}
	free(p);
	return 0;
}
