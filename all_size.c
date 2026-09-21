

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>


#define MAX_PATH 1024
#define MAX_NAME 14


size_t calculate_dir(const char*name_dir)
{
  size_t all_size = 0;
  struct stat*file_stat;
  DIR*dir;
  struct dirent*entry;

  dir = opendir(name_dir);
  if(dir == NULL) return 1;
  
  while((entry = readdir(dir)) != NULL)
  {
    stat((*entry).d_name,file_stat);
    if()/*якщо це директорія*/
    {
      all_size += calculate_dir((*entry).d_name);
    }
    else/*якщо це файл*/
    {
      all_size += (*file_stat).st_size;
    }
  }
  return all_size;
}


