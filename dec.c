#include <stdio.h>
#include <stdlib.h>

void decrypt(FILE* encrypted_file, FILE* key_file){
	FILE* decrypted_file = fopen("decrypted.out", "w");

	int enc_c;
	while((enc_c = fgetc(encrypted_file)) != EOF){
		int key_c = fgetc(key_file);
		int decrypted_character = enc_c ^ key_c;

		fputc(decrypted_character, decrypted_file);
	}

	fclose(decrypted_file);
}

void main(int argc, char* argv[]){
	if (argc != 3){
		printf("Usage: dec <encrypted file> <key file> \n");
	} else {
		FILE* encrypted_file = fopen(argv[1], "r");
		FILE* key_file = fopen(argv[2], "r");

		decrypt(encrypted_file, key_file);
		fclose(encrypted_file);
		fclose(key_file);
	}
}
