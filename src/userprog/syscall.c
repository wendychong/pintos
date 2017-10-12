#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  printf("system call!\n");
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  printf ("system call!\n");
  thread_exit ();
}

/*
static int sys_halt (void) {
  shutdown_power_off();
}

static int sys_exec (const char *cmd) {
  int test;

  //if this is a bad ptr
  if (!cmd || !is_user_vaddr (cmd) 
    return -1;

  lock_acquire (&file_lock);
  test = process_execute (cmd);
  lock_release (&file_lock);
  return test;
}

static int sys_wait(pid_t pid) {
  return process_wait(pid);
}

static int sys_create (const char *file, unsigned initial_size) {
  if (!file)
    return sys_exit(-1);
  return filesys_create (file, inirial_size);
}

static int sys_remove (const char *file) {
  if(!file)
    return false;
  if (!is_user_vaddr (file))
    return filesys_remove(file);
}

static int sys_open (const char *file) {
  struct file *f;
  struct fd_elem *fde;
  int test;

  test = -1; //initialize to -1
  //if file == NULL
  if (!file)
    return -1;
  if(!is_user_vaddr (file))
    sys_exit(-1);
  f = filesys_open (file);
  //if bad file name
  if (!f)
    goto done;

  fde = (struct fd_elem *) malloc (sizeof (struct fd_elem));
  //if there is not enough memory
  if (!fde) {
    file_close (f);
    goto done;
  }

  fde -> file = f;
  fde -> fd = alloc_fid ();
  list_push_back (&file_list, &fde -> elem);
  list_push_back (&thread_current () -> files, &fde -> thread elem);
  test = fde -> fd;
done:
  return test;
}
*/

 
