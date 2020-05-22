#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define col 128 
#define row 10 

int main(void) {

    char line[row][col];
	char fname[20];
	char name[20];
    char name2[20];
	char temp[20];
    char c;
    char add;
    char block_add;
    char new_block_add;
    FILE *fptr = NULL; 
    int i = 0;
    int tot = 0;
    int j;
  	int Num_of_files;
    int check = 0;
    int length = 0;
    int first_block = 8;
    int blocks;
    int counter;

		

    fptr = fopen("file.txt", "r");
    while(fgets(line[i], col, fptr)) 
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;

    Num_of_files = *line[3] - '0';
    //printf("Num_of_files = %d\n", Num_of_files);

    // for(int i=0; i<18; i++){                                //Use this to check the array
    //             printf("%s\n", line[i]);
    // }

    while(1){
    	printf("\nChoose an option\n");
    	printf("1. Size of a file\n");
    	printf("2. Delete a file\n");
    	printf("3. Show freespace in the disk\n");
        printf("4. Exit\n");

    	printf("Input: ");
    	c = getchar();

    	if(c == '1'){
    		printf("Please enter the name of the file: ");
    		scanf("%s", name);
    		//printf("\nThe file name entered by you is %s\n", name);
            int n = 0;
    		
            while(name[n]!=NULL){
    			n++;
    		}
    		
            name[n]='\0'; 
            n=0; 		
            //printf("FileName = %s\n\n", name);

    		for(int k=4; k < (4+Num_of_files); k++){
    			for (int m = 0; name[m]!='\0'; m++){
                    if(line[k][m] == name[m]){
                        length++;
                    }
                    else{
                        //printf("No match\n");
                        check = 1;
                        break;
                    }
    			}
                if(check == 0){

                    //printf("\nMatched at Line %d\n", k);
                    //printf("Length = %d\n", length);
                    add = (line[k][length+1]);///////////////////////////////////////
                    if(add == NULL){
                        printf("The file does not exist\n");
                        break;
                    }
                    //printf("Starting address = %c\n", add);

                    block_add = line[first_block + (add-'0')][0];
                    
                    while(1){
                        if(block_add == '-'){
                            if(line[first_block + (add-'0')][1] == '1'){
                                //printf("No space allocated\n");
                                break;
                            }
                            else{
                                //printf("The space allocated is 32 bytes\n");
                                break;
                            }
                        }
                        else{
                            blocks++;
                            block_add = line[first_block + (block_add-'0')][0];
                            //printf("Number at block = %c\n", block_add);
                        }
                    }
                    
                    printf("\n\n\n=====The total space allocated for %s is %d bytes=====\n\n\n", name, (blocks*32));
                    blocks = 0;
                    break;

                }
                else{
                    //printf("Moving to the next line\n");
                    check = 0;
                    length = 0;
                }
    		}
        }



    	else if(c == '2'){
    		printf("Please enter the name of the file you want to delete: ");
            scanf("%s", name2);
            int n = 0;
            
            while(name2[n]!=NULL){
                n++;
            }
            
            name2[n]='\0'; 
            n=0;

            for(int k=4; k < (4+Num_of_files); k++){
                for (int m = 0; name2[m]!='\0'; m++){
                    if(line[k][m] == name2[m]){
                        length++;
                    }
                    else{
                        check = 1;
                        break;
                    }
                }
                if(check == 0){

                    add = (line[k][length+1]);///////////////////////////////////////

                    block_add = line[first_block + (add-'0')][0];
                    line[first_block + (add-'0')][0] = '-';

                    while(1){
                        if(line[first_block + (block_add-'0')][0] == '-'){
                            if(line[first_block + (block_add-'0')][1] == '1'){
                                //printf("-1 found\n");
                                //memset(line[first_block + (add-'0')], 0, sizeof(line[first_block + (add-'0')]));
                                line[first_block + (block_add-'0')][0] = '-';
                                line[first_block + (block_add-'0')][1] = ' ';
                                break;
                            }
                            else{ 
                                //printf("- found\n");
                                break;
                            }
                        }
                        else{
                           //printf("Number found = %c\n", line[first_block + (block_add-'0')][0]);
                            new_block_add = line[first_block + (block_add-'0')][0];
                            line[first_block + (block_add-'0')][0] = '-';
                            block_add = new_block_add;
                        }
                    }
                    
                    printf("\n\n\n=====The total space allocated for %s is cleared=====\n\n\n", name2);
                    blocks = 0;
                    break;

                }
                else{
                    check = 0;
                    length = 0;
                }
            }
            for(int i=0; i<18; i++){                                //Use this to check the array
               printf("%s\n", line[i]);
            }
    	}




    	else if(c == '3'){
            blocks = 0;

            while(counter!=row){
                if(line[first_block][0] == '-' && line[first_block][1] != '1'){
                    blocks++;
                    first_block++;
                }
                else{
                    first_block++;
                }
                counter++;
            }

            printf("\n\n=====The total free space is %d bytes=====\n", (blocks*32));
            counter = 0;
            first_block = 8;
    	}



        else if(c == '4'){
            printf("\nGoodbye!\n");
            break;
        }




    	else{
    		printf("\nOption is invalid\n");
    	}
    	c=getchar();

    }




    printf("\n");
    return 0;
}