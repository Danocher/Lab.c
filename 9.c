#include <stdio.h>

int main(){
    int  flag = 0, count = 0, number_words = 0, number_letters = 0, number_letter;
    char str[1024];
	printf("Input words: ");
    gets(str);
    printf("Answer: ");
    do{
    	number_letters = 0;
    	while(str[count] != ' ' ){
    		if(str[count] != '\0'){
    			count++;
    			number_letters++;
			}
    		else{
    			flag = 1;
    			break;
			}
		}
		if(number_words == number_letters)
			number_letter = count - 1;
		else
			number_letter = count - number_letters + number_words;
    	printf("%c", str[number_letter]);
    	count++;
    	number_words++;
	}while(!flag);
	return 0;
}