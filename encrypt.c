#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void bob(char *input)
{
    char temp[256];
    int len = strlen(input);

    for (int i = 0; i < len / 2; i++)
    {
        temp[i] = input[len - i - 1];
        input[len - i - 1] = input[i];
        input[i] = temp[i];
    }
}

int main()
{
    
    int prompt;
    char input[256];

    while (1)
    {
        prompt = open("transfer", O_RDONLY); //send prompt to encrypt.c
        read(prompt, input, 256);
        close(prompt);
        printf("Received msg: %s\n", input);
        bob(input);
        prompt = open("return", O_WRONLY);
        write(prompt, input, 256);
        close(prompt);
    }
    return 0;
}