#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>



int ls_function(char *arg1,char *arg2){
  
    
    if((strcmp("hello",arg1))!=0 && strcmp("hello",arg2)!=0 && arg1[0]!='-' && arg2[0]!='-'  ){
        printf("ls: cannot access '%s': No such file or directory\n",arg1);
        printf("ls: cannot access '%s': No such file or directory\n",arg1);
        return 1;
    }
    int postion_1 =0;
    int postion_2 =0;
    int m_found=0;
    int a_found=0;
    int invalid_1=0;
    int invalid_2=0;
    
    if(arg1[0]=='-' && strcmp(arg1,"hello")!=0){
        
        for(int i=1;i<strlen(arg1);i++){
            if(arg1[i]!='a' && arg1[i]!='m'){
                
                invalid_1=1;
            
                break;
            }
            else if(arg1[i]=='a'){
            
                a_found=1;


            }
            else if(arg1[i]=='m'){
                
                m_found=1;
            }
        }
    }
    else{
        if(strcmp("hello",arg1)!=0){
             postion_1 = 1;
        }
            
       
        
    }
    if(arg2[0]=='-' && strcmp(arg2,"hello")!=0){

        for(int i=1;i<strlen(arg2);i++){
            if(arg2[i]!='a' && arg2[i]!='m'){
                invalid_2=1;    
                break;
            }
            else if(arg2[i]=='a'){
                a_found=1;

            }
            else if(arg2[i]=='m'){
                m_found=1;
            }
        }
    }
    else{
       if(strcmp("hello",arg2)!=0){
             postion_2 = 1;
        }
        
        
    }
    
   
    if(strcmp(arg1,"hello")==0 && strcmp(arg2,"hello")==0){  
        DIR *dir=opendir(".");
        if(!dir){
            perror("This directory cannot be opened\n");
        return 1;
        }   
        struct dirent *direntt;
        while((direntt=readdir(dir))!=NULL){
            if(direntt->d_name[0]!='.'){
                printf("%s\t",direntt->d_name);             
            }
                 
        }
        printf("\n");
        return 1;
    }

    else if(postion_1==1  && invalid_2==0 ){
        if(strcmp("hello",arg2)==0){
          
            DIR *dir=opendir(arg1);
            if(!dir){
                printf("ls: cannot access '%s': No such file or directory\n",arg1);
                
            }   
            struct dirent *direntt;
            while((direntt=readdir(dir))!=NULL){
                if(direntt->d_name[0]!='.'){
                    printf("%s\t",direntt->d_name);             
                }
                    
            }
        }
        else if(a_found==1 && m_found==1){
            DIR *dir=opendir(arg1);
            if(!dir){
                printf("ls: cannot access '%s': No such file or directory",arg1);
                printf("\n");
                return 1;
            }
            struct dirent *direntt;
            while((direntt=readdir(dir))!=NULL){
                printf("%s,",direntt->d_name);  
                printf(" ");       
            }
        }
        else if(a_found==1){
            DIR *dir=opendir(arg1);
            if(!dir){
                printf("ls: cannot access '%s': No such file or directory",arg1);
                printf("\n");
                return 1;
            }
            struct dirent *direntt;
        
            while((direntt=readdir(dir))!=NULL){
           
                printf("%s\t",direntt->d_name);   
            
             
            }
        }
        else if(m_found==1){
            DIR *dir=opendir(arg1);
            if(!dir){
                printf("ls: cannot access '%s': No such file or directory",arg1);
                printf("\n");
                return 1;
            }
            struct dirent *direntt;
        
            while((direntt=readdir(dir))!=NULL){
                if(direntt->d_name[0]=='.'){
                    continue;
                }
                else{
                    printf("%s,",direntt->d_name); 
                    printf(" ");
        
                }
                
            }
        }
        else{
            printf("ls: cannot access '%s': No such file or directory",arg1);
        }
        printf("\n");
        
             
    }
       else if(postion_2==1  && invalid_1==0 ){
       
         if(a_found==1 && m_found==1){
            DIR *dir=opendir(arg2);
            if(!dir){
                printf("ls: cannot access '%s': No such file or directory",arg2);
                printf("\n");
                return 1;
            }
            struct dirent *direntt;
            while((direntt=readdir(dir))!=NULL){
                printf("%s,",direntt->d_name);  
                printf(" ");       
            }
        }
        else if(a_found==1){
            DIR *dir=opendir(arg2);
            if(!dir){
                printf("ls: cannot access '%s': No such file or directory",arg2);
                printf("\n");
                return 1;
            }
            struct dirent *direntt;
        
            while((direntt=readdir(dir))!=NULL){
           
                printf("%s\t",direntt->d_name);   
            
             
            }
        }
        else if(m_found==1){
            DIR *dir=opendir(arg2);
            if(!dir){
                printf("ls: cannot access '%s': No such file or directory",arg2);
                printf("\n");
                return 1;
            }
            struct dirent *direntt;
        
            while((direntt=readdir(dir))!=NULL){
                if(direntt->d_name[0]=='.'){
                    continue;
                }
                else{
                    printf("%s,",direntt->d_name); 
                    printf(" ");
        
                }
                
            }
        }
        else{
            printf("ls: cannot access '%s': No such file or directory",arg2);
        }
        printf("\n");
        
             
    }

    else if(a_found==1 && m_found==1 && invalid_1==0 && invalid_2==0 && postion_1==0 && postion_2==0){
        DIR *dir=opendir(".");
        if(!dir){
            perror("This directory cannot be opened\n");
        return 1;
        }   
        struct dirent *direntt;
        
        while((direntt=readdir(dir))!=NULL){
                printf("%s,",direntt->d_name);  
                printf(" ");       
        }
        printf("\n");
    }
    else if(a_found==1 && invalid_2==0 && invalid_1==0 && postion_1==0 && postion_2==0){
        DIR *dir=opendir(".");
        if(!dir){
            perror("This directory cannot be opened\n");
        return 1;
        }   
        
        struct dirent *direntt;
        
        while((direntt=readdir(dir))!=NULL){
           
                printf("%s\t",direntt->d_name);   
            
            
        }
        printf("\n");
    }
    else if(m_found==1 && invalid_1==0&& invalid_2==0 && postion_1==0 && postion_2==0){
        DIR *dir=opendir(".");
        if(!dir){
            perror("This directory cannot be opened\n");
        return 1;
        }   
        struct dirent *direntt;
        
        while((direntt=readdir(dir))!=NULL){
            if(direntt->d_name[0]=='.'){
                continue;
            }
            else{
                printf("%s,",direntt->d_name); 
                printf(" ");
    
            }
             
        }
        printf("\n");
    }
    
    else if(invalid_1==1 || invalid_2==1 || postion_1==0 || postion_2==0 ){
       printf("Invalid flag\n");
    }


    
    return 1;
    

}
int main(int argc,char *argv []){
      
  
        ls_function(argv[1],argv[2]);
        
    

    return 0;
}