#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

int cat_function(char *arg1, char *arg2){
    
    int file_found_1=0;
    int file_found_2=0;
    int E_flag=0;
    int n_flag=0;
    int invalid_1=0;
    int invalid_2=0;
    int unreg=0;
    char c;
    char *unreg_value;
    
    if(arg1[0]=='-' && strcmp(arg1,"hello")!=0){
        
        for(int i=1;i<strlen(arg1);i++){
            if(arg1[1]=='-'){
                unreg=1;
                unreg_value=arg1;
                break;
                
            }
            else if(arg1[i]!='n' && arg1[i]!='E'){
                
                invalid_1=1;
                c=arg1[i];
                break;
            }
            else if(arg1[i]=='n'){
            
                n_flag=1;


            }
            else if(arg1[i]=='E'){
                
                E_flag=1;
            }
        }
    }
    else{

        if(strcmp("hello",arg1)!=0){
             file_found_1 = 1;
        }
            
    } 

    if(arg2[0]=='-' && strcmp(arg2,"hello")!=0){
        
        for(int i=1;i<strlen(arg2);i++){
            if(arg2[1]=='-'){
                unreg=1;
                unreg_value=arg2;
                break;
                
            }
            if(arg2[i]!='n' && arg2[i]!='E'){
                
                invalid_2=1;
                if(invalid_1==0){
                    c=arg2[i];
                }
                
                break;
            }
            else if(arg2[i]=='n'){
            
                n_flag=1;


            }
            else if(arg2[i]=='E'){
                
                E_flag=1;
            }
        }
    }
    else{

        if(strcmp("hello",arg2)!=0){
             file_found_2 = 1;
        }
            
    } 
    

    if(invalid_1==0 && invalid_2==0){
       
        if((strcmp(arg1,"hello")==0 && strcmp(arg2,"hello")==0) ||  (E_flag==1 && strcmp(arg2,"hello")==0)  || (n_flag==1 && strcmp(arg2,"hello")==0)){
           int time = 1800;
        
        char *a;

        if(E_flag==1){
             while (time != 0)
            {
                scanf("%[^\n]%*c", &a);
                
                printf("%s$\n", &a);
                time -= 1;
            }
        }
        else if(n_flag==1){
            int number=1;
            while (time != 0)
            {
                scanf("%[^\n]%*c", &a);
                
                printf("\t%d  %s\n", number,&a);
                number++;
                time -= 1;
            }
        }
        else{
            while (time != 0)
            {
                scanf("%[^\n]%*c", &a);
                
                printf("%s\n", &a);
                time -= 1;
            }
        }
           


            return 1;

        }
    }
    else{
        printf("cat: invalid option --'%c'",c);
        printf("\n");
        return 1;
    }
   
    if(unreg==1){
        printf("cat: unrecognisable option '%s'\n",unreg_value);
        return 1;
   }
    if(file_found_1==1 ){      
    char *buffer = malloc(sizeof(char) * 1024000);
    const char *file = arg1;
    int file_descriptor = open(file, O_RDONLY);
                if (file_descriptor < 0)
                {
                    printf("cat: %s: No such file or directory\n", arg1);
                }
                else
                {
                    read(file_descriptor, buffer, 1024000);
                    int index=0;
                    int number=2;
                    if(n_flag==1 && E_flag==1){
                        printf("1  ");
                        while (buffer[index] != 0)
                        {                         
                            

                            if (buffer[index] == 10)                      
                            {
                                printf("$");
                                printf("%d  ", number);
                                number++;
                                }
                            printf("%c", buffer[index]);
                          index++;
                        }
                    }
                    else if(n_flag==1){
                        printf("1  ");
                        while (buffer[index] != 0)
                        {                           
                            printf("%c", buffer[index]);
                            if (buffer[index] == 10)
                            {                               
                                printf("%d  ", number);
                                number++;
                                }
                            index++;
                        }
                          }
                    else if (E_flag==1){
                     while (buffer[index] != 0)
                        { if (buffer[index] == 10)
                        {                         
                            printf("$");
                        }                      
                        printf("%c", buffer[index]);
                      index++;
                    }
                            }
                  
                   
                    else{
                        while (buffer[index] != 0)
                        {     
                         printf("%c", buffer[index]);         
                      index++;
                    }
                    }
                    close(file_descriptor);
                }
   }
    if(file_found_2==1 ){      
    char *buffer = malloc(sizeof(char) * 1024000);
    const char *file = arg2;
    int file_descriptor = open(file, O_RDONLY);
                if (file_descriptor < 0)
                {
                    printf("cat: %s: No such file or directory\n", arg2);
                }
                else
                {
                    read(file_descriptor, buffer, 1024000);
                    int index=0;
                    int number=2;
                   
                    if(n_flag==1){
                        printf("1  ");
                        while (buffer[index] != 0)
                        {                           
                            printf("%c", buffer[index]);
                            if (buffer[index] == 10)
                            {                               
                                printf("%d  ", number);
                                number++;
                                }
                            index++;
                        }
                          }
                    else if (E_flag==1){
                     while (buffer[index] != 0)
                        { if (buffer[index] == 10)
                        {                         
                            printf("$");
                        }                      
                        printf("%c", buffer[index]);
                      index++;
                    }
                            }
                    
                    
                    else{
                        while (buffer[index] != 0)
                        {     
                         printf("%c", buffer[index]);         
                      index++;
                    }
                    }
                    close(file_descriptor);
                }
   }
 
  
   }




int main(int argc,char *argv[]){
    cat_function(argv[1],argv[2]);
  
    return 0;
}