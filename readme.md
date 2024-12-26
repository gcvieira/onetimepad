# One Time Pad in C

Simple implementation of the One Time Pad encryption (the only unbreakable encryption method) in C.

## Usage

	gcc enc.c -o enc
	gcc dec.c -o dec

	./enc secret_file

	./dec encryptedfile keyfile
