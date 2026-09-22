
#include "all_size.h"

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

#define MAX_PATH 1024

struct Info calculate_dir(const char*name_dir)
{
  struct Info info = zero_info();
  struct Info temp;
  struct stat file_stat;
  DIR*dir;
  struct dirent*directory;
  char path[MAX_PATH];

  dir = opendir(name_dir);
  if(dir == NULL)
  {
    perror("\nDirect do not open: ");
    printf("\tPath to directory: %s\n",name_dir);
    return zero_info();
  }

  while((directory = readdir(dir)) != NULL)
  {
    build_path(path,name_dir,(*directory).d_name);

    if(lstat(path,&file_stat) != 0)
    {
      perror("\nlstat return not zero about: ");
      printf("\tPath to directory: %s\n",name_dir);
      return zero_info();
    }

    if((file_stat.st_mode & S_IFMT) == S_IFREG)/*if it's file*/
    {
      printf("\033[44;97m%s\033[0m\t\tsize: \033[42;97m%zu\033[0m\n",(*directory).d_name,file_stat.st_size);
      info.all_size += file_stat.st_size;
      info.file     += 1;
    }
    else if((file_stat.st_mode & S_IFMT) == S_IFDIR)/*if it's directory*/
    {
      if(comparise((*directory).d_name,".") ||
         comparise((*directory).d_name,"..")) continue;
      
      printf("\033[41;97m%s\033[0m\n",(*directory).d_name);
      temp = calculate_dir(path);
      additional_info(&info,&temp);
      info.dir += 1;
    }
    else {continue;}
  }
  putchar('\n');
  return info;
}


int comparise(const char*arg1,const char*arg2)
{
  for(;*arg1 != '\0' && *arg2 != '\0';arg1++,arg2++)
  {
    if(*arg1 != *arg2) return 0;
  }
  return 1;
}


void additional_info(struct Info*master,struct Info*slave)
{
  (*master).all_size += (*slave).all_size;
  (*master).dir      += (*slave).dir;
  (*master).file     += (*slave).file;
}


struct Info zero_info()
{
  struct Info zero;
  zero.all_size = 0;
  zero.dir = 0;
  zero.file = 0;
  return zero;
}

void build_path(char*new_path,const char*path,const char*name)
{
  if(!comparise(path,"."))
  {
    for(;*path != '\0';new_path++,path++)
    {
      *new_path = *path;
    }
    *new_path = '/';
    new_path++;
  }

  for(;*name != '\0';new_path++,name++)
  {
    *new_path = *name;
  }
  *new_path = '\0';
}


