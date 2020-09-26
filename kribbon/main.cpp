#include "mainwindow.h"

#include <QApplication>
#include "kxmainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
//	MainWindow w;
//	w.show();

	KxMainWindow mainWindow;
	mainWindow.show();
	return a.exec();
}
