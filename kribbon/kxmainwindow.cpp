#include "kxmainwindow.h"
#include <QDebug>

#include <QAbstractEventDispatcher>

#include "kcommand/kcmdfactory.h"

#include <QPushButton>
#include <QHBoxLayout>

KxMainWindow::KxMainWindow(QWidget *parent) : QWidget(parent)
{
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QPushButton* pushBtn1 = new QPushButton(this);
	pushBtn1->setText("1");
	QPushButton* pushBtn2 = new QPushButton(this);
	pushBtn2->setText("2");
	mainLayout->addWidget(pushBtn1);
	mainLayout->addWidget(pushBtn2);
	setLayout(mainLayout);


	QAbstractEventDispatcher* dispatcher = QAbstractEventDispatcher::instance();
	connect(dispatcher, SIGNAL(awake()), SLOT(awake()));
	connect(dispatcher, SIGNAL(aboutToBlock()), SLOT(aboutToBlock()));



	//初始化所有的命令
	initCmd();

}

void KxMainWindow::initCmd()
{
	KCommand* cmd = KCmdFactory::createCommand("KCmdStart", this, this);
	qDebug()<<cmd->objectName()<<endl;
}

void KxMainWindow::awake()
{
	m_lastAwake = QTime::currentTime();
	qDebug() << "Slept for " << m_lastBlock.msecsTo(m_lastAwake) << " msec";
}

void KxMainWindow::aboutToBlock()
{
	m_lastBlock = QTime::currentTime();
	qDebug() << "Worked for " << m_lastAwake.msecsTo(m_lastBlock) << " msec";
}

