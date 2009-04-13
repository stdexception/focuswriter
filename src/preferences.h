/***********************************************************************
 *
 * Copyright (C) 2008-2009 Graeme Gott <graeme@gottcode.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
class QCheckBox;
class QPushButton;

class Preferences : public QDialog {
	Q_OBJECT
public:
	Preferences(QWidget* parent = 0);

	bool alwaysCenter() const;
	QString saveLocation() const;
	bool autoSave() const;
	bool autoAppend() const;

public slots:
	virtual void accept();

private slots:
	void changeSaveLocation();

private:
	QCheckBox* m_always_center;
	QPushButton* m_location;
	QCheckBox* m_auto_save;
	QCheckBox* m_auto_append;
};

#endif
