/*
   DrawPile - a collaborative drawing program.

   Copyright (C) 2006 Calle Laakkonen

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tools.h"

class QActionGroup;
class QMessageBox;

namespace widgets {
	class NetStatus;
	class HostLabel;
	class EditorView;
	class DualColorButton;
	class ToolSettings;
}
namespace dialogs {
	class ColorDialog;
}
namespace drawingboard {
	class Board;
}
class Controller;

//! The application main window
class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow();

	public slots:
		//! Save current document
		void save();
		//! Save current document with a new name
		void saveas();
		//! Zoom in
		void zoomin();
		//! Zoom out
		void zoomout();
		//! Reset to 1:1 zoom
		void zoomone();
		//! Change current tool
		void selectTool(QAction *tool);
		//! Display about dialog
		void about();
		//! Display online help
		void help();
		//! Go to drawpile homepage
		void homepage();

	signals:
		//! This signal is emitted when the current tool is changed
		void toolChanged(tools::Type);

	protected:
		//! Handle closing of the main window
		void closeEvent(QCloseEvent *event);

	private:
		//! Display the "error while saving" message box
		void showSaveErrorMessage();

		//! Read settings from file/registry
		void readSettings();
		//! Write settings to file/reqistry
		void writeSettings();

		//! Initialise QActions
		void initActions();
		//! Create menus
		void createMenus();
		//! Create toolbars
		void createToolbars();
		//! Create all dock windows
		void createDocks();
		//! Create tool settings dock
		void createToolSettings(QMenu *menu);

		widgets::ToolSettings *toolsettings_;
		widgets::DualColorButton *fgbgcolor_;
		widgets::NetStatus *netstatus_;
		widgets::HostLabel *hostaddress_;
		widgets::EditorView *view_;
		dialogs::ColorDialog *fgdialog_,*bgdialog_;
		QDialog *aboutdlg_;
		QMessageBox *msgbox_;
		drawingboard::Board *board_;
		Controller *controller_;

		QString filename_;
		QString lastpath_;

		QAction *save_;
		QAction *saveas_;
		QAction *quit_;

		QAction *host_;
		QAction *join_;
		QAction *logout_;

		QActionGroup *adminTools_;
		QAction *lockboard_;
		QAction *lockuser_;
		QAction *kickuser_;

		QActionGroup *drawingtools_;
		QAction *brushtool_;
		QAction *erasertool_;
		QAction *pickertool_;
		QAction *zoomin_;
		QAction *zoomout_;
		QAction *zoomorig_;

		QAction *toggleoutline_;
		QAction *togglecrosshair_;

		QAction *toolbartoggles_;
		QAction *docktoggles_;

		QAction *help_;
		QAction *homepage_;
		QAction *about_;
};

#endif

