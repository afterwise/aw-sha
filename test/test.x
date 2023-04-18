
#ifndef _nofeatures
# if _WIN32
#  define WIN32_LEAN_AND_MEAN 1
# elif __linux__
#  define _BSD_SOURCE 1
#  define _DEFAULT_SOURCE 1
#  define _POSIX_C_SOURCE 200809L
#  define _SVID_SOURCE 1
# elif __APPLE__
#  define _DARWIN_C_SOURCE 1
# endif
#endif /* _nofeatures */

#include "aw-sha1.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;

	const char data[] =
		"Arvid Stjärnblom gick en Djurgårdsväg\n"
		"fram – den, som kantad af almar med lutande\n"
		"svarta stammar löper längs stranden af den\n"
		"tysta Djurgårdsbrunnsviken, nedanför Skansens\n"
		"skrofliga bergknallar. Utställningsområdet hade\n"
		"han lämnat bakom sig.";
	printf("%.*s\n", (int) sizeof data - 1, data);

	unsigned char h[SHA1_SIZE];
	char s[SHA1_SIZE * 2];
	sha1(h, data, sizeof data - 1);
	sha1str(s, h);
	printf("%.*s\n", (int) sizeof s, s);

	FILE *fd = fopen("test.tmp", "w");
	fwrite(data, 1, sizeof data - 1, fd);
	fclose(fd);

	char buf[256];
	fd = popen("shasum -a1 -b test.tmp", "r");
	fgets(buf, sizeof buf, fd);
	pclose(fd);
	printf("%.*s\n", (int) strcspn(buf, " "), buf);

	remove("test.tmp");
	assert(strncmp(s, buf, sizeof s) == 0);

	printf("OK\n");
	return 0;
}

