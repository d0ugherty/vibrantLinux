#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <QStringList>
#include <QHash>
#include <QListWidget>

//#include <vibrant/vibrant.h>

#undef Bool
#undef CursorShape
#undef Expose
#undef KeyPress
#undef KeyRelease
#undef FocusIn
#undef FocusOut
#undef FontChange
#undef None
#undef Status
#undef Unsorted

#include "procscanner.h"

class displayManager{
public:
	displayManager();
	~displayManager();

	QStringList getDisplayNames();
	int getDisplaySaturation(const QString& name);

	void updateSaturation(QListWidget* watchlist);

	void checkWindowFocus(bool use);
	bool isCheckingWindowFocus();

	//creates or updates an entry in the watchlist
	void setDefaultDisplaySaturation(const QString& name, int value);

private:
	struct controller{
		vibrant_controller *v_controller;
		int defaultSaturation;
	};

	vibrant_instance *instance;
	vibrant_controller *controllers_arr;
	size_t controllers_size;
	procScanner scanner;

	QStringList displays;
	QHash<QString, controller> controllers;
};

#endif // DISPLAYMANAGER_H
