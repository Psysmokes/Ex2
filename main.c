#define _CRT_SECURE_NO_WARNINGS
#define size 26
char getThechar(int* arr, int len);
void countChars(int* );
void declerationFILE(char* str, char* filename);
int doestlomglong(char* str);


void Ex3();
void Ex5();
typedef struct consts
{
	char name[50];
	int size_t;
	struct consts * next;
}Consts;

#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
	
	//Ex3();
	Ex5();

	
}
void Ex3() {

	int chars[24] = { 0 };
	countChars(&chars, "filename.txt");
	printf("The most usefull char in text is: %c", getThechar(chars, size));
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

void Ex5() {
	Consts* head;
	int size_t;
	char decleration[50] = { "long long x,y;" };
	char filename[50] = { "decleration.txt "};
	declerationFILE(decleration, filename);
}
	


Consts* createConst(char* name,int size_t) {
	Consts* temp = (Consts*)malloc(sizeof(Consts));
	strcpy(temp->name, name);
	temp->size_t = size_t;
	temp->next = NULL;
	return temp;

}

void addNex(Consts** head, char* name, int size_t)
{
	Consts* temp;
	Consts* tempT;
	temp = createConst(name, size_t);
	if (*head == NULL)
		(*head) = temp;

	else {
		tempT = (*head);
		while (tempT != NULL)
			tempT = tempT->next;
		tempT->next = temp;
	}
}
	
void declerationFILE(char* str, char* filename) {
	FILE* fptr;
	char type[50];
	int i = 0, j = 0;
	int sizes=1;
	int str_s, type_s;
	char temp[50];
	str_s = strlen(str);
	fptr = fopen(filename, "w");
	while (str[i] != ' ') {
		temp[i] = str[i];
		i++;
	}
	if (str[i - 1] == '*')type_s = sizeof(int*);
	if (type_s = doestlomglong(str) != 0) i = 9;
	temp[i] = '\0';
	type_s = getVar(temp);
	for (; i < str_s; i++) {
		while (str[i] != ',') {
			type[j] = str[i];
			if (str[i] == '[') {
				sizes = count(str, type_s);
				sizes = 1;
			}
			type[j] = str[i];
		}
			
		}
	type[j] = '\0';
	fprintf(fptr, "%c", type);
	fprintf(fptr, " requires %d bytes\n", (sizes*str_s));

	}
	




	fclose(fptr);
}
int doestlomglong(char* str) {
	char temp[] = { "long long" };
	int i=0, f = 1;
	for (i = 0; i < 9; i++) {
		if (str[i] != temp[i]) return 0;
	}
	return sizeof(long long);
 }

int getVar(char* str) {
	if (strcmp("int", str) == 0)return sizeof(int);
	if (strcmp("float", str) == 0)return sizeof(float); 
	if (strcmp("char", str) == 0)return sizeof(char);
	if (strcmp("double", str) == 0)return sizeof(double);
	if (strcmp("short", str) == 0)return sizeof(short);
	if (strcmp("long", str) == 0)return sizeof(long);
}
	