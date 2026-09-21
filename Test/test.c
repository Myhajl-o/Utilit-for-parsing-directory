
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

int
main()
{
  DIR*dir = opendir(".");
  if(dir == NULL) return 1;

  struct dirent*entry;
  struct stat file_stat;
  while((entry = readdir(dir)) != NULL)
  {
    stat((*entry).d_name,&file_stat);
    printf("name: %s\tis_file: %d\tis_dir: %d\n",(*entry).d_name,S_ISREG(file_stat.st_mode),S_ISDIR(file_stat.st_mode));
    printf("\tst_dev:    %zu\n",file_stat.st_dev);
    printf("\tst_ino:    %zu\n",file_stat.st_ino);
    printf("\tst_mode:   %d\n",file_stat.st_mode);
    printf("\tst_nlink:  %zu\n",file_stat.st_nlink);
    printf("\tst_uid:    %d\n",file_stat.st_uid);
    printf("\tst_gid:    %d\n",file_stat.st_gid);
    printf("\tst_rdev:   %zu\n",file_stat.st_rdev);
    printf("\tst_size:   %zu\n",file_stat.st_size);
    printf("\tst_atime:  %zu\n",file_stat.st_atim.tv_sec);
    printf("\tst_mtime:  %zu\n",file_stat.st_mtim.tv_sec);
    printf("\tst_ctime:  %zu\n\n",file_stat.st_ctim.tv_sec);
  }
  
  closedir(dir);
  return 0;
}
