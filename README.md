# kcron

kcron是一个定时任务字符串解析器，它没有传统crontab那样的学习曲线，因此很容易使用。

kcron是一个控制台程序，它接收以下参数：

```text

[w] or [z] or [c] 
	Flags，represents the delay time, period interval,
	and clock scale respectively.
	After this parameter, 
	the year, month, day, week, hour, minute, 
	and second must be written in order, 
	these parameters must all be numbers.
	The flag "w" and "c" serve the same purpose, 
	just to facilitate the distinction.

[-h] or [--help] 
	Show the help info.

[-v] or [--version] 
	Show the version info.

[-l] [num] or [--list] [num] 
	Display the time after n times. 
	The default is 1. 
	The range of n is a number greater than 1.

```

## w、c标记

```shell

# 在w、c标记里面短横线并没有特殊的意义，它只是一个时间分隔符

# 立即执行，0可以使用英文短横线代替
w - - - - - - -

# 10分钟后执行，超出特定单位的部分会自动换算并向前累加
w - - - - - - 600

# 10秒后执行
w - - - - - - 10

# 1年2个小时1分10秒后执行
w 1 - - - 2 - 70

# 每隔2小时1分10秒执行一次
c - - - - 2 - 70

# 每隔1年3个月12小时执行一次
c 1 3 - - - 12 -

# 每隔45天执行一次
c - - 45 - - - -

```

## z标记

```shell

# 活用“z”标记中的短横线可以编辑出丰富的定时器！
# z标记与w标记最大的区别就是短横线的意义不同，
# 在z标记中，短横线的作用是产生 “每” 的作用，
# 这也是为什么z标记值的累加逻辑与w标记不同的原因

# 注意：+ 标识符只在z标记中会生效，代表最后一天，它只能出现在日期的位置
# 注意：+ 标识符存在的情况下星期设置将无效
# 注意：当星期与日两个参数同时不为空时，日将转换为星期几，星期将转换为第几个星期
# 注意：当使用z标记时，务必确保您的时分秒正确的使用短横线，避免出现预期外的每分每秒都会执行
# 注意：与间隔执行不同，对于超出范围的时分秒，准点执行是先设置好年月日，再从秒开始向前累加

# 每秒执行
z - - - - - - - 

# 到2024年的整点就执行
z 2024 1 1 - 0 0 0 

# 每年1月份的整点就执行
z - 1 1 - 0 0 0 

# 每月1日执行
z - - 1 - 0 0 0 

# 每月第二周周一执行
z - - 1 2 0 0 0 

# 每周一执行，因为限定了星期，所以日会被隐式限定
z - - - 1 0 0 0 

# 每天1点执行
z - - - - 1 0 0 

# 每小时1分执行
z - - - - - 1 0 

# 每分钟的第1秒执行
z - - - - - - 1 

# 每周四下午14点32分执行
z - - - 4 14 32 0

# 每月第三个星期四的每小时都执行
z - - 4 3 - 0 0

# 每月最后一天执行
z - - + - 0 0 0

```
