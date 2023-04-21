#include <shell.h>


#define BUFFER_SIZE 1024

char *_getline(void)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0;
    static int bytes_read = 0;
    char *line = NULL;
    int line_len = 0;
    int i;

    while (1) {
        // If we've read all bytes in the buffer, read more bytes
        if (buffer_pos >= bytes_read) {
            bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (bytes_read <= 0) {
                // EOF or error
                return line;
            }
        }

        // Search for the newline character
        for (i = buffer_pos; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                line_len += i - buffer_pos;
                line = realloc(line, line_len + 1);
                if (!line) {
                    // Allocation error
                    return NULL;
                }
                memcpy(line + line_len, buffer + buffer_pos, i - buffer_pos);
                line[line_len + i - buffer_pos] = '\0';
                buffer_pos = i + 1;
                return line;
            }
        }

        // If we didn't find a newline, add the bytes to the line buffer
        line_len += bytes_read - buffer_pos;
        line = realloc(line, line_len + 1);
        if (!line) {
            // Allocation error
            return NULL;
        }
        memcpy(line + line_len - (bytes_read - buffer_pos), buffer + buffer_pos, bytes_read - buffer_pos);
        buffer_pos = bytes_read;
    }
}
