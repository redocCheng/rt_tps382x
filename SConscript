from building import *

# get current directory
cwd     = GetCurrentDir()
# The set of source files associated with this SConscript file.

src     = Glob('drv_tps382x.c')
path    = [cwd]
group   = DefineGroup('Drivers', src, depend = ['BSP_USING_TPS382X'], CPPPATH = path)

Return('group')
