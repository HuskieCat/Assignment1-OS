#include <stdio.h>
#include <string.h>

/*
 * Duplicates the basic functionality of the command 'unzip'.
 * Produces the unzipped version of a binary file in readible ascii values
 * Examples: (logical representation) 3a2b = aaabb
 * @Author Bradley Henderson
*/

int main(int argc, char** argv) 
{
  if(argc < 2)
  {
    printf("wunzip: file1 [file2 ...]\n");
    return 1;
  }

  FILE *fp;
  for(int i = 1; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wunzip: cannot open file\n");
      return 1;
    }

    while(!feof(fp))
    {
      int counter = 0;
      char current;
      unsigned long counter_value = fread(&counter, 1, sizeof(int), fp);
      unsigned long current_value = fread(&current, 1, sizeof(char), fp);

      if(counter_value == 0 && current_value == 0)
        break;

      for(int i = 0; i < counter; i++)
        printf("%c", current);
    }
  }

  fclose(fp);

  return 0;
}