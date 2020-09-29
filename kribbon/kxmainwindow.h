#ifndef KXMAINWINDOW_H
#define KXMAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QMap>

class KCommand;

class KxMainWindow : public QWidget
{
	Q_OBJECT
	using CmdMap = QMap<QString, KCommand*>;
public:
	explicit KxMainWindow(QWidget *parent = nullptr);

signals:

public slots:
	void awake();
	void aboutToBlock();

private:
	QTime m_lastAwake;
	QTime m_lastBlock;

	CmdMap m_cmdMap;
};

#endif // KXMAINWINDOW_H
