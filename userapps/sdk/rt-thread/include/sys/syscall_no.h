NRSYS(exit)            /* 01 */
NRSYS(read)
NRSYS(write)
NRSYS(lseek)
NRSYS(open)            /* 05 */
NRSYS(close)
NRSYS(ioctl)
NRSYS(fstat)
NRSYS(poll)
NRSYS(nanosleep)       /* 10 */
NRSYS(gettimeofday)
NRSYS(settimeofday)
NRSYS(exec)
NRSYS(kill)
NRSYS(getpid)          /* 15 */
NRSYS(getpriority)
NRSYS(setpriority)
NRSYS(sem_create)
NRSYS(sem_delete)
NRSYS(sem_take)        /* 20 */
NRSYS(sem_release)
NRSYS(mutex_create)
NRSYS(mutex_delete)
NRSYS(mutex_take)
NRSYS(mutex_release)   /* 25 */
NRSYS(event_create)
NRSYS(event_delete)
NRSYS(event_send)
NRSYS(event_recv)
NRSYS(mb_create)       /* 30 */
NRSYS(mb_delete)
NRSYS(mb_send)
NRSYS(mb_send_wait)
NRSYS(mb_recv)
NRSYS(mq_create)       /* 35 */
NRSYS(mq_delete)
NRSYS(mq_send)
NRSYS(mq_urgent)
NRSYS(mq_recv)
NRSYS(thread_create)   /* 40 */
NRSYS(thread_delete)
NRSYS(thread_startup)
NRSYS(thread_self)
NRSYS(channel_open)
NRSYS(channel_close)   /* 45 */
NRSYS(channel_send)
NRSYS(channel_send_recv_timeout)
NRSYS(channel_reply)
NRSYS(channel_recv_timeout)
NRSYS(enter_critical)  /* 50 */
NRSYS(exit_critical)

NRSYS(brk)
NRSYS(mmap2)
NRSYS(munmap)

NRSYS(shmget)
NRSYS(shmrm)
NRSYS(shmat)
NRSYS(shmdt)

/* The following syscalls requre to be arranged. */
NRSYS(rt_device_init)
NRSYS(rt_device_register)
NRSYS(rt_device_control)
NRSYS(rt_device_find)
NRSYS(rt_device_open)
NRSYS(rt_device_close)
NRSYS(rt_device_read)
NRSYS(rt_device_write)

NRSYS(stat)
NRSYS(rt_thread_find)

NRSYS(accept)
NRSYS(bind)
NRSYS(shutdown)
NRSYS(getpeername)
NRSYS(getsockname)
NRSYS(getsockopt)
NRSYS(setsockopt)
NRSYS(connect)
NRSYS(listen)
NRSYS(recv)
NRSYS(recvfrom)
NRSYS(send)
NRSYS(sendto)
NRSYS(socket)

NRSYS(closesocket)
NRSYS(getaddrinfo)
NRSYS(gethostbyname2_r)
NRSYS(network_resv0)
NRSYS(network_resv1)
NRSYS(network_resv2)
NRSYS(network_resv3)
NRSYS(network_resv4)
NRSYS(network_resv5)
NRSYS(network_resv6)
NRSYS(network_resv7)

NRSYS(select)

NRSYS(_lock)
NRSYS(_unlock)

NRSYS(rt_tick_get)
NRSYS(exit_group)

NRSYS(rt_delayed_work_init)
NRSYS(rt_work_submit)
NRSYS(rt_wqueue_wakeup)
NRSYS(rt_thread_mdelay)
NRSYS(sighandler_set)
NRSYS(sigprocmask)
NRSYS(thread_kill)
NRSYS(thread_sighandler_set)
NRSYS(thread_sigprocmask)
NRSYS(thread_resv0)
NRSYS(thread_resv1)
NRSYS(waitpid)
NRSYS(timer_create)
NRSYS(timer_delete)
NRSYS(timer_start)
NRSYS(timer_stop)
NRSYS(timer_control)

NRSYS(getcwd)
NRSYS(chdir)
NRSYS(unlink)
NRSYS(mkdir)
NRSYS(rmdir)
NRSYS(getdents)

NRSYS(rt_get_errno)
NRSYS(set_thread_area)
NRSYS(set_tid_address)
NRSYS(access)

#undef NRSYS
