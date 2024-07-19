#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void add(int number);
void removeTODO();
void see();
void install();
void update( char *ptr );

#define FILENAME_SIZE 1024
#define MAX_LINE 2048



char sentence[200];
int numberOfSentence = 0; 

int main() {
    
        FILE *file = fopen("missions.txt" ,"w");
        fclose(file);
        const char *filename = "missions.txt";
        int function;
        int choice;
        do{
        printf("TO-DO List: \n");
        printf("Which function do you like to do: \n");
        printf("1. add\n");
        printf("2. remove\n");
        printf("3. see TO-DO\n");
        printf("Function: ");
        scanf("%d",&function);
        if(function == 1) {
            numberOfSentence++;
            add(numberOfSentence);
        } else if(function == 2) {
            removeTODO();
        } else {
            see();
        }
        printf("Do you want to continue(1/0): ");
        scanf("%d",&choice);
    } while (choice == 1);
    
    
}

void add(int number) {
    int c;
    int choice2;
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("Please add a sentence to TO-DO: ");
    fgets(sentence, sizeof(sentence), stdin);
    FILE *file2 = fopen("missions.txt" ,"a");
    printf("Do you want to mark this TO-DO(1/0)\n");
    scanf("%d",&choice2);
    if(choice2 == 1) {
        fprintf(file2, "%d %s\n", number, sentence);
    } else {
    fprintf(file2, "%d %s", number, sentence);        
    }
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

void install() {
    system("cls");
    FILE *writeFile = fopen("temp.txt", "w");
    FILE *readFile = fopen("missions.txt", "r");
    if(writeFile != NULL){
        if(readFile != NULL){
            while(!feof(readFile)){
            fscanf(readFile, "%d %s", &numberOfSentence, sentence);
            fprintf(writeFile, "%d %s\n",&numberOfSentence, sentence);
            }
        }
    }
    remove("missions.txt");
    fclose(writeFile);
    fclose(readFile);

}

void update( char *ptr ) {
    system("cls");
    FILE *writeFile = fopen("missions.txt", "w");
    FILE *readFile = fopen("temp.txt", "r");
    if(writeFile != NULL){
        if(readFile != NULL){
            while(!feof(readFile)){
            fscanf(readFile, "%d %s", &numberOfSentence, sentence);
            if(strcmp(ptr, sentence)== 0){
                continue;
            }
            fprintf(writeFile, "%d %s\n",&numberOfSentence, sentence);
            }
        }
    }
    remove("temp.txt");
    fclose(writeFile);
    fclose(readFile);
}

void removeTODO() {
    system("cls");
    char sentence[500];
    FILE *fileRead = fopen("missions.txt", "r");
    printf("Enter the the sentence: ");
    scanf("%s",&sentence);
    if(fileRead != NULL){
        while(!feof(fileRead)){
            fscanf(fileRead, "%d %s", &numberOfSentence, sentence);
            if(strcmp(sentence, sentence) == 0){
                fclose(fileRead);
                install();
                update(sentence);
                break;
            }
        }
    }
}
