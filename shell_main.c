#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wordexp.h>
#include <sys/syscall.h>
#include <pthread.h> 
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char buff[256];
int cd_function(char **argument);
int pwd_function(char ** argument);
int echo_function(char ** argument);


char* reading_from_stdin(void)
{   
    size_t len = 0;
    char *returning_line = NULL;
    size_t line_size=0;
    line_size=getline(&returning_line, &len, stdin)+1;
    int value=feof(stdin);

    if (line_size==0){
        
        if (value!=0) {

            exit(EXIT_SUCCESS);  
    } 
    else  {
      printf("READLINE ERROR");
      exit(EXIT_FAILURE);
    }
  }

  return returning_line;
}


char **splitting_arguments(char *read_line)
{ int value1=0;
  int value2=0;
  int value3=0;
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  value1++;
  token = strtok(read_line, LSH_TOK_DELIM);
  while (token != NULL) {
    
    tokens[position] = token;
    position++;
    value1++;

   
    token = strtok(NULL, LSH_TOK_DELIM);
   
  }
  tokens[position] = NULL;
  value1++;
  value2++;
  return tokens;
}

int echo_function(char** argument){

      int index=1;
        while(argument[index]!=NULL){
          index++; 
        }
      int count=index-1;
      if(argument[1]==NULL){
        printf("\n");
      }  


      else if(strcmp(argument[1],"-E")==0){
        int index=2;
        
        if(count==1){
          printf("\n");
        }
        else if(count==2){
          char *a = argument[2];
          int len=strlen(a);
    
          if(a[0]=='"'  && a[len-1]=='"'){
            for(int i=1;i<len-1;i++){
              printf("%c",a[i]);
            }
            printf("\n");
          }
          else if(a[0]=='"'  && a[len-1]!='"'){
            printf("The given command is missing \" at the end" );
            printf("\n");
           
          }
          else{
            for(int i=0;i<len;i++){
              printf("%c",a[i]);
            }
            printf("\n");
          }
        }
        else{
          char *a1 = argument[2];
          int len1=strlen(a1);

          char *a2 =argument[count];
          int len2=strlen(a2);
          
          if(a1[0]=='"' && a2[len2-1]=='"'){
            for(int i=1;i<len1;i++){
              printf("%c",a1[i]);
              
            }
            printf(" ");
            int index=3;
            while(argument[index+1]!=NULL){
          
              printf("%s",argument[index]);
              printf(" ");
              index++;
           }
            for(int i=0;i<len2-1;i++){
              printf("%c",a2[i]);
            }
            printf("\n");
          }
          else if(a1[0]=='"' && a2[len2-1]!='"'){
            printf("The given command is missing \" at the end" );
            printf("\n");
          }
          else{
            int index=2;
            while(argument[index]!=NULL){
          
              printf("%s",argument[index]);
              printf(" ");
              index++;
           }
           printf("\n");
          }       
        }
            
      }

      else if(strcmp(argument[1],"-e")==0){
        int index=2;
        while(argument[index]!=NULL){
          char *a= argument[index];
          for(int j=0;j<strlen(a);j++){
            if(a[j]=='"'){
              continue;
            }
            if(j!=strlen(a) ){
             
                    if (a[j] == 92 && a[j+1] == 'n')
                    {
                        printf("\n");
                        j++;
                    }
                     else if (a[j] == 92 && a[j+1] == 't')
                    {
                        printf("\t");
                        j++;
                    }
                    else if (a[j] == 92 && a[j+1] == 'a')
                    {
                        printf("\a");
                        j++;
                    }
                    else if (a[j] == 92 && a[j+1] == 92)
                    {
                        printf("\\");
                        j++;
                    }
                  
                     else if (a[j] == 92 && a[j+1] == 'r')
                    {
                        printf("\r");
                        j++;
                    }
                          
                       
                    else{
                        printf("%c",a[j]);
                    }
            }
          else{
             printf("%c",a[j]);
          }
            
          }
          index++;
          
        }
        printf("\n");
      }


      else if(strcmp(argument[1],"-n")==0){
        int index=2;
        
        if(count==1){
    
        }
        else if(count==2){
          char *a = argument[2];
          int len=strlen(a);
    
          if(a[0]=='"'  && a[len-1]=='"'){
            for(int i=1;i<len-1;i++){
              printf("%c",a[i]);
            }
            
          }
          else if(a[0]=='"'  && a[len-1]!='"'){
            printf("The given command is missing \" at the end" );
            printf("\n");
          }
          else{
            for(int i=0;i<len;i++){
              printf("%c",a[i]);
            }
           
          }
        }
        else{
          char *a1 = argument[2];
          int len1=strlen(a1);

          char *a2 =argument[count];
          int len2=strlen(a2);
          
          if(a1[0]=='"' && a2[len2-1]=='"'){
            for(int i=1;i<len1;i++){
              printf("%c",a1[i]);
              
            }
            printf(" ");
            int index=3;
            while(argument[index+1]!=NULL){
          
              printf("%s",argument[index]);
              printf(" ");
              index++;
           }
            for(int i=0;i<len2-1;i++){
              printf("%c",a2[i]);
            }
           
          }
          else if(a1[0]=='"' && a2[len2-1]!='"'){
            printf("The given command is missing \" at the end" );
            printf("\n");
          }
          else{
            int index=2;
            while(argument[index]!=NULL){
          
              printf("%s",argument[index]);
              printf(" ");
              index++;
           }
          
          }       
        }
                 
      }



      else{
        int index=1;
        
        if(count==0){
          printf("\n");
        }
        else if(count==1){
          char *a = argument[1];
          int len=strlen(a);
    
          if(a[0]=='"'  && a[len-1]=='"'){
            for(int i=1;i<len-1;i++){
              printf("%c",a[i]);
            }
            printf("\n");
          }
          else if(a[0]=='"'  && a[len-1]!='"'){
            printf("The given command is missing \" at the end" );
            printf("\n");
          }
          else{
            for(int i=0;i<len;i++){
              printf("%c",a[i]);
            }
            printf("\n");
          }
        }
        else{
          char *a1 = argument[1];
          int len1=strlen(a1);

          char *a2 =argument[count];
          int len2=strlen(a2);
          
          if(a1[0]=='"' && a2[len2-1]=='"'){
            for(int i=1;i<len1;i++){
              printf("%c",a1[i]);
              
            }
            printf(" ");
            int index=2;
            while(argument[index+1]!=NULL){
          
              printf("%s",argument[index]);
              printf(" ");
              index++;
           }
            for(int i=0;i<len2-1;i++){
              printf("%c",a2[i]);
            }
            printf("\n");
          }
          else if(a1[0]=='"' && a2[len2-1]!='"'){
            printf("The given command is missing \" at the end" );
            printf("\n");
          }
          else{
            int index=1;
            while(argument[index]!=NULL){
          
              printf("%s",argument[index]);
              printf(" ");
              index++;
           }
           printf("\n");
          }       
        }
      }
      return 1;
}

int pwd_function(char** argument){
    
   
    int found=0;
    int invalid=0;
    char * arg=argument[1];
    char c;
    if(argument[1]==NULL){
       printf("%s\n",buff);
       return 1;
    }

    if(arg[0]=='-'){
      for(int i=1;i<strlen(arg);i++){
        if(arg[i]!='L' && arg[i]!='P'){     
            c=arg[i];         
            invalid=1;        
            break;

                }
        else if(arg[i]=='L'){      
            found=1;
                }
        else if(arg[i]=='P'){          
            found=1;
                }
            
      }

  }
  if(invalid==1){
    printf("bash: pwd: -%c: invalid option\n",c);
    
  }
  else{
      printf("%s\n",buff);
  }

    return 1;
}
int cd_function(char **argument)
{  
  int count=0;
  int index=1;
  int found=0;
  int invalid=0;
  char * arg=argument[1];
  char c;
  if(argument[1]==NULL || strcmp(argument[1],"~")==0){
    chdir("/home/mayank");
    getcwd(buff,256);
    return 1;
  }
  
  
  if(arg[0]=='-'){
  for(int i=1;i<strlen(arg);i++){
    if(arg[i]!='L' && arg[i]!='P'){     
        c=arg[i];         
        invalid=1;        
        break;

            }
    else if(arg[i]=='L'){      
        found=1;
            }
    else if(arg[i]=='P'){          
        found=1;
            }
        
  }
  }
  while(argument[index]!=NULL){
    index++;
  }
  count=index-1;
 
  if(invalid==1){
    printf("-bash: cd: -%c: invalid option\n",c);
    return 1;
  }
  if(count>2 || (count>1 && found==0)){
    printf("-bash: cd: too many arguments\n");
    return 1;
  }
  if(count==1 && found==1 && invalid==0){
    chdir("/home/mayank");
    getcwd(buff,256);
    return 1;
  }
  
  if(count==2 && found==1 && invalid==0){
    if(chdir(argument[2])!=0){
      printf("-bash: cd: %s: No such file or directory\n",argument[2]);
    }
    else{
      getcwd(buff,256);
    } 

  }
  
  else if(count==1 && invalid==0){
    if(chdir(argument[1])!=0){
      printf("-bash: cd: %s: No such file or diretory\n",argument[1]);
    }
    else{
      getcwd(buff,256);
    } 

  }
  return 1;
}
int external_command(char ** argument,char * path){
  
  pid_t pid;
  pid_t wpid;
  int status;
  int value1=0;
  int value2=-0;
  int value3=0;
  
  
  pid=fork();
  if(pid==0){
    int index=0;
    value1++;
  
    while(argument[index]!=NULL){
      index++;
    }
    argument[index]="hello";
    argument[index+1]="hello";
    argument[index+2]="hello";
    argument[index+3]="hello";
    argument[index+4]="hello";
    int len=execl(path,argument[0],argument[1],argument[2],argument[3],NULL)+1;
    value2++;
    
    if( len==0){
      printf("Your process is not being exected\n");
    }
    exit(EXIT_FAILURE);
  }
  if(pid<0){
    printf("Error in forking!\n");
    return 1;
  }
  else if(pid>0){
       do {
        value1++;
       
      
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  value1--;
  
  return 1;

}
void * thread_command(void * argument){
  int value1=0;
 
 
  char ** arg1=argument;
  char * a =malloc(sizeof(char)*512);
  strcat(a,"/home/mayank/OsAssignment/");
  int i=0;
  while(strcmp(arg1[i],"&t")!=0){
    strcat(a,arg1[i]);
    value1--;
   
    strcat(a," ");
    i++;
  }
  for(int i=0;i<4;i++){
  
    strcat(a,"hello");
    strcat(a," ");
  
  }
  value1=0;

  system(a);

  pthread_exit(NULL);
  return NULL;

}
int executing_command(char **argument)
{
    
    if (argument[0] == NULL) {
        return 1;
     } 
    int index=0;
    while(argument[index]!=NULL){
        index++;
    }
    if(strcmp("cd",argument[0])==0){
      cd_function(argument);
    }
    else if(strcmp("pwd",argument[0])==0){
      pwd_function(argument);
    }
    else if(strcmp("echo",argument[0])==0){
      echo_function(argument);
    }
    
    else if(strcmp(argument[index-1],"&t")==0){
        pthread_t threaddd;
        int value;
        value=pthread_create(&threaddd,NULL,&thread_command,argument);
        pthread_join(threaddd,NULL); 
    }
    else{
        if(strcmp("ls",argument[0])==0){
      external_command(argument,"/home/mayank/OsAssignment/ls");
        }
         else if (strcmp("mkdir",argument[0])==0){
          
          external_command(argument,"/home/mayank/OsAssignment/mkdir");
        }
        else if (strcmp("cat",argument[0])==0){
        
          external_command(argument,"/home/mayank/OsAssignment/cat");
        }
        else if (strcmp("date",argument[0])==0){
          external_command(argument,"/home/mayank/OsAssignment/date");
        }
        else if (strcmp("rm",argument[0])==0){
          external_command(argument,"/home/mayank/OsAssignment/rm");
        }  
       
        
        else{
          printf("-bash: %s: command not found\n", argument[0]);
        }
    }
    
    
    return 1;
}

int main()
{
  char * executable_line;
  char ** splitted_arguments;
  int status=1;
  getcwd(buff,256); 
  while (status){
    printf("\e[0;34m""[mayank@artix %s❯]""\e[0;31m",buff);
    executable_line = reading_from_stdin();
    splitted_arguments = splitting_arguments(executable_line);
    status = executing_command(splitted_arguments);
    free(executable_line);
    free(splitted_arguments);
  } 
  return 0;
}



