#include <stdio.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char*argv[]) {
  char *path = "./";
  DIR *dir;
  struct dirent *dent;
  int hid = 1;
  if (argc > 1) {
	if(strcmp(argv[1],"-all")==0 ){
		hid = 0;
	}
  }
  dir = opendir(path);
  if (dir == NULL) {
    perror(path);
    return 1;
  }
  while ((dent = readdir(dir)) != NULL) {
	if (hid==0){
		 printf("%s\n", dent->d_name);
	}else if(dent->d_name[0] != '.'){
		 printf("%s\n", dent->d_name);
 	}
   }
  closedir(dir);
  return 0;
}
