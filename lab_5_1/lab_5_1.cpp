#include <iostream>
#include <cstdio>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS 
#define ROWS 7
#define COLS 100

using namespace std;

int scan_number_in_range(const int right_border, const int left_border);
int count_words(char* s);
char search_string(char(&text)[ROWS][COLS], char string[], int number_row, int count);
void decode(int count, int number_word, char* string);



int main()
{
	int index = 0;
	char text[ROWS][COLS] = { "I have been tearing around in my fucking nightgown ",
		"Writing in blood on the walls ",
		"Cause the ink in my pen do not work in my notepad ",
		"Do not ask if I am happy, you know that I am not ",
		"But at best I can say I am not sad ",
		"Cause hope is a dangerous thing for a woman like me to have ",
		"Hope is a dangerous thing for a woman like me to have " };

	int left_border = 0;
	cout << "Enter the row number: ";
	const int number_row = scan_number_in_range(ROWS, left_border);

	int right_border_word = count_words(text[number_row]);
	cout << "Enter the word number: ";
	int number_word = scan_number_in_range(right_border_word, left_border);
	number_word++;

	int count_characters = strlen(&text[number_row][COLS]);
	char string[COLS];
	search_string(text, string, number_row, count_characters);
	decode(count_characters, number_word, string);
}


int scan_number_in_range(const int right_border, const int left_border)
{
	while (true) {
		cout << "Enter a number less than " << right_border << " greater than or equal to than " << left_border << endl;
		int number = 0;
		cin >> number;

		if (cin.fail()) {
			cout << "Entered is not a number.\n";
			cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else {
			if ((number >= left_border) && (number < right_border)) {
				return number;
			}
			else {
				if (number < left_border) {
					cout << "The entered number is less " << left_border << endl;
					cin.clear();
				}
				if (number >= right_border) {
					cout << "The entered number is greater than or equal to " << right_border << endl;
					cin.clear();
				}
			}
			}
	}
}

int count_words(char* string) {
	int index, res = 0;
	for (index = 0; string[index]; index++)
		if (string[index] == ' ')
			res++;
	return res;
}

char search_string(char(&text)[ROWS][COLS], char string[], int number_row, int count) {

	for (int index = 0; index < count; index++) {
		string[index] = text[number_row][index];
		cout << string[index];
	}
	cout << endl;
	return string[COLS];
}

void decode(int count, int number_word, char* string) {
	int count_words = 0;
	char* word;
	word = new char[COLS];
	int beginning = 0;

	for (int index = 0; index < count; index++) {

		if ((string[index] != ' ')) {
			word[index] = string[index];
		}
		else {
			count_words++;

			if (count_words == number_word) {
				if (number_word > 1) {
					for (int i = beginning; i < index; i++)
						cout << word[i];
					break;
				}
				else {
					for (int i = 0; i < index; i++)
						cout << word[i];
					break;
				}
			}
			else {
				beginning = index + 1;
				delete[]word;
				word = new char[COLS];
			}
		}
	}

}