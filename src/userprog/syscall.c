#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

    // SYS_HALT,                   /* Halt the operating system. */
    // SYS_EXIT,                   /* Terminate this process. */
    // SYS_EXEC,                   /* Start another process. */
    // SYS_WAIT,                   /* Wait for a child process to die. */
    // SYS_CREATE,                 /* Create a file. */
    // SYS_REMOVE,                 /* Delete a file. */
    // SYS_OPEN,                   /* Open a file. */
    // SYS_FILESIZE,               /* Obtain a file's size. */
    // SYS_READ,                   /* Read from a file. */
    // SYS_WRITE,                  /* Write to a file. */
    // SYS_SEEK,                   /* Change position in a file. */
    // SYS_TELL,                   /* Report current position in a file. */
    // SYS_CLOSE,                  /* Close a file. */

    // /* Project 3 and optionally project 4. */
    // SYS_MMAP,                   /* Map a file into memory. */
    // SYS_MUNMAP,                 /* Remove a memory mapping. */

    // /* Project 4 only. */
    // SYS_CHDIR,                  /* Change the current directory. */
    // SYS_MKDIR,                  /* Create a directory. */
    // SYS_READDIR,                /* Reads a directory entry. */
    // SYS_ISDIR,                  /* Tests if a fd represents a directory. */
    // SYS_INUMBER



static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  int syscall_number = *(int *)f->esp;
  switch (syscall_number) {
    case SYS_HALT: break;
    case SYS_EXIT: 
    case SYS_EXEC:
    case SYS_WAIT:
    case SYS_CREATE:
    case SYS_REMOVE:
    case SYS_OPEN:
    case SYS_FILESIZE:
    case SYS_READ:
    case SYS_WRITE:
    case SYS_SEEK:
    case SYS_TELL:
    case SYS_CLOSE:
    
    default: break;
  }

  printf ("system call!\n");
  thread_exit ();
}
