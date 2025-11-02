#include <fcntl.h>
#include <linux/fs.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [+i|-i|+a|-a] <path>\n", argv[0]);
        return 1;
    }
    int fd = open(argv[2], O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }

    unsigned long flags;
    if (ioctl(fd, FS_IOC_GETFLAGS, &flags) < 0) { perror("GETFLAGS"); return 1; }

    if (argv[1][0] == '+') {
        if (argv[1][1] == 'i') flags |= FS_IMMUTABLE_FL;
        if (argv[1][1] == 'a') flags |= FS_APPEND_FL;
    }
    else if (argv[1][0] == '-') {
        if (argv[1][1] == 'i') flags &= ~FS_IMMUTABLE_FL;
        if (argv[1][1] == 'a') flags &= ~FS_APPEND_FL;
    }
    else {
        fprintf(stderr, "Bad flag: %s\n", argv[1]);
        return 1;
    }

    if (ioctl(fd, FS_IOC_SETFLAGS, &flags) < 0) { perror("SETFLAGS"); return 1; }
    close(fd);
    return 0;
}
