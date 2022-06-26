#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findShort(const char *s){
	int word_size, shortest_size;
	char *sentence;
	char *word;	

	/* We have to copy the string to a new pointer,
 	because the exercise doesn't allow modifying s.
	The possible newline character is also removed
	from the input string.*/
	sentence = (char*)malloc(sizeof(char)*strlen(s));
	strncpy(sentence, s, sizeof(char)*strlen(s));
	if (sentence[strlen(s)-1] == '\n')
		sentence[strlen(s)-1] = '\0';
	
	if (sentence[strlen(s)-2] == '\n')
		sentence[strlen(s)-2] = '\0';

	word = strtok(sentence, " ");
	shortest_size = strlen(word);

	while (word != NULL){
		word_size = strlen(word);
		if (word_size <= shortest_size)
			shortest_size = word_size;
		printf("%s\n", word);
		word = strtok(NULL, " ");
	}
		
	return shortest_size;
}

int main(){
	char input[] = "Let's travel abroad shall we";
	printf("Shortest word has length of %d.\n", findShort(input)); 
}
