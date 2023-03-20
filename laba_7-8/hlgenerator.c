#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include <signal.h>
#include <unistd.h>
#include "math.h"
#include <sys/types.h>
#include <sys/wait.h>

#ifndef countof
#define countof(x)	(sizeof( x ) / sizeof( x[0] ))
#endif

#define WAIT_ANY (-1)

#define	SELF_NAME	"hlgenerator"


static size_t arrsz(const char** arr);


const char* schemes[] = {
        "http://",
        "https://",
        "ftp://",
        "news://",
        "foobar://",
        "data:",
        "foo:",
        "",
};

const char* users[] = {
        "john:doe@",
        "smith@",
        "123456@",
        ""
};

const char* domains[] = {
        "gosuslugi.ru",
        "ietf.org",
        "москва.рф",
        ""
};

const char* ports[] = {
        ":8080",
        ":[80]",
        "[:80]",
        ":",
        ""
};

const char* paths[] = {
        "/",
        "/foo",
        "/foo/",
        "/foo/bar",
        "/foo/bar/",
        ""
};

const char* queries[] = {
        "?foo=bar&bar=buz",
        "?foo=bar&",
        "?foo=bar",
        "?foo=",
        "?foo",
        "?",
        ""
};

const char* anchors[] = {
        "#foo%20bar",
        "#foo%20",
        "#%20foo",
        "#foo",
        "#",
        ""
};

const char** sources[] = {
        schemes,
        users,
        domains,
        ports,
        paths,
        queries,
        anchors
};

size_t
arrsz(const char** arr) {
    size_t	n = 0;
    do {
        n++;
    } while (arr[n][0] != '\0');
    return ++n;
}

int main() {
    size_t	idx[countof(sources)], j, t, nvariants = 1;
    char	buf[1024];
    int status;
    long cpus = sysconf(_SC_NPROCESSORS_ONLN);
    pid_t processes[cpus];

    for (int i = 0; i < countof(sources); i++)
        nvariants *= arrsz(sources[i]);

    for (int k = 0; k < cpus; k++) {
        processes[k] = fork();
        if (processes[k] == 0) {
            printf("child pid: %d, parent pid: %d\n", getpid(), getppid());
            for (size_t i = 0; i < nvariants; i++) {
                t = i;
                buf[0] = '\0';
                for (j = 0; j < countof(sources); j++) {
                    idx[j] = t % arrsz(sources[j]);
                    if (strlcat(buf, sources[j][idx[j]], sizeof(buf)) >= sizeof(buf)) {
                        fprintf(stderr, "internal buffer was too small\n");
                        return 1;
                    }
                    t /= arrsz(sources[j]);
                }
//                puts(buf);
            }
            kill(getpid(), SIGKILL);
            exit(0);
        }
    }

    for (int k = 0; k < cpus; k++) {
        waitpid(WAIT_ANY, &status, 0);
        if (WIFSIGNALED(status)) {
            for (int k = 0; k < cpus; k++) {
                if (kill(processes[k], SIGKILL) == 0) {
                    printf("killed process with pid: %d\n", processes[k]);
                }
            }
            return 0;
        }
    }

    return 0;
}
