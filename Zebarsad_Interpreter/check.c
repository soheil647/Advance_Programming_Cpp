#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_DIR "testcases/data/1/"
#define SOLUTION_DIR "testcases/data/1/"
#define ANSWER_DIR "ans/"

#define INPUT_EXTENTION ".in"
#define SOLUTION_EXTENTION ".sol"
#define ANSWER_EXTENTION ".ans"

int main(int argc, char const *argv[]) {
  if(argc != 2)
  {
    printf("invalid number of arguments %d. write format: ./program num/of/inputs\n", argc);
    return -1;
  }

  char command[80];
  char input_file[80];
  char answer_file[80];
  char solution_file[80];
  const int files_number = atoi(argv[1]);

  for(int file_number = 1; file_number <= files_number; file_number ++)
  {
    sprintf(input_file, "%s%d%s", INPUT_DIR, file_number, INPUT_EXTENTION);
    sprintf(answer_file, "%s%d%s", ANSWER_DIR, file_number, ANSWER_EXTENTION);
    sprintf(solution_file, "%s%d%s", SOLUTION_DIR, file_number, SOLUTION_EXTENTION);
    sprintf(command, "./a.out < %s > %s\n", input_file, answer_file);
    system(command);
    printf("diffrents between your answer and solution in test number %d:\n", file_number);
    usleep(1000);
    sprintf(command, "diff %s %s\n", answer_file, solution_file);
    system(command);
  }

  return 0;
}
