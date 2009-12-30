/*
 * Public domain 2008 David Crawshaw <david@zentus.com>
 * http://www.zentus.com/rhost-check.html
 * Usage: tcpserver -R -h -p 0 smtp rhost-check rblsmtpd qmail-smtpd
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        fputs("usage: rhost-check program [arguments]\n", stderr);
        return 111;
    }
    if (getenv("TCPREMOTEHOST") == 0) {
        putenv("RBLSMTPD=bad reverse DNS");
    }

    execvp(argv[1], argv+1);
    fputs("error: execution of rhost-check failed\n", stderr);
    return 111;
}
