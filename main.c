#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add(int number);
void removeTODO();
void see();

char choice =' ';

int main() {
    
        FILE *file = fopen("missions.txt" ,"w");
        fclose(file);
        int numberOfSentence = 0;
        int function;
        do
            {
        printf("TO-DO List: \n");
        printf("Which function do you like to do: \n");
        printf("1. add\n");
        printf("2. remove\n");
        printf("3. see TO-DO");
        scanf("%d",&function);
        switch(function) {
            case 1:
                numberOfSentence++;
                add(numberOfSentence);
                break;
            case 2:
                break;
            case 4:
                see();
                break;
        }
        scanf("%c",&choice);
    } while (choice == 'y');
    
    
}

void add(int number) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    char sentence[100];
    printf("Please add a sentence to TO-DO: ");
    fgets(sentence, sizeof(sentence), stdin);
    FILE *file2 = fopen("missions.txt" ,"a");
    printf("Do you want to mark this TO-DO(1/0)\n");
    fprintf(file2, "%d %s", number, sentence);
    fclose(file2);
}

void see() {
    FILE *file = fopen("missions.txt", "r");
    char satir[256];
    while (fgets(satir, sizeof(satir), file)) {
        printf("%s", satir);
    }
    fclose(file);
}