#include<stdio.h>
#include<string.h>

#define SUCCESS 1
#define FAILED 0
int E(),Edash(),T(),Tdash(),F();
const char *cursur;
char string[64];
int main()
{
 puts("\n Enter the string");
 sscanf("i+(i+i)*i","%s",string);
 cursur=string;
 puts("");
 puts("input       action");
 puts("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
 
 
    if(E() && *cursur =="\0")
    {
      puts("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
      puts("String is succesfully parsed");
      return 0;
    }
    else{
    puts("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
      puts("Error in parsing the string");
      return 1;
    }
 
}
int E()
{
  printf("%-16s E-> T E'\n",cursur);
  if(T())
  {
   if(Edash())
      return SUCCESS;
   else
      return FAILED;
  }
  else{
  return FAILED;
  }
}
int Edash()
{
  if(*cursur == '+')
  {
   printf("%-16s E'-> + T E'\n",cursur);
   cursur++;
   if(T())
   {
     if(Edash())
         return SUCCESS;
     else
         return FAILED;
   }
   else
      return FAILED;
  }
  else{
    printf("%-16s E'-> $\n",cursur);
    return SUCCESS;
  }
}

int T()
{
  printf("%-16s T-> F T'\n",cursur);
  if(F())
  {
    if(Tdash())
       return SUCCESS;
    else
       return FAILED;
  }
  else 
     return FAILED;
}

int Tdash()
{
  if(*cursur == '*')
  {
   printf("%-16s T'-> * F T'\n",cursur);
   cursur++;
   if(F())
   {
     if(Tdash())
        return SUCCESS;
     else
        return FAILED;
   }
   else
      return FAILED;
  }
  else
  {
    printf("%-16s T'-> $\n",cursur);
    return SUCCESS;
  }
}

int F()
{
  if(*cursur == '(')
  {
    printf("%-16s F->(E)\n",cursur);
    cursur++;
    if(E())
    {
      if(*cursur == ')'){
      cursur++;
      return SUCCESS;
      }
      else
         return FAILED;
    }
    else
       return FAILED;
  }
  else if(*cursur == 'i'){
    cursur++;
    printf("%-16s F->i\n",cursur);
    return SUCCESS;
  }
  else 
     return FAILED;
}
