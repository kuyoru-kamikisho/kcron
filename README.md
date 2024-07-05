# kcron-dll

适用于 `C` 的定时任务时间字符串解析器函数库，
参数规范与使用[EXE应用程序](https://github.com/kuyoru-kamikisho/kcron)的方式十分类似，
只不过从命令行变成了函数调用。

## 函数

### parseTimeString

```c++
typedef struct KCronTime_C
{
	int Y;
	int M;
	int D;
	int w;
	int h;
	int m;
	int s;
} KCronTime_C;
```

```c++
extern "C" KCRON_API KCronTime_C* parseTimeString(const char* timeStr, int lineNums);
```

示例：

```c++
parseTimeString("w - - - - - - -", 10);
```