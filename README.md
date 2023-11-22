# kcron

kcron��һ����ʱ�����ַ�������������û�д�ͳcrontab������ѧϰ���ߣ���˺�����ʹ�á�

kcron��һ������̨�������������²�����

```text

[w] or [z] or [c] 
	Flags��represents the delay time, period interval,
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

## ����ʾ��

```shell

# ����ִ�У�0����ʹ��Ӣ�Ķ̺��ߴ���
w - - - - - - -

# 10���Ӻ�ִ�У������ض���λ�Ĳ��ֻ��Զ����㲢��ǰ�ۼ�
w - - - - - - 600

# 10���ִ��
w - - - - - - 10

# 1��2��Сʱ1��10���ִ��
w 1 - - - 2 - 70

# ÿ��2Сʱ1��10��ִ��һ��
c - - - - 2 - 70

# ÿ��1��3����12Сʱִ��һ��
c 1 3 - - - 12 -

# ��ÿ��4�·ݵڶ�������ÿ���12��ִ��һ�Σ�����ִ�в�ͬ�����ڳ�����Χ��ʱ���룬׼��ִ���������ú������գ��ٴ��뿪ʼ��ǰ�ۼ�
z - 4 - 2 12 - -

# ��ÿ��4�·ݵڶ�������һ��12��ִ��һ�Σ�������������������ͬʱ��Ϊ0ʱ���ս�ת��Ϊ���ڼ������ڽ�ת��Ϊ�ڼ�������
z - 4 1 2 12 - -

# ÿСʱ�ĵ�10����ִ��һ��
z - - - - - - 600

# ÿСʱ�ĵ�10����ִ��һ��
z - - - - - 10 -

```