#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define BS 100

// bs means sife of the buffer
//  pipe is the imporant process where the output of one process is input of
//  another process
//  int pipe(int fds[2]);Parameters :fd[0] will be the fd(file descriptor) for
//  the read end of pipe.fd[1] will be the fd for the write end of pipe Returns
//  : 0 on Success and -1 on error.

// when we create a pipe,the kernel gives two descriptors which are write and
// read
// p1p2[0] read end of the pipe and also the p2p1[0] write end of the pipe
// p1p2[0] always used for reading and the p2p1[0] is always for the writing

// buf is the memory where the data is stored in the memory
// this means read upto 100 characters  from the p1p2[0] and then place them to
// the buf and we have to write only to the length it is necessary not full,so
// we use the write(p2p1[1],buf,strlen(buf)+1) close the descriptions we dont
// use
// read = take data out of the pipe (receive)
// write = put data into the pipe (send)

int main() {
  int p1p2[2], p2p1[2];
  char str1[BS], str2[BS] = "World", buf[BS];
  pipe(p1p2);
  pipe(p2p1);

  if (fork() == 0) { // child is p2 and parent is p1
    close(p1p2[1]);
    close(p2p1[0]);

    read(p1p2[0], buf, BS);
    int i = 0, j = 0;
    while (buf[i] != '\0') {
      i++;
    }
    while (str2[j] != '\0') {
      buf[i++] = str2[j++];
    }
    buf[i] = '\0';

    write(p2p1[1], buf, BS);
    close(p1p2[0]);
    close(p2p1[1]);
  } else { // Parent = P1
    close(p1p2[0]);
    close(p2p1[1]);
    printf("Enter a string: ");
    scanf("%s", str1);

    write(p1p2[1], str1, BS);
    read(p2p1[0], buf, BS);

    printf("Final string: %s\n", buf);
    close(p1p2[1]);
    close(p2p1[0]);
  }
  return 0;
}
