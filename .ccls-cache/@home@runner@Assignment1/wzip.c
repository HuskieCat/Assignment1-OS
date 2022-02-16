#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) 
{
  if(argc < 2)
  {
    printf("To few arguments\n");
    return 0;
  }

  FILE *fp;
  for(int i = 1; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wgrep: cannot open file\n");
      return 1;
    }

    int counter = 0;
    while(!feof(fp))
    {
      char current_character;
      char previous_character;
      char next = fgetc(fp);
      if(previous_character == next)
      {
        counter++;
      }
      else if (next == ' ' || next == '\n')
      {
        continue;
      }
      else
      {
        if(counter != 0)
        {
          //printf("%d%c", counter, current_character);
          fwrite(&counter, 2, 1, stdout);
          //char buffer[2] = {current_character};
          //fwrite(buffer, 1, 1, stdout);
          fwrite(&current_character, 1, 1, stdout);
        }
        
        current_character = next;
        counter = 1;
        previous_character = current_character;
      }
    }
  }

  fclose(fp);

  return 0;
}