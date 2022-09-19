#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
int top=-1;
char Stack[4]={'\0'};

void Push(char x){
   
  	Stack[++top]=x; // top value we get 0 1 2 

    // because of that we store C in 0 pos S in 1 pos and E in 2 pos 
   // printf("top value %d \n", top);
  	return;
}
char Pop(void){

   return Stack[top--];
}

int main() {

 char Str1[4]={'\0'};
    char Str2[4]={'\0'};
    int i;
    strcpy(Str1, "CSE");
    for(i=0; i<3; ++i){
       //  i = 0 , 1 , 2 and got the value C S E ;
       // 
        
        Push(Str1[i]);
    }
    for(i=0; i<3; ++i){
      
       Str2[i]=Pop();
        printf("%d top ka value \n", top);
    }
    printf("%s", Str2);
    return 0;
}
 

// void Push(char x){
//   	Stack[++top]=x;
//   	return;
// }
// char Pop(void){
//    return Stack[top--];
// }