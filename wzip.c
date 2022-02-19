#include <stdio.h>
#include <string.h>

/*
 * Duplicates the basic functionality of the command 'zip'.
 * Takes a file (or series of) and zips them into a singular file
 * Example: aaabb = 3a2b
 * @Author Bradley Henderson
*/

int main(int argc, char** argv) 
{
  if(argc < 2)
  {
    printf("wzip: file1 [file2 ...]\n");
    return 1;
  }

  FILE *fp;
  int counter = 0;
  char previous_character;
  char current;
  for(int i = 1; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wzip: cannot open file\n");
      return 1;
    }

    while(!feof(fp))
    {
      current = fgetc(fp);
      if(previous_character == current)
      {
        counter++;
      }
      else
      {
        // To 'Skip over' the end of file (EOF) and keep counting
        if(counter != 0 && current != EOF)
        {
          fwrite(&counter, sizeof(int), 1, stdout);
          fwrite(&previous_character, sizeof(char), 1, stdout);
        }

        if(current != EOF)
        {
          counter = 1;
          previous_character = current;
        }
      }
    }
  }
  //Used to zip the last of the character count and character
  fwrite(&counter, sizeof(int), 1, stdout);
  fwrite(&previous_character, sizeof(char), 1, stdout);

  fclose(fp);

  return 0;
}