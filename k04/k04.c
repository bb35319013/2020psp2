#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct prof_data{
           int ID;
           char height;
           int gender;
    }; 
int main(void)
{   
    struct prof_data person_data[14];
    int search_ID, a, i=0, l=0, n;
    char height_buf[32];
    char fname[FILENAME_MAX];
    FILE* fp_height;
    FILE*fp_ID;


    printf("input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);
    printf("ba-ka\n");
    fp_height = fopen(fname,"r");
    if(fp_height==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(height_buf, sizeof(height_buf), fp_height)!=NULL){
         sscanf(height_buf, "%d, %c", &person_data[14].gender, &person_data[14].height);
    }

    printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp_ID = fopen(fname,"r");
    if(fp_ID==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("which ID's date do you want?");
    sscanf("%d", &search_ID);

    while(fgets(person_data[14].ID,sizeof(person_data[14].ID),fp_ID) != NULL){
        sscanf(person_data[14].ID,"%d",&a);
        if(search_ID==a){
            i++;
            n=l;
        }
        l++;
    }
    if(i==0){
        printf("No data\n");
    }
    if(i==1){
    printf("ID:%d\n", person_data[n].ID);
    if(person_data[n].gender==1){
        printf("gemder:male\n");
    }
    if(person_data[n].gender==2){
        printf("gender:female\n");
    }
    printf("height:%d\n", person_data[n].height);
}


    return 0;
};