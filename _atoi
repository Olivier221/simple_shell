#include "shell.h"

/**
 * interactive - Returns true if the shell is in interactive mode
 * @info: structure address
 *
 * Returns: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Check if a character is a delimiter
 * @c: Character to check
 * @delim: delimiter string
 * Returns: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
while (*daelim)
if (*delim++ ​​== c)
return (1);
return (0);
}

/**
 *_isalpha - check for alphanumeric characters
 *@c: character to be entered
 *Returns: 1 if c is an alphabetic character, 0 otherwise
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
Except that
return (0);
}

/**
 *_atoi - convert string to integer
 *@s: String to convert
 *Returns: 0 if the string does not contain a number, otherwise the number is converted
 */

int _atoi(char *s)
{
int i , sign = 1 , flag = 0 , exit .
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flags != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else (flag == 1)
flag = 2;
}

if (sign == -1)
output = - result;
Except that
output = result;

return (output);
}
