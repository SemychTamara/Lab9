#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (void)
{
    char text[255];
    int d, num=0, max=0, count=0, space_count=0,id;
    int i=0;
    FILE* F1 = fopen("F1.txt", "r");
    FILE* F2 = fopen("F2.txt", "w");
    
        if(F1==NULL||F2==NULL){
            printf("ERROR!\n");
            return 1;
        }
        
      while(!feof(F1)) 
        { 
 
 
            fgets(text,sizeof(text),F1); 
            
             d = strlen(text); 
              
                for(int i = 0; i<d;i++) 
 
                {                    
                 if(text[i]== ' ')
                 num++;
                 
                 if(text[i]=='\n'){
                    if (num>=1){
                   fputs(text, F2);
                 }
                 num=0;
                 }
                                
                }
                                       
for (i=0; i<d; i++){
if (text[i] != ' ') 
count += 1;
        else {
            if (count > max) {
                max = count;
                id = i - count;
            }
            count = 0;
        }
    
    }
    for(i=0;i<id;i++){
        if(text[i]==' ')
        space_count++;
    }
    
}
printf("%d\n", space_count+1);
        fclose(F1);
        fclose(F2);
        return 0;
}
