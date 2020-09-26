#ifndef KXMAINWINDOW_H
#define KXMAINWINDOW_H

#include <QMainWindow>
#include <QTime>

class KxMainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit KxMainWindow(QWidget *parent = nullptr);

signals:

public slots:
	void awake();
	void aboutToBlock();

private:
	QTime m_lastAwake;
	QTime m_lastBlock;
};

#endif // KXMAINWINDOW_H
