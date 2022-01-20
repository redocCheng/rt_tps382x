/*
 * Copyright (c) 2022, redoc
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author            Notes
 * 2022-01-27     redoc          first version
 */

#include <board.h>

#ifdef BSP_USING_TPS382X

//#define DRV_DEBUG
#define LOG_TAG             "drv.wdt"
#include <drv_log.h>

/* tsp382x timeout ms */
#ifdef BSP_TPS382X_TYPE_3820
    #define TIMEOUT_TPS382X   (200)    
#else
    #define TIMEOUT_TPS382X   (1600)   
#endif

static struct rt_watchdog_ops ops;
static rt_watchdog_t watchdog;
static rt_uint16_t is_start = 0;

static rt_err_t _tps382x_feed(void)
{
    if(0 == is_start)
    {
        rt_pin_mode(BSP_TPS382X_WDI_PIN, PIN_MODE_OUTPUT);
    }
    else
    {
        rt_pin_write(BSP_TPS382X_WDI_PIN, (!(rt_pin_read(BSP_TPS382X_WDI_PIN))));
    }  
    
    return RT_EOK;
}

static rt_err_t _tps382x_start(void)
{
    rt_pin_mode(BSP_TPS382X_WDI_PIN, PIN_MODE_OUTPUT);
    is_start = 1;
    
    return RT_EOK;
}

static rt_err_t wdt_init(rt_watchdog_t *wdt)
{
    _tps382x_start();
    
    return RT_EOK;
}

static rt_err_t wdt_control(rt_watchdog_t *wdt, int cmd, void *arg)
{
    switch (cmd)
    {
        /* feed the watchdog */
    case RT_DEVICE_CTRL_WDT_KEEPALIVE:
        _tps382x_feed();
        break;
    case RT_DEVICE_CTRL_WDT_GET_TIMEOUT:
        (*((rt_uint32_t*)arg)) = TIMEOUT_TPS382X;
        break;
    case RT_DEVICE_CTRL_WDT_START:
        _tps382x_start();
        break;
    default:
        LOG_W("This command is not supported.");
        return -RT_ERROR;
    }
    return RT_EOK;
}

int rt_drv3832_init(void)
{
    rt_pin_mode(BSP_TPS382X_WDI_PIN, PIN_MODE_INPUT);
    
    is_start = 0;
    ops.init = &wdt_init;
    ops.control = &wdt_control;
    watchdog.ops = &ops;
    
    /* register watchdog device */
    if (rt_hw_watchdog_register(&watchdog, BSP_TPS382X_DEVICE_NAME, RT_DEVICE_FLAG_DEACTIVATE, RT_NULL) != RT_EOK)
    {
        LOG_E("wdt device register failed.");
        return -RT_ERROR;
    }
    LOG_D("wdt device register success.");
    return RT_EOK;
}
INIT_BOARD_EXPORT(rt_drv3832_init);

#endif /* RT_USING_WDT */
