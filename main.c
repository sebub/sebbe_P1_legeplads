#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

void convert_to_lowercase(char *str);

int main() {
    int co2 = 0, cost = 0, time = 0, remainder = 100;

    while(remainder > 0) {

        char input[5];
        int value = 0;
        printf("Env \tCost \tTime \tRemaining\n");
        printf("%d \t%d \t%d \t%d\n", co2, cost, time, remainder);

        scanf("%s \t%d",input, &value);
        convert_to_lowercase(input);
        if(strcmp(input,"env")==0)
            co2 +=value;
        else if(strcmp(input,"cost")==0)
            cost += value;
        else if(strcmp(input,"time")==0)
            time += value;
        else
            printf("invalid input\n");

        remainder -= value;
        //system("cls");


    }
    return 0;

}

void convert_to_lowercase(char *str){//runs over every letter in the string and converts them to lowercase
    for (int i = 0; i < strlen(str); ++i) {
        str[i]= tolower(str[i]);
    }
}
