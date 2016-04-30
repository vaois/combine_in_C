#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char*argv[])
{
	char c;
	int in1,in2,out;
    int length;

	in1 = open(argv[1],O_RDONLY);
	in2 = open(argv[2],O_RDONLY);
	out = open(argv[3], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

	length = lseek(in1,0,SEEK_END);
	lseek(in1,0,SEEK_SET);
	while(read(in1,&c,1) == 1)
		write(out,&c,1);
	close(in1);
	lseek(out,length,SEEK_SET);
	while(read(in2,&c,1) == 1)
		write(out,&c,1);
	close(in2);
	close(out);
	exit(0);





}
