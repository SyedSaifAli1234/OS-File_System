#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define col 128 
#define row 10

int main(void) {

    //char c;
    char blocks[10];
    char block_size[10];
    int r;
    int c;
    
	
    	printf("\nPlease enter the number of blocks your Virtual Hard disk: ");
        scanf("%[^\n]%*c", blocks);
        printf("The number of blocks are = %s\n", blocks);

        printf("\nPlease enter the Block size of your Virtual Hard disk: ");
        scanf("%[^\n]%*c", block_size);        
        printf("Size of each block is = %s\n", block_size);

        r = (*blocks) - '0';
        c = (*block_size) - '0';

        printf("r = %d\n", r);
        printf("c = %d\n", c);

        char HD[(*blocks) -'0'][(*block_size) -'0'];

        for(int i=0; i < (*blocks -'0'); i++){
            for(int j=0; j < (*block_size -'0'); j++){
                HD[(*blocks) -'0'][(*block_size)-'0'] = '0';
            }
        }
        for(int i=0; i < (*blocks -'0'); i++){
            for(int j=0; j < (*block_size -'0'); j++){
                printf("%c\n", HD[(*blocks) -'0'][(*block_size)-'0']);
            }
        }


        printf("\n1. ls ");
        printf("\n2. rm ");
        printf("\n3. mkdir ");
        printf("\n4. cd ");
        printf("\n5. import ");
        
        

    printf("\n");
    return 0;
}