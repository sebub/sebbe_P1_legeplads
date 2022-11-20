#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_number_of_cities();
//void create_city_name_array(char city_name_array[20][20]);

int main() {


    int nr = find_number_of_cities();


    char city_name_array[nr][20];

    FILE *city_data = fopen("cities.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }

    char temp1[30];
    char prev_city[30];
    int index = 0;

    while(fscanf(city_data,"%s %*s %*d",temp1)==1){

        if(strcmp(temp1,prev_city) != 0) {
            strcpy(city_name_array[index],temp1);
            index++;
        }
        strcpy(prev_city,temp1);
    }

    fclose(city_data);

    printf("%d\n",nr);

    for (int i = 0; i < nr; ++i) {

        printf("%s\n",city_name_array[i]);
    }


}
int find_number_of_cities(){
    FILE *city_data = fopen("cities.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }


    char temp1[30];
    char prev_city[30];
    int number_of_cities = 0;

    while(fscanf(city_data,"%s %*s %*d",temp1)==1){

        if(strcmp(temp1,prev_city) != 0) {
            number_of_cities++;
        }
        strcpy(prev_city,temp1);
    }
    fclose(city_data);
    return number_of_cities;
}

/*void create_city_name_array(char city_name_array[20][20]){
    FILE *city_data = fopen("cities.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }

    char temp1[30];
    char prev_city[30];
    int index = 0;

    while(fscanf(city_data,"%s %*s %*d",temp1)==1){


        if(strcmp(temp1,prev_city) != 0) {
            printf("\n\tNumber: %d City: %s\n", index,temp1);
            strcpy(city_name_array[index],temp1);
            index++;
        }
        strcpy(prev_city,temp1);
    }

    fclose(city_data);

}*/