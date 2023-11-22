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

## 参数示例

```shell

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

# 在每年4月份第二个星期每天的12点执行一次，与间隔执行不同，对于超出范围的时分秒，准点执行是先设置好年月日，再从秒开始向前累加
z - 4 - 2 12 - -

# 在每年4月份第二个星期一的12点执行一次，当星期与日两个参数同时不为0时，日将转换为星期几，星期将转换为第几个星期
z - 4 1 2 12 - -

# 每小时的第10分钟执行一次
z - - - - - - 600

# 每小时的第10分钟执行一次
z - - - - - 10 -

```