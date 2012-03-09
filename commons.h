#ifndef COMMONS_H
#define COMMONS_H

#include <arpa/inet.h>
/*
	for:
		htons()
		htonl()
		ntohs()
		inet_aton()
		inet_ntoa()
*/

#include <netinet/in.h>
/*
	for:
		inet_aton()
		inet_ntoa()
*/

#include <sys/types.h>
/*
	for:
		socket()
		bind()
		recvfrom()
		sendto()
		stat()
*/

#include <sys/socket.h>
/*
	for:
		socket()
		bind()
		recvfrom()
		sendto()
		inet_aton()
		inet_ntoa()
		AF_INET
		SOCK_DGRAM
*/

#include <errno.h>
/*
	for:
		return type of system calls
*/

#include <stdio.h>
/*
	for:
		printf()
		sprintf()
		fflush()
		perror()
*/

#include <stdlib.h>
/*
	for:
		exit()
		malloc()
*/

#include <string.h>
/*
	for:
		memset()
		strlen()
		strcpy()
*/

#include <unistd.h>
/*
	for:
		close()
		sleep()
		stat()
*/

#include <dirent.h>

#define	DEBUG		1

#define	LENBUFFER	506		// so as to make the whole packet well-rounded ( = 512 bytes)
#define	PORTSERVER	8487

enum TYPE
	{
		REQU,
		DONE,
		INFO,
		TERM,
		DATA,
		EOT
	};

#define	NP		0
#define	HP		1

#define	er(e, x)					\
	do						\
	{						\
		perror("ERROR IN: " #e "\n");		\
		fprintf(stderr, "%d\n", x);		\
		exit(-1);				\
	}						\
	while(0)

//TODO: Make two kinds of packets: one for INFO, the other for DATA.

struct packet
{
	short int conid;
	short int type;
	short int comid;
	char buffer[LENBUFFER];
};

void set0(struct packet*);

struct packet* ntohp(struct packet*);
struct packet* htonp(struct packet*);

void printpacket(struct packet*, int);

#define NCOMMANDS 17
enum COMMAND
	{
		GET,
		PUT,
		MGET,
		MPUT,
		CD,
		LCD,
		MGETWILD,
		MPUTWILD,
		DIR_,		// _ to avoid conflict with directory pointer DIR
		LDIR,
		LS,
		LLS,
		RGET,
		RPUT,
		PWD,
		LPWD,
		EXIT
	};			// any change made here should also be \
				replicated accordingly in the commandlist \
				2D array in client_ftp_fucntions.c

#endif

