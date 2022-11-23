#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int find_number_of_cities();
char** create_city_name_array(int number_of_cities);
int** create_djikstra_array(int number_of_cities, char** city_name_array);
unsigned int index_city_names(char* name, char** city_name_array, int num_cities);
unsigned int hash_city_names_nondynamic(char* name);


int minDistance(int dist[], bool sptSet[],int number_of_cities)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < number_of_cities; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int number_of_cities)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < number_of_cities; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int** graph, int src, int number_of_cities)
{
    int dist[number_of_cities]; // The output array.  dist[i] will hold the
    // shortest
    // distance from src to i

    bool sptSet[number_of_cities]; // sptSet[i] will be true if vertex i is
    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < number_of_cities; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < number_of_cities - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet, number_of_cities);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < number_of_cities; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, number_of_cities);
}




int main() {

    int nr = find_number_of_cities();
    char** city_name = create_city_name_array(nr);
    int** city_distance_array = create_djikstra_array(nr, city_name);

    dijkstra(city_distance_array,0,nr);
    for (int  i= 0; i < nr; ++i) {
        printf("\n");
        for (int j = 0; j < nr; ++j) {
            printf("%5d",city_distance_array[i][j]);
        }
    }

    for (int i = 0; i < nr; ++i) {
        printf("\n%s => %u\n",city_name[i],
               index_city_names(city_name[i], city_name, nr));
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

int** create_djikstra_array(int number_of_cities, char** city_name_array){
    FILE *city_data = fopen("cities.txt","r");
    if(city_data == NULL){
        printf("file not found");
    }

    int **djikstra_array;
    djikstra_array = (int**)malloc(number_of_cities  * (sizeof(int*)));
    for (int i = 0; i < number_of_cities; ++i) {
        djikstra_array[i]= (int*) malloc(number_of_cities*sizeof(int));
    }

    for (int i = 0; i < number_of_cities; ++i) {
        for (int j = 0; j < number_of_cities; ++j) {
            djikstra_array[i][j]=0;
        }
    }

    char temp1[20];
    char temp2[20];
    int value = 0;
    while(fscanf(city_data,"%s %s %d",temp1,temp2,&value)==3){
        djikstra_array[index_city_names(temp1,city_name_array,number_of_cities)]
                      [index_city_names(temp2, city_name_array, number_of_cities)]=value;
    }
    return djikstra_array;
}

unsigned int hash_city_names_nondynamic(char* name){
    if(strcmp(name,"frederikshavn")==0)
        return 0;
    else if(strcmp(name,"saeby")==0)
        return 1;
    else if(strcmp(name,"hjorring")== 0)
        return 2;
    else if(strcmp(name,"bronderslev")== 0)
        return 3;
    else if(strcmp(name,"norresundby")== 0)
        return 4;
    else if(strcmp(name,"aalborg")== 0)
        return 5;
    else if(strcmp(name,"stovring")== 0)
        return 6;
    else return -1;
}

unsigned int index_city_names(char* name, char** city_name_array, int num_cities){
    for (int i = 0; i < num_cities; ++i) {
        if (strcmp(name,city_name_array[i]) == 0){
            return i;
        }
    }
    printf("index function error occurred\n");
}