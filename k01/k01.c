#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
extern double ave_online(double val,double ave,int N);
extern double var_online(double val,double ave,int N,double square_ave);

int main(void)
{   double ave=0,var=0,square_ave=0, suiteivar=0;
    int N=0;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

         N++;     
         
        var=var_online(val,ave,N,square_ave);
        ave=ave_online(val,ave,N);
        square_ave=ave_online(pow(val,2),square_ave,N);
    }
    if(N==1){
        suiteivar=0;
    }
    else{
        suiteivar=(double)N/(N-1)*var;
    }
    printf("hyouhonn ave: %lf\n", ave);
    printf("hyouhonn var: %lf\n", var);
    printf("suitei ave: %lf\n", ave);
    printf("suitei var: %lf\n", suiteivar);
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    return 0;
}
double ave_online(double val,double ave, int N){
    ave=(ave*(N-1)/N)+val/N;
    return(ave);
}

double var_online(double val,double ave,int N,double square_ave){
    double var;
    var=(((N-1)*square_ave)/N+pow(val,2)/N-pow(((N-1)*ave)/N+val/N,2));
    return(var);
}

