/**
 * 3. Write a C application “writer” (finder-app/writer.c)  which can be used as an alternative to
 * the “writer.sh” test script created in assignment1 and using File IO as described in LSP chapter 2.
 * See the Assignment 1 requirements for the writer.sh test script and these additional instructions:
 *
 * One difference from the write.sh instructions in Assignment 1:
 * You do not need to make your "writer" utility create directories which do not exist.
 * You can assume the directory is created by the caller.
 * Setup syslog logging for your utility using the LOG_USER facility.
 * Use the syslog capability to write a message “Writing <string> to <file>”
 *     where <string> is the text string written to file (second argument) and <file> is the file created by the script.
 *     This should be written with LOG_DEBUG level.
 *
 * Use the syslog capability to log any unexpected errors with LOG_ERR level.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>


#define NUM_ARG 2

int main(int argc, char *argv[])
{
	FILE *fp;
	openlog("assignment2-writer-log", LOG_CONS|LOG_NDELAY|LOG_PERROR, LOG_USER);
    if (argc != NUM_ARG + 1)
    {
        syslog(LOG_ERR, "Usage: writer [WRITEFILE] [WRITE_STR]\n"
                "[WRITEFILE]:\tFull path to a file (including filename) on the filesystem\n"
                "[WRITE_STR]:\tText string which will be written within WRITEFILE"
                "Return: 0 if success, otherwise error return 1\n");
		return 1;
    }

    
    char* write_str = argv[2];
    char* write_file = argv[1];
    syslog(LOG_DEBUG, "Writing %s to %s", write_str, write_file);
    fp = fopen(write_file, "w");
    if (NULL == fp)
    {
    	syslog(LOG_ERR, "%s",strerror(errno));
    	return 1;
    }
   
    syslog(LOG_DEBUG, "Writing %s to %s", write_str, write_file);
	fprintf(fp,"%s", write_str);
	fclose(fp);

	closelog();	

	return 0;
}
