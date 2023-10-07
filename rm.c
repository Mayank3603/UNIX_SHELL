#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int rm_function(char *arg1,char *arg2){
    if(strcmp(arg1,"hello")==0 && strcmp(arg2,"hello")==0 ){
             printf("rm: missing operand\n");
             return 1;
    }
   if(arg2[0]=='-'  ){
        printf("Assumption: No flags at argument\n");
        return 1;
    }
    if(strcmp(arg1,"-")==0 && strcmp(arg2,"hello")==0){
        int removee=0;      
        removee = remove(arg1);
        if(removee != 0) {    
            printf("rm: cannot remove '%s': No such file or directory\n",arg1);
        }
    }

    int file_found_1=0;
    int v_flag=0;
    int invalid_1=0;
    int unreg=0;
    char c;
    char *unreg_value;
    int f_flag=0;
   
    if(arg1[0]=='-' && strcmp(arg1,"hello")!=0 ){
        for(int i=1;i<strlen(arg1);i++){
            if(arg1[i]!='f'){
                f_flag=0;
                break;
            }
            else{
                f_flag=1;
            }
        }
    }  
    if(arg1[0]=='-' && strcmp(arg1,"hello")!=0 ){   
        if(f_flag==0){
        for(int i=1;i<strlen(arg1);i++){
            
            if(arg1[1]=='-'){
                unreg=1;
                unreg_value=arg1;
                break;              
            }
            else if(arg1[i]!='v' ){
                
                invalid_1=1;
                c=arg1[i];
                break;
            }           
            else{
                v_flag=1;
            }     
        }
    }
    }
    else{
        if(strcmp("hello",arg1)!=0){
             file_found_1 = 1;
        }            
    } 
    if(unreg==1){
        printf("rm: unrecognisable option '%s'\n",unreg_value);
        return 1;
   }
    else if(invalid_1==1 ){
      printf("rm: invalid option --'%c'",c);
      printf("\n");
      return 1;
    }

  
  if(file_found_1==1){   
    int removee=0;      
    removee = remove(arg1);
    if(removee != 0) {
      printf("rm: cannot remove '%s': No such file or directory\n",arg1);
    }
    if(strcmp(arg2,"hello")!=0){
        int removee=0;      
        removee = remove(arg2);
        if(removee != 0) {
        printf("rm: cannot remove '%s': No such file or directory\n",arg2);
        }
    }
    return 1;
   
}
    if(f_flag==1){
     if(strcmp(arg2,"hello")!=0){
        int removee=0;      
        removee = remove(arg2);
    }
    else{
        printf("rm: missing operand\n"); 
    }
    return 1;          
    }
    if(v_flag==1){
        if(strcmp("hello",arg2)==0){
            printf("rm: missing operand\n");        
        }
        else{
            int removee=0;      
            removee = remove(arg2);
            if(removee == 0) {
                printf("removed '%s'\n",arg2);
                }
            else {
                printf("rm: cannot remove '%s': No such file or directory\n",arg2);
            }
        }       
    }  
    return 1;
}
int main(int argc,char *argv []){
      
        rm_function(argv[1],argv[2]);

    return 0;
}