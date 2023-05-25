#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

// added headers
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "stdbool.h"
// end of added headers

void syscall_init (void);

// added methods

/* system calls */

// Terminates Pintos by calling shutdown_power_off()
void sys_halt();

// Terminates the current user program, returning status to the kernel. If the process’s parent
// waits for it, this is the status that will be returned. A status of 0 indicates success
// and nonzero values indicate errors
void sys_exit(int status);

// Waits for a child process pid and retrieves the child’s exit status.
// If pid is still alive, waits until it terminates. Then, returns the status that pid passed to exit.
// If pid did not call exit(), but was terminated by the kernel (e.g. killed due to an exception),
// wait(pid) must return -1. It is perfectly legal for a parent process to wait for child processes that have already
// terminated by the time the parent calls wait,
// but the kernel must still allow the parent to retrieve its child’s exit status,
// or learn that the child was terminated by the kernel. 
tid_t  sys_wait(tid_t tid);

// creates a new file called file initially initial_size bytes in size. Returns true if successful,
// false otherwise.
int sys_create(const char *file, unsigned initial_size);

// deletes the file called file. Returns true if successful, false otherwise. 
// removing an open file does not close it.
int sys_remove(const char* file);

// opens the file called file. Returns a nonnegative integer handle called a "file descriptor"
// (fd), or -1 if the file could not be opened. 
int sys_open(const char* file);

// returns the file opened to help setting the file size. 
struct open_file* sys_file(int fd);

// reads size bytes from the file open as fd into buffer. Returns the number of bytes actually
// read (0 at end of file), or -1 if the file could not be read (due to a condition other than end of
// file). Fd 0 reads from the keyboard using input_getc(). 
int sys_read(int fd, void* buffer, unsigned size);

// Writes size bytes from buffer to the open file fd.
// Returns the number of bytes actually written, which may be less than size if some bytes could not be written. 
// Fd 1 writes to the console.
int sys_write(int fd, const void* buffer, unsigned size);

// Changes the next byte to be read or written in open file fd to position, expressed in bytes
// from the beginning of the file.
void sys_seek(struct intr_frame *f);

// Returns the position of the next byte to be read or written in open file fd.
void sys_tell(struct intr_frame *f);

// Closes file descriptor fd. Exiting or terminating a process implicitly closes all 
// its open file descriptors, as if by calling this function for each one.
int close(int fd);

// end of added methods

#endif /* userprog/syscall.h */
