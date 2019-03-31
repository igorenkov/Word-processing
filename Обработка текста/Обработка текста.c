#include <stdio.h>
#include <string.h>
#define SIZE 100
//Функция замены в строке переменной на i-й позиции на "a"
void replace_symb(char *str, int i, char a) {
	str[i] = a;
}
//Функция удаления из элемента из i-й позиции строки
void delete_symb(char *str, int i) {
	
	for (int j = i; j < SIZE - 1; j++) {
		str[j] = str[j + 1];
	}
}
//Функция добавления элемента "a" в i-ю позицию строки
void insert_symb(char *str, int i, char a) {

	for (int j = SIZE; j > i - 1; j--) {
		str[j + 1] = str[j];
	}
	str[i] = a;
}
//Функция корректировки строки
void correct_str(char *str) {
	for (int i = 0; i < SIZE; i++) {
		if (str[0] == ' ') {	//Проверка на пробелы перед первой буквой
			delete_symb(str, 0);
			i--;
		}
		else if (str[0] >= 'a' && str[0] <= 'z') {	//Проверка на строчную первую букву
			str[0] -= 32;
		}
		else if (str[i] == ' ' && str[i + 1] == ' ') {	//Проверка на два подряд идущих пробела
			delete_symb(str, i);
			i--;
		}
		else if (str[i] == ' ' && (str[i + 1] == '.' || str[i + 1] == ',')) {	//Проверка на отсутствие пробела перед знаком препинания
			delete_symb(str, i);
			i--;
		}
		else if (str[i] == ' ' && (str[i - 1] == '.' || str[i - 1] == '?' || str[i - 1] == '!') && (str[i + 1] >= 'a' && str[i + 1] <= 'z')) {	//Проверка на строчную букву в начале предложения
			str[i + 1] -= 32;
		}
		else if ((str[i] == ',' || str[i] == ':' || str[i] == ';' || str[i] == '.') && str[i + 1] != ' ') {	//Проверка на пробел после после конца предложения
			insert_symb(str, i + 1, ' ');
			}

	}
}

int main() {
	char ch;
	do {
		char str[SIZE];

		printf("Input text: \n");
		fgets(str, SIZE, stdin);

		correct_str(str);

		printf("Corrected text: \n");
		puts(str);

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		scanf_s("%c", &ch);
		getchar();
	} while (ch == 'y' || ch == 'Y');

	return 0;
}