#include <stdio.h>
#include <stdlib.h>


size_t strlen(const char* str);
char* strcpy(char* restrict dest, const char* restrict src);
char* strcat(char* restrict dest, const char* restrict src);
int strcmp(const char* str1, const char* str2);
void* allocAndInit(unsigned int size, char* str);


int main(void)
{
    char* text1 = (char*)allocAndInit(6, "Hallo");
    char* text2 = (char*)allocAndInit(6, "Hallooo");
    char* destCat = (char*)allocAndInit(strlen(text2) + strlen(text1) + 1, text1);

    printf("Strlen: %llu\n", strlen(text1));
    printf("Strcmp: %d\n", strcmp(text1, text2));
    printf("Strcpy: %s\n", strcpy(text1, text2));
    printf("Strcat: %s\n", strcat(destCat, text1));

    free(text1), free(text2), free(destCat);

    return EXIT_SUCCESS;
}


size_t strlen(const char* str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0' ;i++)
    {
        counter++;
    }

    return counter;
}


char* strcpy(char* restrict dest, const char* restrict src)
{
    int i;

    for (i = 0; i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest;
}


char* strcat(char* restrict dest, const char* restrict src)
{
    size_t dest_len = strlen(dest) + strlen(src);
    int i;

    for (i = 0; i < strlen(src); i++)
    {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest;
}


int strcmp(const char* str1, const char* str2)
{
    int counter = 0;
    size_t condition = strlen(str2);

    if (strlen(str2) < strlen(str1)) condition = strlen(str1);

    for (int i = 0; i < condition; i++)
    {
        if (str1[i] != str2[i])
        {
            counter++;
        }
    }
    return counter;
}


/*int strcmp(const char* str1, const char* str2)
{
    int counter = 0;
    size_t condition = strlen(str1) + strlen(str2);

    if (strlen(str2) < strlen(str1)) condition = strlen(str1);

    for (int i = 0; i < condition; i++)
    {
        if (str1[i] != str2[i])
        {
            counter++;
        }
    }
    return counter;
}*/


void* allocAndInit(unsigned int size, char* str)
{
    void* ptr = malloc(size * sizeof(char));

    if (ptr == NULL) EXIT_FAILURE;

    strcpy(ptr, str);

    return ptr;
}