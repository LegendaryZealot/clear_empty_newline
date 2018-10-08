#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;
    int count;
    char buf[128];
    if (2!=argc) {
        printf("$(app_name) file_path\n");
        return 0;
    }
    if(-1==(fd=open(argv[1],O_RDONLY)))
    {
        printf("bad file_path\n");
        return 0;
    }
    while(0<(count=read(fd,buf,sizeof(buf)))){
        for(int i=0;i<count;i++){
            if(32!=buf[i]&10!=buf[i]&13!=buf[i]){
                printf("%c",buf[i]);
            }
        }
    }
    close(fd);
    return 0;
}

// 回车，ASCII码13
// 换行，ASCII码10
// 空格，ASCII码32
