#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_number_of_cities();
//void create_city_name_array(char city_name_array[20][20]);
char** create_city_name_array(int number_of_cities);

int main() {


    int nr = find_number_of_cities();
    char** cityname = create_city_name_array(nr);
    int** city_distance_array =


    for (int i = 0; i < nr; ++i) {

        printf("%s\n",cityname[i]);
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

char** create_city_name_array(int number_of_cities){
    FILE *city_data = fopen("cities.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }
    char **citynames;
    citynames = malloc(number_of_cities * sizeof(char*));
    char temp1[20];
    char prev_city[20];
    int index = 0;


    while(fscanf(city_data,"%s %*s %*d",temp1)==1){
        if(strcmp(temp1,prev_city) != 0) {
            citynames[index] = malloc((strlen(temp1)*sizeof(char)));
            strcpy(citynames[index],temp1);
            index++;

        }
        strcpy(prev_city,temp1);
    }

    fclose(city_data);
    return citynames;
}

int** create_djikstra_array(int number_of_cities){
    
}