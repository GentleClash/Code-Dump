#include <stdio.h>
#include<stdlib.h>
//Open addressing( Quadratic Probing ), with c1=1 and c2=2. We'll use p and q for c1 and c2.
//1) Number of slots
//2) Default keys = -1
//2) Take input
//3) Store in [(input%slots+i+i^2)%slots]
//4) Display



//Remainder when x/y
int _remainder(int x, int y){
    int quiotent = x/y;
    int remainder = (x - quiotent*y);
    return remainder;
}



int main(){
    int slots, key, index;
    int p = 1, q = 2;       //Change as per need
    //Number if slots
    printf("Enter the size of hash table: ");
    scanf("%d", &slots);
    
    //Take input
    int hash[slots];
    //Set Default to -1
    for(int i = 0; i<slots; i++){
        hash[i] = -1;
    }
    
    
    
    printf("Enter elements: (Enter 'end' when want to stop entering)\n");
    for(int i = 0; i<slots; i++){
        int j = 1;
        if(scanf("%d", &key)!=1){break;};
        //Generate Index
        index = _remainder((_remainder(key, slots)), slots);
        if(hash[index]==-1){
            hash[index] = key;
            printf("%d goes to index %d\n", key, index);
        }else{
            while( hash[index]!=-1){
                printf("%d index full\n", index);
                index = _remainder((_remainder(key, slots)+(p*j)+(q*(j*j))), slots);
                printf("Moving %d to %d index\n", key, index);
                j++;
            }
            hash[index] = key;
        }
        
    }
    
    
    //Display hash table
    
    printf("Hash table is:\n");
    for(int i = 0; i<slots; i++){
        printf("hash[%d] = %d\n", i, hash[i]);
    }
    
    printf("Success\n");    
    return 0;    
    
        
}
