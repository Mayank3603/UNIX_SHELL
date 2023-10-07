#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
int date_function(char *arg1,char *arg2){
    
    if(strcmp(arg1,"--date")==0 && strcmp("hello",arg2)==0){
        printf("date: option '--date: requires an argument\n");
        return 1;
    }
    if( strcmp("hello",arg1)!=0){
        if(arg1[0]!='-'){
            if(strcmp("hello",arg2)==0){
                printf("date: invalid date %s\n",arg1);
                return 1;
            }
            else if(strcmp("hello",arg2)!=0 && arg2[0]!='-'){
                printf("date: extra operand '%s\n",arg2);
                return 1;
            }
        }
        
    }
    char * uni="-universal";
    char * utc="-utc";
    int u_found=0;
    char c;
    int date_found=0;

    if(strcmp(arg1,"--date=\"next")==0){
        date_found=1;            
    }
   
    if(arg1[0]=='-' && strcmp("hello",arg1)!=0 && date_found==0){
       
   
        if(arg1[1]!='-'){
                if(arg1[1]=='u' && strlen(arg1)==2){
                    u_found=1;                
                }
                else {
                    printf("date: invalid date '%c'\n",arg1[1]);
                    return 1;
                }
            }
        
        for(int i=1;i<strlen(arg1)-1;i++){
           
           
            if(arg1[1]=='-'&& strlen(arg1)>2){
               
                if(arg1[i+1]==uni[i]){
                    u_found=1;
                }
                else if(arg1[i+1]==utc[i] && strlen(arg1)<6){
                    u_found=1;
                }
               
                else{
                    printf("date: unrecognized option'--%c\n'",arg1[i+1]);
                    return 1;
                }
            }
        }
    }
    
  

    
    if((strcmp(arg1,"hello")==0 && strcmp(arg2,"hello")==0) ||(strcmp(arg1,"--")==0) && (strcmp(arg2,"hello")==0)) {
        time_t t;
        t=time(NULL);
        struct tm tm=*localtime(&t);
        
        char *a=ctime(&t);
        int m=tm.tm_mon+1;
        for(int i=0;i<3;i++){
            printf("%c", a[i]);
        }
        printf(" ");
        switch(m)
        {
            case 1:
                printf("Jan");
                break;
            case 2:
                printf("Feb");
                break;
            case 3:
                printf("Mar");
                break;
            case 4:
                printf("Apr");
                break;
            case 5:
                printf("May");
                break;
            case 6:
                printf("June");
                break;
            case 7:
                printf("July");
                break;
            case 8:
                printf("Aug");
                break;
            case 9:
                printf("Sep");
                break;
            case 10:
                printf("Oct");
                break;
            case 11:
                printf("Nov");
                break;
            case 12:
                printf("Dec");
                break;
        }
        printf("  %d  ",tm.tm_mday);
        if(tm.tm_hour>=12){
        printf("%d:%d:%d PM IST ", tm.tm_hour, tm.tm_min, tm.tm_sec);     
        }
        else{
            printf("%d:%d:%d AM IST ", tm.tm_hour, tm.tm_min, tm.tm_sec);
        }   
        printf("%d\n", tm.tm_year+1900);
        return 1;
    }


    
    else if( (u_found==1) && strcmp("hello",arg2)==0){
      
        time_t t;
        t=time(NULL);
        struct tm tm=*localtime(&t);
        
        char *a=ctime(&t);
        int m=tm.tm_mon+1;
        for(int i=0;i<3;i++){
            printf("%c", a[i]);
        }
        printf(" ");
        switch(m)
        {
            case 1:
                printf("Jan");
                break;
            case 2:
                printf("Feb");
                break;
            case 3:
                printf("Mar");
                break;
            case 4:
                printf("Apr");
                break;
            case 5:
                printf("May");
                break;
            case 6:
                printf("June");
                break;
            case 7:
                printf("July");
                break;
            case 8:
                printf("Aug");
                break;
            case 9:
                printf("Sep");
                break;
            case 10:
                printf("Oct");
                break;
            case 11:
                printf("Nov");
                break;
            case 12:
                printf("Dec");
                break;
        }
        printf("  %d  ",tm.tm_mday);
        tm.tm_hour-=5;
        if(tm.tm_min>30){
            tm.tm_min-=30;

        }
        else{
            tm.tm_min+=30;
            tm.tm_hour-=1;
        }
        if(tm.tm_hour>=12){
            printf("%d:%d:%d PM UTC ", tm.tm_hour, tm.tm_min, tm.tm_sec);     
            }
            else{
                printf("%d:%d:%d AM UTC ", tm.tm_hour, tm.tm_min, tm.tm_sec);
            } 

        printf("%d\n", tm.tm_year+1900);
        return 1;

    }
    
    
    if(strcmp(arg1,"--date=\"next")==0){
        if(strcmp(arg2,"monday\"")==0 || strcmp(arg2,"mon\"")==0 || strcmp(arg2,"tuesday\"")==0 || strcmp(arg2,"tue\"")==0 || strcmp(arg2,"wednesday\"")==0 || strcmp(arg2,"wed\"")==0 || strcmp(arg2,"thursday\"")==0 || strcmp(arg2,"thu\"")==0 || strcmp(arg2,"friday\"")==0 || strcmp(arg2,"fri\"")==0 || strcmp(arg2,"saturday\"")==0 ||strcmp(arg2,"sat\"")==0 ||strcmp(arg2,"sunday\"")==0 ||strcmp(arg2,"sun\"")==0 ){
             
            time_t t;
            t=time(NULL);
            struct tm tm=*localtime(&t);
            char *a=ctime(&t);
            
            
            int day_number=0;
            if(a[2]=='n' && a[1]=='o'){
                day_number=1;
            }
            else if(a[2]=='e'){
                day_number=2;
            }
            else if(a[2]=='d'){
                day_number=3;
            }
            else if(a[2]=='u' ){
                day_number=4;
            }
            else if(a[2]=='i' ){
                day_number=5;
            }
            else if(a[2]=='t' ){
                day_number=6;
            }
            else if(a[2]=='n' && a[1]=='u'){
                day_number=7;
            }
           
            
            char *b=arg2;
            int cur_number=0;
            if(b[2]=='n' && b[1]=='o'){
                cur_number=1;
            }
            else if(b[2]=='e'){
                cur_number=2;
            }
            else if(b[2]=='d'){
                cur_number=3;
            }
            else if(b[2]=='u' ){
                cur_number=4;
            }
            else if(b[2]=='i' ){
                cur_number=5;
            }
            else if(b[2]=='t' ){
                cur_number=6;
            }
            else if(b[2]=='n' && b[1]=='u'){
                cur_number=7;
            }
            
            
            
            int now_day;
            
            if(cur_number>day_number){
                now_day=cur_number-day_number;
            }
            else{
                now_day=cur_number-day_number+7;
            }
            int m=tm.tm_mon+1;
            
            tm.tm_mday=tm.tm_mday+now_day;
            if(tm.tm_mday>28 && m==2 ){
                tm.tm_mday=tm.tm_mday%28;
                m=m+1;
            }
            if(tm.tm_mday>30){
                if(m==4|| m==6|| m==9|| m==11){
                    tm.tm_mday=tm.tm_mday%30;
                    m=m+1;
                }
            }

            if(tm.tm_mday>31){
                if(m==1|| m==3|| m==5|| m==7|| m==8|| m==10|| m==12){
                    tm.tm_mday=tm.tm_mday%31;
                    m=m+1;
                }
            }
        
            printf("%c%c%c", toupper(arg2[0]),arg2[1],arg2[2]); 
            printf(" ");
            switch(m)
            {
                case 1:
                    printf("Jan");
                    break;
                case 2:
                    printf("Feb");
                    break;
                case 3:
                    printf("Mar");
                    break;
                case 4:
                    printf("Apr");
                    break;
                case 5:
                    printf("May");
                    break;
                case 6:
                    printf("June");
                    break;
                case 7:
                    printf("July");
                    break;
                case 8:
                    printf("Aug");
                    break;
                case 9:
                    printf("Sep");
                    break;
                case 10:
                    printf("Oct");
                    break;
                case 11:
                    printf("Nov");
                    break;
                case 12:
                    printf("Dec");
                    break;
            }
          
            
            printf("  %d  ",tm.tm_mday);
            if(tm.tm_hour>=12){
            printf("%d:%d:%d PM IST ", tm.tm_hour, tm.tm_min, tm.tm_sec);     
            }
            else{
                printf("%d:%d:%d AM IST ", tm.tm_hour, tm.tm_min, tm.tm_sec);
            }   
            printf("%d\n", tm.tm_year+1900);

        }
        else{
            
            printf("date: invalid date ");
            int index=0;
            for(int i=0;i<strlen(arg1);i++){
                if(arg1[i]=='"'){
                    index=i;
                    break;
                }
            }
            for(int i=index+1;i<strlen(arg1);i++){
                printf("%c",arg1[i]);
            }
            printf(" '%s\n'",arg2);
        }
        return 1;
        
    }
   
    return 1;
}
int main(int argc,char *argv []){
      
      
    date_function(argv[1],argv[2]);


    return 0;
}
