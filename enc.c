#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encrypt(FILE* secret_file){
	FILE* out_file = fopen("encrypted.out", "w");
	FILE* key_file = fopen("key.out", "w");

	int c;
	srand(time(NULL));
	while((c = fgetc(secret_file)) != EOF){
		int key = rand();
		int encryped_character = c ^ key;

		fputc(key, key_file);
		fputc(encryped_character, out_file);
	}

	fclose(key_file);
	fclose(out_file);
}

void main(int argc, char* argv[]){
	if(argc != 2){
		printf("Usage: enc <secret file>\n");
	} else {
		char* filename = argv[1];
		FILE* secret_file = fopen(filename, "r");

		encrypt(secret_file);
		fclose(secret_file);
	}
}
