# kribbon

设计思路
仿照C#来写界面，使用XML来描述界面

# 例子

```xml
<KRibbon version = "1.0">
	<KRibbonTab cmd="KCmdTabStart">
		<KRibbonPushButton cmd="KCmdStart" text="start" />
		<KRibbonPushButton cmd="KCmdOpen" text="open" />
		<KRibbonPushButton cmd="KCmdClose" text="close" />
	</KRibbonTabWidget>
</KRibbon>
```

<KRibbonPushButton cmd="KCmdStart" text="start" />

使用widget来表示当前的widget状态。 对应一个命令cmd。由命令来控制控制界面刷新状态。

界面上每一个控件对应一个widget，有特殊需求可以定制自己的widget。

默认水平布局

## cmd命令

可以用idle的方式刷新，Qt提供了这样的接口。使用Qt的事件循环来做

cmd应该由整个kxmainwindow来维护。需要一个主窗口的状态来维护整个cmd的声明周期

由cmd來維護widget的生命周期



## KxApplication


## KxMainWindow

## 注册事件
比如在Ribbon中注冊一個新的事件start
在 `kcmdtabstart.h`中添加一个新的类

## 声明
```cpp
class KCmdStart : public KCommand
{
	Q_OBJECT
public:
	KCmdStart(QObject *parent = nullptr, QObject* host = nullptr);

signals:

};
```

## 注册
然后在cpp文件中别忘记注册
```cpp
KCmdStart::KCmdStart(QObject *parent,  QObject* host) : KCommand(parent)
{
	setObjectName("KCmdStart");
}
REGISTER_COMMAND(KCmdStart, KxMainWindow);
```
