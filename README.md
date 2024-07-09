# kcron-dll

适用于 `C` 的定时任务时间字符串解析器函数库，
参数规范与使用[EXE应用程序](https://github.com/kuyoru-kamikisho/kcron)的方式十分类似，
只不过从命令行变成了函数调用。

## 下载库函数

前往 [Release](https://github.com/kuyoru-kamikisho/kcron/releases) 页进行下载，
您也可以根据您的系统自行构建

## 函数列表

### parseTimeString

您可以通过下面的简单指引来了解如何调用库函数，
也可以查看专门编写的 [测试文件](./test/test.cpp)
来了解更详细的调用方式。

下面的代码是 `parseTimeString` 库函数的基础定义：

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

使用示例：

```c++
auto x = parseTimeString("w - - - - - - -", 10);
printf("year is %d\n",x[0].Y);
printf("year is %d\n",x[1].Y);
```

### 其它函数

其他函数的使用说明请参见 [头文件](./core//method.h)
