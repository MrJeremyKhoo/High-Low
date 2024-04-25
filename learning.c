#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* 응답을받다 (char* response, int j) {
  char * 결과;
      if (response) {
                // Find the start of the 3rd line after "Higher"
                for (int i = 0; i < j +1 ; i++) {
                    response = strchr(response + 1, '\n');
                }
                if (response) {
                    char* endOfThirdLine = strchr(response + 1, '\n');
                    int size = endOfThirdLine - response;
                    결과 = malloc(size * sizeof(char) + 1);
                    memcpy(결과, response, (int)(endOfThirdLine - response));
                    결과[size] = '\0';
                }
            }
    return 결과 + 1;
}

int main() {
    int number, guess, 결과, attempts, attemptsInRowHigher, randomNumber, attemptsInRowLower = 0;
    
  FILE *fptr = fopen("insults", "r");
  fseek(fptr,0,SEEK_END); 
  long int fileSize = ftell(fptr);
  fseek(fptr,0,SEEK_SET); 
  char * print;
  char *buffer = (char*)malloc(fileSize + 1);
  size_t byteRead = fread(buffer,1, fileSize, fptr);
  fclose(fptr);
    // Generate a random number between 1 and 100
    srand(time(0));  // Seed the random number generator
    number = rand() % 100 + 1;
    printf("안영하세여 >_<\n");
    printf("1-100 사이의 숫자를 선택했습니다.\n");
    printf("내 번호 맞춰봐 ㅎㅎㅎㅎ\n");

  char* response;
    do {
        response = buffer;
        do {
          printf("당신의 추측은 무엇입니까");
          결과 = scanf("%d", &guess);
          printf("%d", guess);

          if (결과 < 1) {
              printf("Invalid input. Please enter an integer.\n");

            // Clear the input buffer
            while (getchar() != '\n');
          }
        } while (결과 < 1);

        
        attempts++;
        if (guess > number) {
            attemptsInRowHigher++; 
            attemptsInRowLower = 0;
            response = strstr(buffer, "Higher");
            randomNumber = rand() % 15 + 1;
            print = 응답을받다(response, randomNumber);
            printf("숫자가 나무 큼.\n");
            printf("%s \n", print);
          
        } else if (guess < number) {
            attemptsInRowLower++; 
            attemptsInRowHigher = 0;
            response = strstr(buffer, "Lower");
            randomNumber = rand() % 11 + 1;
            response = 응답을받다(response, randomNumber);
            printf("숫자가 나무 작.\n");
            printf("%s \n", response);
        } else {
            printf("축하합니다! %d 번의 시도 끝에 올바른 숫자를 맞췄습니다..\n", attempts);
        }
    } while (guess != number);

    return 0;
}

