void expand(char s1[], char s2[]){
	int start, end;
	int found = 0;
	int y = 0;
	
	for (int i = 0; s1[i] != '\0'; ++i){

		if (s1[i] == '-'){

			if (i == 0){
				s2[y++] = '-';
				if (s1[i+2] == '\n')
					s2[y++] = s1[i+1];
			}
			else if (s1[i+1] != '\n'){
				if (found && s1[i-1] == end) 
					start = s1[i-1] + 1;
				else
					start = s1[i-1];

				end = s1[i+1];
				found = 1;

				do
					s2[y++] = start++;
 				while (start <= end);
			}
			else if (i == 1 && s1[i+1] == '\n'){
				s2[y++] = s1[i-1];
				s2[y++] = '-';
			}
			else
				s2[y++] = '-';

		}
	}
	s2[y] = '\0';
}
