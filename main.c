#define _CRT_SECURE_NO_WARNINGS

#include "node.h"
#include <stdio.h>
#include<string.h>
#include <ctype.h>

#define size 26

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
char** exOneLogic(char c, int* arrayLength);
char* exTwoLogic(char* str);
void commonestLetter(int* chars, char filename[]);
char getThechar(int* arr, int len);
void decorder(char* str);
void declerationFILE(char* str, char* filename);
int doestlomglong(char* str);
int getVar(char* str);
int isPointer(char* str);



int main()
{
	int select = 0, i, all_Ex_in_loop = 0;

	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");

	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d \n", i, i);

			printf("EXIT-->0 \n");

			do
			{
				select = 0;
				printf("please select 0-5 : \n");
				scanf_s("%d", &select);
			} while ((select<0) || (select>5));

			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}

		} while (all_Ex_in_loop && select);
		return 0;
}

//Ex1
void Ex1() {
	int arrayLength = 0, i = 0;
	char c_small = NULL;
	char** arr;
	printf("split by: \n");

	//get input char
	c_small = tolower(getchar());

	// build array of strings
	arr = exOneLogic(c_small, &arrayLength);

	printf("\n\noutput: \n");
	// print output
	for (i = 0; i < arrayLength; i++) {
		puts(arr[i]);
		free(arr[i]);
	}
	free(arr);

}
//Ex2
void Ex2() {
	int strLength = 0;
	char* strNew = NULL;
	char* str = (char*)malloc(sizeof(char) * 101);

	// get input
	printf("Enter input MAX 100\n");
	gets(str);
	//gets(str);
	//scanf("%s",str);
	strLength = strlen(str);
	strNew = exTwoLogic(str);

	// print new string 
	printf("new stirng:");
	puts(strNew);
	printf("\n");

	free(strNew);
	free(str);

}

//Ex3
void Ex3() {
	char ch;
	int chars[size] = { 0 };
	 commonestLetter(&chars, "input.txt");
	ch = getThechar(chars, size);
		if (ch)
			printf("The most usefull char in text is: %c", ch);
		else
			printf("No letters in the file");
}
//Ex4
void Ex4() {
	char str[100];
	char* massege;
	printf("enter the decoded mesage:\n");
	gets(str);
	decorder(str);
}

//Ex5
void Ex5() {
	int size_t;
	char* filename = (char *)malloc(100);
	char* decleration = (char *)malloc(100);

	printf("Enter file name\n");
	gets(filename);

	printf("Enter the decleration\n");
	gets(decleration);



	declerationFILE(decleration, filename);
	free(filename);
	free(decleration);

}

char** exOneLogic(char c, int* arrayLength) {
	Node* list = NULL;
	char c_upp = NULL;
	Node* temp = NULL;
	char** arr;
	int strLength = 0, i = 0, j = 0, start = 0, count = 0, k = 0;
	char* str = (char*)malloc(sizeof(char) * 101);

	// get input
	printf("Enter input MAX 100\n");
	gets(str);
	gets(str);
	//scanf("%s",str);
	strLength = strlen(str);

	c_upp = toupper(c);


	// create list struct with data about the words. index start end
	for (i = 0; i < strLength; i++)
	{
		if ((str[i] == c || str[i] == c_upp) && (str[i - 1] == ' ' || i == 0)) {
			start = i;
			while (str[i] != ' ' && i < strLength)
			{
				i++;
			}
			if (list == NULL) {
				list = createNode(start, i);

			}
			else {
				addNode(&list, start, i);
			}
			// cout total words
			count++;
		}
	}

	// check if have records
	if (count == 0) {
		printf("Zero words");
		return;
	}
	//have record - create array
	arr = (char**)malloc(sizeof(char*)*count);

	i = 0;

	// set data to array
	while (list != NULL)
	{
		k = 0;
		// create array for a word
		arr[i] = (char*)malloc(sizeof(char)*(list->indexEnd - list->indexStart) + 1);

		// put data by index to new array from srt
		for (j = list->indexStart; j < list->indexEnd; j++)
		{
			arr[i][k] = str[j];
			k++;
		}

		// end string
		arr[i][k] = '\0';

		i++;
		temp = list->next;
		free(list);
		list = temp;
	}
	free(str);
	free(temp);
	*arrayLength = count;
	return arr;
}

char* exTwoLogic(char* str) {
	char* strNew = NULL;
	int i = 0, j = 0;
	int count = 0;


	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != 32)
			if (str[i] > 57 || str[i] < 48) {
				count++;
			}
	}

	// create new string / array
	strNew = (char*)malloc(sizeof(char) * (count + 1));

	// build new string
	for (i = 0; i < str[i] != '\0'; i++) {
		if (str[i] != 32)
			if (str[i] > 57 || str[i] < 48) {
				strNew[j] = str[i];
				j++;
			}
	}
	// end string
	if (count > 0)
		strNew[j] = '\0';

	return strNew;

}

// counting sort alorithmic for looking most usefull char
void commonestLetter(int* chars, char filename[]) {
	char ch;
	FILE* f;
	//oppening file for reading the content
	f = fopen(filename, "r");
	if (f == NULL)printf("coudnt oppen file");
	while ((ch = fgetc(f)) != EOF) {
		if (ch >= 'a'&& ch <= 'z')  		chars[ch - 'a']++;

		else if (ch >= 'A'&&ch <= 'Z')			chars[ch - 'A']++;
	}
	//close file
	fclose(f);
	free(f);
}

//find most usefull char+ biggest priority 
char getThechar(int* arr, int len) {
	int i = 0;
	int position, max = 0;
	for (i = 0; i < len; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			position = i;
		}
	}
	return 	position + 'A';
}
//using alogirhmic for decod the original masege
void decorder(char* str) {
	int string_size, i, j = 1;
	char temp[100];
	string_size = strlen(str);
	printf("the original mesage is:\n");
	for (i = 0; i < string_size; i++) {
		while (str[i] != ' '&& str[i] != '\0') {
			temp[i] = str[i] - j;
			i++;
			j++;
		}
		temp[i] = ' ';
		j = 1;
	}
	temp[i - 1] = '\0';
	puts(temp);

}

void declerationFILE(char* str, char* filename) {
	FILE* fptr;
	char type[100];
	int i = 0, j = 0, start = 0;
	int sizes = 1, final_size = 0;
	int str_s = 0, type_s = 0;
	char temp[100];
	str_s = strlen(str);
	fptr = fopen(filename, "w");
	while (str[i] != ' ') {
		temp[i] = str[i];
		i++;
	}

	// chekc if this is long long or long long*
	type_s = doestlomglong(str);
	if (type_s != 0) {
		if (str[9] == '*') {
			type_s = sizeof(void *);
			i = 11;
		}
		else {
			i = 10;
		}
	}
	// check if this is pointer and get size of the var type
	else {
		// end of string
		temp[i] = '\0';

		if (temp[i - 1] == '*')type_s = sizeof(void *);
		else
			type_s = getVar(temp);
		i++;
	}

	// check type
	if (type_s != -1) {
		// build the output 
		for (i; i < str_s; i++) {
			j = 0;
			// string get varible name
			while (str[i] != ',' && str[i] != ' ' &&   str[i] != ';'&&i < str_s) {
				type[j] = str[i];
				j++;
				i++;
			}

			// check if doesnt spase
			if (j > 0) {
				type[j] = '\0';
				start = 0;

				// if array
				final_size = getSizeOfArrayIfDoesArray(type);
				if (final_size != 0) {
					final_size = final_size * type_s;
				}
				else
					final_size = type_s;

				// for pointer only
				if (isPointer(type) == 1) {
					start = 1;
					final_size = sizeof(void *);
				}

				// write to file
				fprintf(fptr, "%c", type[start]);
				fprintf(fptr, " requires %d bytes\n", (final_size));
			}
		}
	}
	else {
		printf("This type doesn't support !");

	}
	// close file  - save changes 
	fclose(fptr);
	free(fptr);


}

int doestlomglong(char* str) {
	int i = 0, f = 1;
	char temp[] = { "long long" };
	int length = strlen(str);

	if (length < 9) return 0;

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
	if (strcmp("*int", str) == 0)return sizeof(int);


	return -1;
}

int getSizeOfArrayIfDoesArray(char* str) {
	int i = 0, start = 0, end = 0, arr_size = 0;;
	int length = strlen(str);
	for (i = 0; i < length; i++)
	{
		if (str[i] == '[') {
			start = i + 1;
			break;
		}
	}
	if (i < length)
		for (start; start < length - 1; start++) {
			arr_size *= 10;
			arr_size += str[start] - '0';
		}

	return arr_size;
}

int isPointer(char* str) {

	return str[0] == '*';
}