#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    struct prof_data{
           int ID[13];
           double height[13];
           int gender[13];
    }; 
    struct prof_data x;
    int search_ID, a, i=0, l=0, n;
    char seibetu;
    char fname[FILENAME_MAX];
    FILE* fp_height;
    FILE*fp_ID;


    printf("input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp_height = fopen(fname,"r");
    if(fp_height==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    };
    while(fgets(x.height,sizeof(x.height),fp_height) != NULL);
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

    while(fgets(x.ID,sizeof(x.ID),fp_ID) != NULL){
        sscanf(x.ID,"%lf",&a);
        if(search_ID==a){
            i++;
            n=l;
        }
        l++;
    };
    if(i==0){
        printf("No data\n");
    };
    if(i==1){
    if(x.gender[n]==1){
        seibetu="male";
    };
    if(x.gender[n]==2){
        seibetu="female";
    };
    printf("ID:%d\n", x.ID[n]);
    printf("gender:%c\n", seibetu);
    printf("height:%d\n", x.height[n]);
};


    return 0;
};