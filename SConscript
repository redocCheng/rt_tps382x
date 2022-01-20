from building import *

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.

src     = Glob('drv_tps382x.c')
path    = [cwd]
group   = DefineGroup('DeviceDrivers', src, depend = ['PKG_USING_CAN_YMODEM'], CPPPATH = path)

Return('group')
