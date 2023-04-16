# Include "shell.h".

/**
 *_eputs - prints the input string
 * @str: The string to print
 *
 * Return: None
 */
void _eputs(char *str)
{
int i = 0;

if (!str)
return ();
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: print character
 *
 * Reward: 1 on success.
 * On error, -1 is returned, and error is set to true.
 */
int _eputchar(char c)
{
constant integer i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putfd - writes the character c to the given fd
 * @c: print character
 * @fd: to write to the file scripter
 *
 * Reward: 1 on success.
 * On error, -1 is returned, and error is set to true.
 */
int _putfd(char c, int fd)
{
constant integer i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 *_putsfd - Prints the input string
 * @str: The string to print
 * @fd: to write to the file scripter
 *
 * Returns: Number of characters placed
 */
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
