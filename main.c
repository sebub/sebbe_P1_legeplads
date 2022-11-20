#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    FILE *city_data = fopen("cities.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }

    char temp1[30];
    char temp2[30];
    char prev_city[30];
    int distance, number_of_cities = 0;
    char city_name_array[10][20];

    while(fscanf(city_data,"%s %s %d",temp1, temp2, &distance)==3){
        printf("%s -> %s, is %dkm\n",temp1,temp2,distance);

        if(strcmp(temp1,prev_city) != 0) {
            printf("\n\tNumber: %d City: %s\n", number_of_cities,temp1);
            strcpy(city_name_array[number_of_cities],temp1);
            number_of_cities++;
        }
        strcpy(prev_city,temp1);
        printf("This is prev city:%s\n", prev_city);
    };

    printf("%d\n",number_of_cities);

    for (int i = 0; i < number_of_cities; ++i) {
        printf("*%s*\n",city_name_array[i]);

    }


}
