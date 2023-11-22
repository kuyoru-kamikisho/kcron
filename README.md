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

```shell
# 活用“z”标记中的短横线！
# 在z标记中，短横线的作用是产生“每”的作用，
# 从左往右当遇到第一个不为零的值时，会将该值前面的第一个值限定为“每”标记，
# 不过 日 和 周 组合时的情况略有不同，请通过下方示例进行感受
# 后面的短横线将被换算为0值
# 这也是为什么z标记值的累加逻辑与w标记不同的原因

# 每秒执行
z - - - - - - - 

# 每到2024年的整点就执行
z 2024 - - - - - - 

# 每年1月份的整点就执行
z - 1 - - - - - 

# 每月1日执行
z - - 1 - - - - 

# 每月第二周第一日0点整执行
z - - 1 2 - - - 

# 每月第一周第一日0点整执行
z - - - 1 - - - 

# 每个小时整点执行
z - - - - 1 - - 

# 每分钟0秒执行
z - - - - - 1 - 

# 每秒执行
z - - - - - - 1 

```