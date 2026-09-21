
#include "all_size.h"

#include <stdio.h>

int 
main(int argc,char**argv)
{
  char cdir[3] = ".\0";
  char*current_dir;
  int c = 0;
  if(argc == 1)
    current_dir = cdir;
  else
    current_dir = argv[1];

  struct Info all_info;
  all_info = calculate_dir(current_dir,c);

  printf("\n\n\tall_size: %zu\n\tall_dir:  %zu\n\tall_file: %zu\n\n",all_info.all_size,all_info.dir,all_info.file);

  return 0;
}
