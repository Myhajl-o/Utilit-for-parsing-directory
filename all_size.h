#ifndef ALL_SIZE_H
#define ALL_SIZE_H

#include <unistd.h>

struct Info
{
  size_t all_size;
  size_t dir;
  size_t file;
};


struct Info calculate_dir(const char*name_dir,int c);
int comparise(const char*arg1,const char*arg2);
void additional_info(struct Info*master,struct Info*slave);
struct Info zero_info();
void build_path(char*new_path,const char*path,const char*name);


#endif
