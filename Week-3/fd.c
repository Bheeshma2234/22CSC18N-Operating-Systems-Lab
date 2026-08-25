#include <stdio.h>      
#include <unistd.h>     
#include <fcntl.h>      
#include <stdlib.h>     
#include <sys/ioctl.h>  
#include <sys/stat.h>   
#define WR_VALUE _IOW('a','a',int*)  
#define RD_VALUE _IOR('a','b',int*)  
int main()
{
    int fd, fd2, fd3;
    char c[20] = {0};
    char c1[20] = {0};
    int number;

    fd = open("sample.txt", O_RDONLY | O_CREAT, 0644);

    fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    fd3 = open("file3.txt", O_RDWR | O_CREAT, 0644);

    if (fd < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("File opening failed\n");
        return 1;
    }

    read(fd, c, 20);
    printf("Text in file is: %s\n", c);

    write(fd2, c, 20);

    lseek(fd, 5, SEEK_CUR);

    read(fd, c1, 20);
    printf("Text after lseek: %s\n", c1);

    printf("Enter a value to write in the file: ");
    scanf("%d", &number);

    ioctl(fd3, WR_VALUE, (int *)&number);

    struct stat sfile;
    stat("stat.c", &sfile);

    printf("File mode = %o\n", sfile.st_mode);

    close(fd);
    close(fd2);
    close(fd3);
    return 0;
}
