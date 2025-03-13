#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define H 50

struct route{
    char ek[H];
    int mikos;
    int ana,kata;
    int maxIps,minIps;
    char term[H];
};

void sortMi(struct route ip[],int L){
    int i,j;
    struct route temp;

    for(i=0;i<L-1;i++){
        for(j=1+i;j<L;j++){
            if(ip[i].mikos<ip[j].mikos){
                temp=ip[j];
                ip[j]=ip[i];
                ip[i]=temp;
            }
        }
    }
    return;
}

void read(char s[]){
    scanf(" ");
    fgets(s,H,stdin);
    s[strcspn(s,"\n")]='\0';
    return;
}

struct route *readFromInput(int *n){
    int i,N;
    struct route *A;
    scanf("%d",&N);
    A=malloc(N*sizeof(struct route));
    for(i=0;i<N;i++){
        read(A[i].ek);
        scanf("%d %d %d %d %d ",&A[i].mikos,&A[i].ana,&A[i].kata,&A[i].maxIps,&A[i].minIps);
        read(A[i].term);
    }
    *n=N;
    return A;
}

void printData(struct route B[],int L){
    int i;
    int time,time2;
    sortMi(B,L);
    for(i=0;i<L;i++){
        time=round((B[i].mikos/65.0)+B[i].ana/10.0);
        time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
        printf("From %s to %s\n",B[i].ek,B[i].term);
        printf("Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
        printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
        printf("Length %d, Estimated time %d min\n",B[i].mikos,time);
        printf("\n");
        if(strcmp(B[i].ek, B[i].term)!=0){
                printf("From %s to %s\n",B[i].term,B[i].ek);
                printf("Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
                printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
                printf("Length %d, Estimated time %d min\n",B[i].mikos,time2);
                printf("\n");
            }
    }
}

void findShort(struct route B[],int L){
    int i,mi,time,time2;
    sortMi(B,L);
    scanf("%d",&mi);
    for(i=0;i<L;i++){
        if(B[i].mikos<=mi){
            time=round((B[i].mikos/65.0)+B[i].ana/10.0);
            time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
            printf("From %s to %s\n",B[i].ek,B[i].term);
            printf("Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time);
            printf("\n");
            if(strcmp(B[i].ek, B[i].term)!=0){
                printf("From %s to %s\n",B[i].term,B[i].ek);
                printf("Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
                printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
                printf("Length %d, Estimated time %d min\n",B[i].mikos,time2);
                printf("\n");
            }
        }
    }
    return;
}

void findLocation(struct route B[],int L){
    int i,time,time2;
    char name[H];
    sortMi(B,L);
    read(name);
    for(i=0;i<L;i++){
        if(strcmp(name, B[i].ek)==0){
            time=round((B[i].mikos/65.0)+B[i].ana/10.0);
            printf("From %s to %s\n",B[i].ek,B[i].term);
            printf("Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time);
            printf("\n");
        }
        else if(strcmp(name, B[i].term)==0){
            time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
            printf("From %s to %s\n",B[i].term,B[i].ek);
            printf("Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time2);
            printf("\n");
        }
    }
    return;
}

void findUpHill(struct route B[],int L){
    int i,time,time2;
    sortMi(B,L);
    for(i=0;i<L;i++){
        if(B[i].ana>B[i].kata){
            time=round((B[i].mikos/65.0)+B[i].ana/10.0);
            printf("From %s to %s\n",B[i].ek,B[i].term);
            printf("Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time);
            printf("\n");
        }
        if(B[i].ana<B[i].kata){
            time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
            printf("From %s to %s\n",B[i].term,B[i].ek);
            printf("Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time2);
            printf("\n");
        }
    }
    return;
}

void findDownHill(struct route B[],int L){
    int i,time,time2;
    sortMi(B,L);
    for(i=0;i<L;i++){
        if(B[i].ana>B[i].kata){
            time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
             printf("From %s to %s\n",B[i].term,B[i].ek);
            printf("Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time2);
            printf("\n");
        }
        if(B[i].kata>B[i].ana){
            time=round((B[i].mikos/65.0)+B[i].ana/10.0);
            printf("From %s to %s\n",B[i].ek,B[i].term);
            printf("Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time);
            printf("\n");
        }
    }
    return;
}

void findAltitude(struct route B[],int L){
    int i,time,time2;
    int mini,maxi;
    sortMi(B,L);
    scanf("%d%d",&mini,&maxi);
    for(i=0;i<L;i++){
        if((B[i].minIps>=mini && B[i].minIps<= maxi)&&(B[i].maxIps>=mini && B[i].maxIps<= maxi)){
            time=round((B[i].mikos/65.0)+B[i].ana/10.0);
            time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
            printf("From %s to %s\n",B[i].ek,B[i].term);
            printf("Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,time);
            printf("\n");
            if(strcmp(B[i].ek, B[i].term)!=0){
                printf("From %s to %s\n",B[i].term,B[i].ek);
                printf("Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
                printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
                printf("Length %d, Estimated time %d min\n",B[i].mikos,time2);
                printf("\n");
            }
        }
    }
    return;
}

void findTimely(struct route B[],int L){
    int i,T,Time,Time2;
    float time,time2;
    sortMi(B,L);
    scanf("%d",&T);
    for(i=0;i<L;i++){
        time=(B[i].mikos/65.0)+B[i].ana/10.0;
        time2=(B[i].mikos/65.0)+B[i].kata/10.0;
        if((time-T)<0){
            Time=round((B[i].mikos/65.0)+B[i].ana/10.0);
            printf("From %s to %s\n",B[i].ek,B[i].term);
            printf("Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
            printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
            printf("Length %d, Estimated time %d min\n",B[i].mikos,Time);
            printf("\n");
        }
        if((time2-T<0)){
            if(strcmp(B[i].ek, B[i].term)!=0){
                Time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
                printf("From %s to %s\n",B[i].term,B[i].ek);
                printf("Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
                printf("Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
                printf("Length %d, Estimated time %d min\n",B[i].mikos,Time2);
                printf("\n");
            }
        }
    }
    return;
}

// PART 3


struct route *readFromFile(int *n){
    FILE *fl;
    int i,c=0,N;
    char text[H];
    struct route *A;
    read(text);
    fl=fopen(text,"r");
    if(fl!=NULL){
        fscanf(fl,"%d",&N);
        A=malloc(N*sizeof(struct route));
        for(i=0;i<N;i++){
            fscanf(fl," ");
            fgets(A[i].ek,H,fl);
            A[i].ek[strcspn(A[i].ek,"\n")]='\0';
            fscanf(fl,"%d %d %d %d %d ",&A[i].mikos,&A[i].ana,&A[i].kata,&A[i].maxIps,&A[i].minIps);
            fscanf(fl," ");
            fgets(A[i].term,H,fl);
            A[i].term[strcspn(A[i].term,"\n")]='\0';

        }
    }
    fclose(fl);
    *n=N;
    return A;
}

void saveData(struct route B[],int L){
    FILE *fl;
    int i,time,time2;
    char text[H];
    read(text);
    sortMi(B,L);
    fl=fopen(text,"w");

    for(i=0;i<L;i++){
        time=round((B[i].mikos/65.0)+B[i].ana/10.0);
        time2=round((B[i].mikos/65.0)+B[i].kata/10.0);
        fprintf(fl,"From %s to %s\n",B[i].ek,B[i].term);
        fprintf(fl,"Uphill %d, Downhill %d\n",B[i].ana,B[i].kata);
        fprintf(fl,"Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
        fprintf(fl,"Length %d, Estimated time %d min\n",B[i].mikos,time);
        fprintf(fl,"\n");
        if(strcmp(B[i].ek, B[i].term)!=0){
                fprintf(fl,"From %s to %s\n",B[i].term,B[i].ek);
                fprintf(fl,"Uphill %d, Downhill %d\n",B[i].kata,B[i].ana);
                fprintf(fl,"Max altitude %d, Min altitude %d\n",B[i].maxIps,B[i].minIps);
                fprintf(fl,"Length %d, Estimated time %d min\n",B[i].mikos,time2);
                fprintf(fl,"\n");
            }
    }
}

