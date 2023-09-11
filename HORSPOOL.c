#include<stdio.h>
#include<string.h>
#define MAX_STRING_LENGTH 100
#define MAX_PATTERN_LENGTH 25
int shiftTable[256];
void shiftTableInit(char *pattern){
    int m= strlen(pattern);
    for(int i=0;i<256;i++){
        shiftTable[i]=m;
    }
    for(int i=0;i<m-1;i++){
        shiftTable[pattern[i]]=m-1-i;
    }
}
int horspool(char *text, char *pattern){
    int n= strlen(text);
    int m= strlen(pattern);
    int i=m-1;
    while(i<n){
        int k=0;
        while(k<m && pattern[m-1-k]==text[i-k]){
            k++;
        }
        if(k==m){
            return i-m+1; //position of string
        }
        else{
            i+=shiftTable[text[i]];
        }
        
    }
    return -1;

}
void main(){
    char text[MAX_STRING_LENGTH];
    char pattern[MAX_PATTERN_LENGTH];
    printf("Enter text:\t");
    scanf("%s",text);
    printf("\nEnter pattern:\t");
    scanf("%s",pattern);
    shiftTableInit(pattern);
    int pos= horspool(text,pattern);
     if (pos == -1) {
        printf("The given string is not found in the original string.\n");
    } else {
        printf("The search string is found at position %d in the original string.\n", pos);
    }


}