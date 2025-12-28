#include "get_next_line.h"
int main(){
	int fd = open("file.txt", O_RDONLY);
	char* line;
	while((line = get_next_line(fd))!= NULL)
    {
        printf("%s", line);
	    free(line);
    }

	return 0;
}
