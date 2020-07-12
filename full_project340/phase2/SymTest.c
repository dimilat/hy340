#include "SymTable.h"

int main(){

    int i;
    symrec_t* orizontia;
    symrec_t* katheta;
    myHashTable = newHashTable();
    
    insert(1, 10, GLOBAL, "MANOS1");
    insert(2, 10, GLOBAL, "MANOS2");
    insert(3, 10, GLOBAL, "MANOS3");
    insert(4, 10, GLOBAL, "MANOS4");
    insert(5, 10, GLOBAL, "MANOS5");
    

    

  
    orizontia = scope_Head;
    katheta = scope_Head;
    printf("\n===HASHLIST PRINT:\n");
    while(orizontia != NULL){
        printf("\n===NEW SCOPE: \n");
        katheta = orizontia;
        while(katheta->next_scope != NULL){
            printf(" %s ",katheta->next_scope->name);
            katheta->next_scope = katheta->next_scope->next_scope;
        }
        orizontia = orizontia->next_link;
    }
    
    printf("\n===HASHTABLE PRINT:\n");
    for(i = 0; i < HASH_SIZE; i++){
        printf(" ");
        while(myHashTable->hashTable[i] != NULL){
            printf("SCOPE%s ",myHashTable->hashTable[i]->name);
            myHashTable->hashTable[i] = myHashTable->hashTable[i]->next_link;
        }
    }



    return 0;
}