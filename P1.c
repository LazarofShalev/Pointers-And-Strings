
#include <stdio.h>
#include <conio.h>


//--Question 1 function
void fillArrByTheNum(int const *numArray, int numArraySize, int jumpSize, int numToInsert){
	int *floatPointer = numArray;
	int i = 0;

	for (floatPointer; floatPointer < numArray + numArraySize; floatPointer++){
		if ((i % jumpSize) == 0){
			*floatPointer = numToInsert;
		}
		else{
			*floatPointer = 0;
		}
		i++;
	}
}
//--Question 2 function
void fillArray(int const *numArray, int numArraySize, int numToStore){

	int *floatPointer;

	for (floatPointer = numArray; floatPointer < numArray + numArraySize; floatPointer++){
		*floatPointer = numToStore;
	}
}
//--Question 3 function
void countChars(char const *string, char charToSearch){
	char *pointerForTheCharAdress = string;

	printf("indexes are: ");

	while (pointerForTheCharAdress < string + strlen(string)){

		pointerForTheCharAdress = strchr(pointerForTheCharAdress, charToSearch);

		if (pointerForTheCharAdress != NULL){
			printf("%d ", (pointerForTheCharAdress - string) + 1);
			pointerForTheCharAdress++;
		}
		else{
			break;
		}

	}
}
//--Question 4 function
void arrangeStringsPointerByBubbleSorting(char const **stringsaArray, int numOfWord){
	char **floatingPointer;
	char **floatingPointer2;

	int i = 0;

	for (floatingPointer = stringsaArray + (numOfWord - 1); stringsaArray < floatingPointer; floatingPointer--){
		for (floatingPointer2 = stringsaArray; floatingPointer2 < stringsaArray + numOfWord - (i + 1); floatingPointer2++){
			if (strlen(*floatingPointer2) >= strlen(*(floatingPointer2 + 1))){
				char *tempFloatingPointer1 = *floatingPointer2;
				*floatingPointer2 = *(floatingPointer2 + 1);
				*(floatingPointer2 + 1) = tempFloatingPointer1;
			}
		}
		i++;
	}
}
//--Question 5 function
char* myStrtok(char *string, char *delimiters){
	static char *indexAddress;
	char *floatingPointer1;
	char *floatingPointer2;
	char *tempIndex = NULL;
	int tempMinIndex;

	if (string != NULL){
		int minIndex = strlen(string);
		floatingPointer1 = string;
		for (floatingPointer2 = delimiters; floatingPointer2 < delimiters + strlen(delimiters); floatingPointer2++){
			if (strchr(floatingPointer1, *floatingPointer2)){
				indexAddress = strchr(floatingPointer1, *floatingPointer2);
				tempMinIndex = (int)(indexAddress - floatingPointer1);
				if (tempMinIndex < minIndex){
					minIndex = tempMinIndex;
					tempIndex = indexAddress;
				}
			}
		}
		indexAddress = tempIndex;
		*indexAddress = '\0';
		indexAddress++;
		return floatingPointer1;
	}
	else if (string == NULL && indexAddress != NULL){
		int minIndex = strlen(indexAddress);
		floatingPointer1 = indexAddress;
		for (floatingPointer2 = delimiters; floatingPointer2 < delimiters + strlen(delimiters); floatingPointer2++){
			if (strchr(floatingPointer1, *floatingPointer2)){
				indexAddress = strchr(floatingPointer1, *floatingPointer2);
				tempMinIndex = (int)(indexAddress - floatingPointer1);
				if (tempMinIndex < minIndex){
					minIndex = tempMinIndex;
					tempIndex = indexAddress;
				}
			}
		}
		if (tempIndex == NULL){
			indexAddress = NULL;
			return floatingPointer1;
		}
		else{
	indexAddress = tempIndex;
		*indexAddress = '\0';
		indexAddress++;
		return floatingPointer1;	
		}	
	}
	else{
		return NULL;
	}
}

/*------------------------------------------------------------------------Main---------------------------------------------------------------------------*/
int main() {
	//-- Question 1
	int userChoise = 1;

	printf("Please enter Question Number(1-5), other for exit: ");
	scanf_s("%d", &userChoise);

	if (userChoise == 1){
		int matrix[10][10] = { 0 };

		for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++){
			for (int j = 0; j < sizeof(matrix) / sizeof(matrix[0]); j++){
				fillArrByTheNum(matrix[j] + i, sizeof(matrix) / sizeof(matrix[0]) - i, j + 1, i);
			}
		}

		//print the matrix
		for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++){
			for (int j = 0; j < sizeof(matrix) / sizeof(matrix[0]); j++){
				printf("%d  ", matrix[i][j]);
			}
			printf("\n");
		}
	}

	//-- Question 2
	else if (userChoise == 2){

		int matrix[10][10];

		fillArray((int*)matrix, (sizeof(matrix) / sizeof(matrix[0])) * (sizeof(matrix) / sizeof(matrix[0])), 0);

		//Print Matrix
		for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++){
			for (int j = 0; j < sizeof(matrix) / sizeof(matrix[0]); j++){
				printf("%d  ", matrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++){
			fillArrByTheNum(matrix[i] + i, sizeof(matrix) / sizeof(matrix[0]) - i, 1, i + 1);
		}

		//Print Matrix
		for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++){
			for (int j = 0; j < sizeof(matrix) / sizeof(matrix[0]); j++){
				printf("%d  ", matrix[i][j]);
			}
			printf("\n");
		}
	}

	//-- Question 3
	else if (userChoise == 3){

		char string[50];
		char charToSearch;

		printf("Please enter a String: ");
		flushall();
		gets(string);
		
		printf("Please enter a Char to search: ");
		flushall();
		scanf("%c", &charToSearch);

		countChars(string, charToSearch);
		printf("\n");
	}

	//-- Question 4
	else if (userChoise == 4){

		char testStringArray[3][20];

		for (int i = 0; i < 3; i++){
			flushall();
			printf("Please enter a String: ");
			gets(testStringArray[i]);
		}

		char *string1 = testStringArray[0];
		char *string2 = testStringArray[1];
		char *string3 = testStringArray[2];

		char *stringPointerArray[3] = { string1, string2, string3 };

		int numOfWord = sizeof(testStringArray) / sizeof(testStringArray[0]);
		arrangeStringsPointerByBubbleSorting(stringPointerArray, numOfWord);

		for (int i = 0; i < numOfWord; i++){
			printf("%s - ", *(stringPointerArray+i));
		}
		printf("\n");
	}

	//-- Question 5
	else if (userChoise == 5){

		char *words;
		char string[] = "shalev airplane:home,phone:luggege days,oliver:yosef,los angeles:new york,washington:dublin,";
		char *delimiters = " :,";

		words = myStrtok(string, delimiters);
		while (words != NULL){
			printf("%s\n", words);
			words = myStrtok(NULL, delimiters);
		}
	}
	system("pause");
}

