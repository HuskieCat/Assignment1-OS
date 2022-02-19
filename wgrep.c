#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Duplicates the basic functionality of the command 'grep'.
 * Searches a file for a specific word or phrase
 * @Author Bradley Henderson
*/

int main(int argc, char** argv) 
{
  if(argc < 2)
  {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }

  char *search_term = argv[1];

  //Lines in after the fact
  if(argc == 2)
  {
    char *buffer;
    size_t buffer_size = 32;
    buffer = (char *)malloc(buffer_size * sizeof(char));
    while(getline(&buffer, &buffer_size, stdin) != -1)
    {
      if(strstr(buffer, search_term))
        printf("%s", buffer);
    }
    return 0;
  }

  FILE *fp;
  for(int i = 2; i < argc; i++)
  {
    fp = fopen(argv[i], "r");
    if(fp == NULL)
    {
      printf("wgrep: cannot open file\n");
      return 1;
    }
    
    while(!feof(fp))
    {
      char *buffer;
      size_t buffer_size = 32;
      buffer = (char *)malloc(buffer_size * sizeof(char));
      if(getline(&buffer, &buffer_size, fp) != -1)
        if(strstr(buffer, search_term))
          printf("%s", buffer);
    }
    fclose(fp);
  }

  return 0;
}