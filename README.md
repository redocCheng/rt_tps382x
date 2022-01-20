# rt_tps382x

## 介绍

本软件包是外部独立看门狗芯片tps382x的驱动。

##  支持情况
| 包含设备     | 看门狗 |
| ------------ | ------ |
| **通信接口** |        |
| GPIO         | √      |
| **功能**     |        |
| 喂狗         | √      |
| 获取喂狗时间 | √      |
| **控制模式** |        |
| 不支持暂停   | √      |
| 支持暂停     |        |


##  许可证

rt_tps382x package 遵循 Apache-2.0 许可，详见 `LICENSE` 文件。

## 依赖

- RT-Thread 3.0.0+
- watchdog框架组件
- pin驱动


## 获取软件包

使用 can_ymodem package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```shell
RT-Thread online packages
    peripheral libraries and drivers --->
        [*] TPS382X:TPS382X Independent watchdog 
        (22)  tps382x wdi pin number                                                          
		(wdt) tps382x wdt device name                                                         
		Select tps382x type (TPS3823/4/8)  --->                                            
                   Version (v1.0.0)  --->
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。


## 设置参数

### WDI引脚：
`BSP_TPS382X_WDI_PIN`  可通过 menuconfig 中的 `(22)  tps382x wdi pin number ` 选项设置。

### 设备名称：
`BSP_TPS382X_DEVICE_NAME`  可通过 menuconfig 中的 `(wdt) tps382x wdt device name` 选项设置。

### 芯片选择：
可通过 menuconfig 中的 `Select tps382x type (TPS3823/4/8)` 选项设置tps3820、tps3823、tps3824、tps3828。


## 注意事项

暂无


## 联系方式 & 感谢

* 维护：redoccheng
* 主页：<https://github.com/redocCheng/rt_tps382x>
* 邮箱：<619675912@qq.com>
