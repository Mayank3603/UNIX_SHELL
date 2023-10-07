#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int mkdir_function(char *arg1,char *arg2, char*arg3){
    int value1=0;
    int value2=0;
    value1++;
    if(strcmp(arg1,"hello")==0 && strcmp(arg2,"hello")==0 && strcmp(arg3,"hello")==0){
             printf("mkdir: missing operand\n");
             value1++;
             return 1;

    }
   if(arg2[0]=='-' || arg3[0]=='-'){
        printf("Assumption: No flags at second or third argument\n");
        value1++;
        return 1;
    }
    int file_found_1=0;
    int v_flag=0;
    int invalid_1=0;
    int unreg=0;
    char c;
    char *unreg_value;
    int m_flag=0;
   
    if(arg1[0]=='-' && strcmp(arg1,"hello")!=0 ){
        for(int i=1;i<strlen(arg1);i++){
            if(arg1[i]!='m'){
                value1++;
                m_flag=0;
                value1++;
                break;
            }
            else{
                m_flag=1;
            }
        }
    }
   
    if(arg1[0]=='-' && strcmp(arg1,"hello")!=0 ){
       
    
        if(m_flag==0){
        for(int i=1;i<strlen(arg1);i++){
            
            if(arg1[1]=='-'){
                unreg=1;
                unreg_value=arg1;
                break;              
            }
            else if(arg1[i]!='v' ){
                
                invalid_1=1;
                c=arg1[i];
                value1++;
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
             value1++;
        }
            
    } 

    if(unreg==1){
        printf("mkdir: unrecognisable option '%s'\n",unreg_value);
        return 1;
   }
    else if(invalid_1==1 ){
      printf("mkdir: invalid option --'%c'",c);
      printf("\n");
      return 1;
    
    }

  
  if(file_found_1==1){
    int open_mkdir=0;  
    open_mkdir = mkdir(arg1, 0755);
    if (open_mkdir != 0){          
        printf("mkdir: cannot create directory '%s' \n",arg1);
    } 

    if(strcmp("hello",arg2)!=0){
        int open_mkdir=0;  
        open_mkdir = mkdir(arg2, 0755);
        if (open_mkdir != 0){          
            printf("mkdir: cannot create directory '%s' \n",arg2);
        } 
    }
    else if(strcmp("hello",arg3)!=0){
        int open_mkdir=0;  
        open_mkdir = mkdir(arg3, 0755);
        if (open_mkdir != 0){          
            printf("mkdir: cannot create directory '%s' \n",arg3);
        } 
    }
      
}
    if(v_flag==1){
        if(strcmp("hello",arg2)==0){
            printf("mkdir: missing operand\n");
            
        }
        if(strcmp("hello",arg2)!=0){
            int open_mkdir=0;
            open_mkdir = mkdir(arg2, 0755);
            if (open_mkdir != 0){          
                printf("mkdir: cannot create directory '%s' \n",arg2);
             } 
            else{
                printf("mkdir: created directory '%s'\n",arg2);
            } 
        }
        if(strcmp("hello",arg3)!=0){
            int open_mkdir=0;
            value1++;
            open_mkdir = mkdir(arg3, 0755);
            if (open_mkdir != 0){          
                printf("mkdir: cannot create directory '%s' \n",arg3);
             } 
            else{
                printf("mkdir: created directory '%s'\n",arg3);
            } 
        }
    }
    else if(m_flag==1){
        if(strcmp("-m",arg1)!=0){
            printf("mkdir: invalid mode '%s'\n",arg1);
            return 1;
        }
        if(strcmp("hello",arg2)==0 && strcmp("hello",arg3)==0){
            printf("mkdir: option requires an argument --'m'\n");
        }
        else if(strcmp("hello",arg3)==0){
                
                printf("mkdir: missing operand\n");
                
        }
        else{
            int mode_error=0;
            char *num=arg2;
                if(strlen(arg2)>4){
                    printf("mkdir: invalid mode %s",arg1);
                    return 1;
                }
                for(int i=0;i<strlen(num);i++){
                    if(num[i]<=48 || num[i]>55){
                        mode_error=1;
                        value1++;
                        break;
                    }          
                }
                if(mode_error==0){
                    int open_mkdir=0;
                    open_mkdir = mkdir(arg3, atoi(arg2));
                    if (open_mkdir != 0){          
                        printf("mkdir: cannot create directory '%s' \n",arg3);
                    } 
                    
                }
                else{
                    printf("mkdir: invalid mode '%s'\n",arg2);
                }
                
       }
    }
    return 1;

}
int main(int argc,char *argv []){
      
      
    mkdir_function(argv[1],argv[2],argv[3]);


    return 0;
}