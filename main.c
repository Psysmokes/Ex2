#define _CRT_SECURE_NO_WARNINGS
#define size 26
char getThechar(int* arr, int len);
void countChars(int* );


#include <stdio.h>
#include <conio.h>

void main() {
	
	int chars[24] = { 0 };
	countChars(&chars,"filename.txt");
	printf("The most usefull char in text is: %c", getThechar(chars,size));

	
}

void countChars(int* chars, char filename[]) {
	char ch;
	FILE* f;
	f = fopen(filename, "r");
	if (f == NULL)printf("coudnt oppen file");
	while ((ch = fgetc(f)) != EOF) {
		if (ch >= 'a'&& ch <= 'z')  		chars[ch - 'a']++;

		else if (ch >= 'A'&&ch <= 'Z')			chars[ch - 'A']++;
	}
	fclose(f);
}

char getThechar(int* arr, int len) {
	int i = 0;
	int position, max=0;
	for (i = 0; i < len; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			position = i;
		}
	}
	return 	position + 'A';
}



