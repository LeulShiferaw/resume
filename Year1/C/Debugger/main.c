#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_char(char *str, char c) {
    int i,count=0;
    for(i=0;str[i]!='\0';i++) {
        if(str[i] == c) {
            count++;
        }
    }
    return count;

}

int main()
{
    int n;
    printf("Max no of characters: ");
    scanf("%d",&n);
    getchar();

    char *str = (char*)malloc(sizeof(char)*n);

    printf("Enter the string:\n");
    fgets(str, sizeof(char)*n, stdin);
    str[strlen(str)-1] = '\0';

    printf("The character 'B' occurs %d times\n",count_char(str,'B'));
    printf("The character 'p' occurs %d times\n",count_char(str,'p'));
    printf("The character 'i' occurs %d times\n",count_char(str,'i'));
    printf("The character 'D' occurs %d times\n",count_char(str,'D'));
    printf("The character 'z' occurs %d times\n",count_char(str,'z'));

    free(str);
    return 0;
}
