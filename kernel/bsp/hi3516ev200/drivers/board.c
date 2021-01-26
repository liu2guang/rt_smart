/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "rtthread.h"
#include "rtdevice.h"
#include "rthw.h"
#include "board.h"

#include <mmu.h>
#ifdef RT_USING_USERSPACE
#include <page.h>
#include <lwp_arch.h>
#endif

#ifdef RT_USING_USERSPACE
struct mem_desc platform_mem_desc[] = {
    {KERNEL_VADDR_START, KERNEL_VADDR_START + 0x03FFFFFF, KERNEL_VADDR_START + PV_OFFSET, NORMAL_MEM}
};
#else
/* Hi3516EV200 19页 地址空间引射表 */ 
struct mem_desc platform_mem_desc[] = {
    {0x00000000, 0x14FFFFFF, 0x00000000, DEVICE_MEM},  /* SYS */ 
    {0x40000000, 0x43FFFFFF, 0x40000000, NORMAL_MEM}   /* DDR2 512Mb(64MB)  */ 
};
#endif

const rt_uint32_t platform_mem_desc_size = sizeof(platform_mem_desc)/sizeof(platform_mem_desc[0]);

static void reboot(void)
{
    hi3516e_clock_reset();
}
MSH_CMD_EXPORT_ALIAS(reboot, reboot, reboot hi3516ev200 system.);

rt_mmu_info mmu_info;

extern size_t MMUTable[];

#ifdef RT_USING_USERSPACE
rt_region_t init_page_region = 
{
    (uint32_t)PAGE_START,
    (uint32_t)PAGE_END,
};
#endif

void rt_hw_board_init(void)
{
#ifdef RT_USING_USERSPACE
    rt_hw_mmu_map_init(&mmu_info, (void*)0xf0000000, 0x10000000, MMUTable, PV_OFFSET);

    rt_page_init(init_page_region);
    rt_hw_mmu_ioremap_init(&mmu_info, (void*)0xf0000000, 0x10000000);

    arch_kuser_init(&mmu_info, (void*)0xffff0000);
#else
    rt_hw_mmu_map_init(&mmu_info, (void*)0x80000000, 0x10000000, MMUTable, 0);
    rt_hw_mmu_ioremap_init(&mmu_info, (void*)0x80000000, 0x10000000);
#endif

    /* initialize interrupts */
    rt_hw_interrupt_init();

    /* initialize PLLs and the clock tree */
    hi3516e_clock_init(); 

    // /* initialize pin */
    // extern int rt_hw_pin_init(void); 
    // rt_hw_pin_init(); 

#if defined(BSP_USING_UART0) || defined(BSP_USING_UART1) || defined(BSP_USING_UART2)
    /* init hardware interrupt */
    rt_hw_uart_init();
#endif

#ifdef RT_USING_HEAP
    /* init memory system */
    // rt_kprintf("head start: 0x%08x, head end: 0x%08x.\n", (rt_uint32_t)HEAP_BEGIN, (rt_uint32_t)HEAP_END);
    rt_system_heap_init(HEAP_BEGIN, HEAP_END);
#endif

#ifdef RT_USING_CONSOLE
    /* set console device */
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif /* RT_USING_CONSOLE */

#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
}
