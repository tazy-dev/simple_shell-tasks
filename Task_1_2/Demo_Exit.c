#include "shell.h"
int _fork(char *buffer)
{
    /*if (fgets(buffer, BUFFER_SIZE,stdin) ==NULL){
    write(Alternative function for printing);}*/


buffer[strcspn(buffer, "\n")] = '\0';
if (strcmp(buffer, "exit") == 0)
{
	return (1);
}
	return (0);
}
