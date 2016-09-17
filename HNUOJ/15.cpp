#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 1024;
static int counter[10]; // store the times that number being replaced
static char output[SIZE]; // store the result
static char replace_table[10][20] = {
	"(Zero)", "(One)", "(Two)", "(Three)", "(Four)",
	"(Five)", "(Six)", "(Seven)", "(Eight)", "(Nine)"
};

int digit(char c)
// to judge weather c is a digit, if so return the number c stands for
// otherwise return -1
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return -1;
}

char *replace(char *input)
{
	int slen = strlen(input);
	int index = 0; // to index the output
	for (int i = 0; i < slen; ++i)
	{
		int num = digit(input[i]);
		if (num != -1)
		{
			strcpy(output + index, replace_table[num]);
			index += strlen(replace_table[num]); // move forward the index
			counter[num] += 1;
		}
		else
			output[index++] = input[i]; // do not replace the non-digit
	}
	output[index] = '\0'; 
	return output;
}

int main()
{
	char input[SIZE];
	gets(input); // get the input
	cout << replace(input) << endl;
	for (int i = 0; i < 9; ++i)
	{
		cout << counter[i] << " ";
	}
	cout << counter[9] << endl;
	//system("pause");
	return 0;
}