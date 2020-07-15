#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double val,L_a=1,L_b=1,xa,xb;
    const double Aave=170.8,Avar=pow(5.43,2),Bave=169.7,Bvar=pow(5.5,2);
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


        xa=(val-Aave)/sqrt(Avar);
        xb=(val-Bave)/sqrt(Bvar);
        L_a=L_a*p_stdnorm(xa);
        L_b=L_b*p_stdnorm(xb);
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L_a);
    printf("L_B: %f\n",L_b);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

