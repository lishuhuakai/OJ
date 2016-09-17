#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
static char start_line[10];
static char end_line[10];
static char ciphertext[1024];
static char plaintext[1024]; /*Ã÷ÎÄ*/

bool is_letter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

char map(char c)
{
	if (c > 'E')
		return c - 5;
	else
		return c + 21;
}
char * decryption(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (is_letter(str[i]))
			plaintext[i] = map(str[i]);
		else
			plaintext[i] = str[i];
	}
	plaintext[len] = '\0';
	return plaintext;
}
int main()
{
	while (true)
	{
		gets(start_line);
		if (strcmp(start_line, "ENDOFINPUT") == 0)
			break;
		gets(ciphertext); 
		gets(end_line);
		cout << decryption(ciphertext) << endl;
	}
	return 0;
}
