#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "threads/init.h"
#include "devices/shutdown.h"
#include "threads/vaddr.h"
#include <debug.h>

static void syscall_handler(struct intr_frame *);
static uint32_t * esp;


static void sys_halt(void);
static void sys_exit(int status);
static int sys_write(int fd, void *buffer, unsigned size);

void
syscall_init(void) {
  intr_register_int(0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler(struct intr_frame * f UNUSED) {
  esp = f->esp;

  int sys_call_number = *esp;

  if (is_kernel_vaddr(esp)){
    sys_exit(-1);
  }

  switch (sys_call_number) {
  case SYS_HALT:
    sys_halt();
    break;
  case SYS_EXIT:
    sys_exit(*(esp + 1));
    break;
  case SYS_WRITE:
    break;
  default:
    break;
  }
}

void sys_halt(void) {
  shutdown_power_off();
}

void sys_exit(int status) {
  thread_exit();
}


//static int sys_exec (const char *cmd) {
//  int test;
//
//  //if this is a bad ptr
//  if (!cmd || !is_user_vaddr (cmd)
//    return -1;
//
//  lock_acquire (&file_lock);
//  test = process_execute (cmd);
//  lock_release (&file_lock);
//  return test;
//}
//
//static int sys_wait(pid_t pid) {
//  return process_wait(pid);
//}

//static int sys_create (const char *file, unsigned initial_size) {
//  if (!file)
//    return sys_exit(-1);
//  return filesys_create (file, inirial_size);
//}
//
//static int sys_remove (const char *file) {
//  if(!file)
//    return false;
//  if (!is_user_vaddr (file))
//    return filesys_remove(file);
//}
//
//static int sys_open (const char *file) {
//  struct file *f;
//  struct fd_elem *fde;
//  int test;
//
//  test = -1; //initialize to -1
//  //if file == NULL
//  if (!file)
//    return -1;
//  if(!is_user_vaddr (file))
//    sys_exit(-1);
//  f = filesys_open (file);
//  //if bad file name
//  if (!f)
//    goto done;
//
//  fde = (struct fd_elem *) malloc (sizeof (struct fd_elem));
//  //if there is not enough memory
//  if (!fde) {
//    file_close (f);
//    goto done;
//  }
//
//  fde -> file = f;
//  fde -> fd = alloc_fid ();
//  list_push_back (&file_list, &fde -> elem);
//  list_push_back (&thread_current () -> files, &fde -> thread elem);
//  test = fde -> fd;
//done:
//  return test;
//}


 
