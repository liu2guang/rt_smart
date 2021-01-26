/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "rtthread.h"
#include "dfs.h"
#include "dfs_fs.h"

extern int pin_test(int argc, char **argv); 

int main(int argc, char **argv)
{
    /* mount ROMFS as root directory */
    extern const struct romfs_dirent romfs_root;
    if (dfs_mount(RT_NULL, "/", "rom", 0, (const void *)(&romfs_root)) == 0)
    {
        rt_kprintf("ROMFS File System initialized!\n");
    }
    else
    {
        rt_kprintf("ROMFS File System initialized Failed!\n");
    }

    // pin_test(1, 0); 

    return 0;
}
