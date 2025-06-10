#include<stdio.h>
/* It provides functionality for input and output operations */


#include <fcntl.h>
/* The <fcntl.h> header is a POSIX (Portable Operating System Interface) header file, commonly used in UNIX-like systems (e.g., Linux, macOS).
It provides functions and constants for file control operations, such as opening files and setting file descriptor flags.
What Does It Provide?
Functions:
open(): Opens a file and returns a file descriptor (FD). This is the main function used in the program.
fcntl(): Performs control operations on file descriptors (e.g., setting flags, duplicating FDs).
*/


#include <unistd.h>
/* What Is It?
The <unistd.h> header is another POSIX header file, providing access to UNIX system calls and constants.
It’s one of the most fundamental headers for system-level programming in UNIX-like systems.
What Does It Provide?
Functions:
write(): Writes data to a file descriptor (used in the program).
read(): Reads data from a file descriptor.
close(): Closes a file descriptor, freeing up system resources.
lseek(): Changes the offset (position) in the file for the next read/write.
dup(), dup2(): Duplicates file descriptors.
Constants:
Standard file descriptors:
STDIN_FILENO (0): Standard input.
STDOUT_FILENO (1): Standard output.
STDERR_FILENO (2): Standard error.
Types:
ssize_t: Used for the return type of write() and read() (can hold both positive sizes and -1 for errors).
off_t: Used for file offsets (e.g., in lseek()).
*/


#include<string.h>
/* Functions:
strlen(): Returns the length of a C-style string (excluding the null terminator).
strcpy(), strncpy(): Copies strings.
strcmp(): Compares strings.
memset(), memcpy(): Manipulates raw memory (e.g., setting or copying bytes).
Types:
size_t: An unsigned integer type used for sizes (returned by strlen()). */


#include <sys/stat.h>
/*What Is It?
The <sys/stat.h> header is a POSIX header file that provides functions and types for retrieving and modifying file metadata (e.g., permissions, size, timestamps).
What Does It Provide?
Functions:
stat(), fstat(), lstat(): Retrieve file metadata (e.g., size, permissions, inode number).
mkdir(): Creates a directory.
chmod(), fchmod(): Changes file permissions.
Types and Structures:
struct stat: A structure that holds file metadata, with fields like:
st_mode: File permissions and type (e.g., regular file, directory).
st_size: File size in bytes.
st_mtime: Last modification time.
st_ino: Inode number.
Constants:
Permission bits (e.g., S_IRUSR, S_IWUSR for read/write permissions for the owner).
File type macros (e.g., S_ISREG() to check if a file is a regular file).  */


int main(){

    const char *textToWriteBlue = "Hello blue file";
    const char *textToWritePink = "Hello pink file";
    int fd1 = open("blue.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int fd2 = open("pink.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    /*  
    int open(const char *pathname, int flags, mode_t mode);

    First Argument (pathname): The path to the file (e.g., "blue" in your program).
    Second Argument (flags): A bitwise OR of flags that control how the file is opened (e.g., O_WRONLY, O_CREAT, O_TRUNC).
    Third Argument (mode): The permissions for the file if it’s created (only used if O_CREAT is set in flags).*/

    if (fd1 == -1 | fd2 == -1 ){
        printf("Chud gye guru");
        return 1;
    }

    ssize_t bytes_written_in_blue = write(fd1, textToWriteBlue, strlen(textToWriteBlue));
    ssize_t bytes_written_in_pink = write(fd2, textToWritePink, strlen(textToWritePink));

    // printf("wrote to blue and pink");


    lseek(fd2,0, SEEK_SET); 
    char bufferPink[100];
    ssize_t byte_read_pink = read(fd2, bufferPink, sizeof(bufferPink)-1);
    return 0;
}