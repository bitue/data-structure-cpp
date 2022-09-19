#include<stdio.h>
#include<string.h>
int top=-1;  // init the top value -1 GLOBALLY 
char Stack[4]={'\0'}; // initialize an array with a default value null char GLOBALLY 

void Push(char x){
  	Stack[++top]=x; // top value is 0 Stack[0] = 'S' => top value is 1 and Stack[1]='E'
  	return;
}
char Pop(void){
   return Stack[top--]; // top value 

}
int main()
{
  char Str1[4]={'\0'}; // Str1 is a char array with a default value null char 
    char Str2[4]={'\0'}; // Str1 is a char array with a default value null char 
    int i; // initialize i var
    strcpy(Str1, "CSE"); // "CSE" value is copy at Str1
    for(i=0; i<3; ++i){
        cout<<i<<"i push "<<endl;
       Push(Str1[i]); // push fun return void get parameter as a char and push it to global STACK char array 
    }
    for(i=0; i<3; ++i){
        Str2[i]=Pop(); // 
    }
    printf("%s", Str2);
    
}
 

