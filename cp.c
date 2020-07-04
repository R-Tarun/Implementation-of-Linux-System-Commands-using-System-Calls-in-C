
#include<stdio.h>
#include<fcntl.h>
int main( int argc,char *argv[] )
{
    int i,fd1,fd2;
    char *file1,*file2,buf[2];
    file1=argv[1];
    file2=argv[2];
    printf("file1=%s file2=%s\n",file1,file2);
    fd1=open(file1,O_RDONLY);
    fd2=open(file2,O_WRONLY | O_CREAT | O_TRUNC,S_IRWXU | S_IRWXG | S_IRWXO);
    while(i=read(fd1,buf,1)>0){
        write(fd2,buf,1);
    }
    close(fd1);
    close(fd2);
    return 0;
}
