#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double n;
extern double ave_online(double val,double ave,int N);
extern double var_online(double val,double ave,double var,double n,double x);

int main(void)
{   double ave=0,var=0,x=0, suiteivar=0;
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
         n++;      
     var=var_online(val,ave,var,n,x);
     ave=ave_online(val,ave,N);
     x=ave_online(pow(val,2),x,n);
    }
    if(n==1){
        suiteivar=0;
    }
    else{
        suiteivar=n/(n-1)*var;
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
extern double ave_online(double val,double ave, int N){
    ave=(ave*(N-1)/N)+val/N;
    return(ave);
};

extern double var_online(double val,double ave,double var,double n,double x){
    var=(((n-1)*x)/n+pow(val,2)/n-pow(((n-1)*ave)/n+val/n,2));
return(var);
};

