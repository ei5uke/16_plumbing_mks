#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int prompt;
    char input[256], back[256];
    mkfifo("transfer", 0666);
    mkfifo("return", 0666);

    while (1)
    {
        printf("Input a word:\n");
        fgets(input, 256, stdin);
        prompt = open("transfer", O_WRONLY);
        write(prompt, input, 256);
        close(prompt);

        prompt = open("return", O_RDONLY);
        read(prompt, back, 256);
        close(prompt);
        printf("Encrypted msg: %s\n", back);
    }
    return 0;
}