#include "advTopics.h"

/*

system("/bin/stty raw");
		while(1) {
			   / / no wait for enter key, but function will only return if any keyboard input;
				c = getchar();    // getch() does not exist in Linux
				if(c=='k') break;
				usleep(500);
				printf(".");
		}
		system("/bin/stty cooked");
		*/


int main(int argc, char *argv[]) {
	
	for (int i=0; i< argc; i++){
		printf("... %d: %s\n", argc, argv[i]);
	}
	return 0;
	
}