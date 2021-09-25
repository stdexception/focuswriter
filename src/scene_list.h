/*
	SPDX-FileCopyrightText: 2012 Graeme Gott <graeme@gottcode.org>

	SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef FOCUSWRITER_SCENE_LIST_H
#define FOCUSWRITER_SCENE_LIST_H

class Document;

#include <QFrame>
class QLineEdit;
class QListView;
class QModelIndex;
class QSortFilterProxyModel;
class QToolButton;

class SceneList : public QFrame
{
	Q_OBJECT

public:
	SceneList(QWidget* parent = 0);
	~SceneList();

	bool scenesVisible() const;

	void setDocument(Document* document);

public slots:
	void hideScenes();
	void showScenes();

protected:
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void resizeEvent(QResizeEvent* event);

private slots:
	void moveScenesDown();
	void moveScenesUp();
	void sceneSelected(const QModelIndex& index);
	void selectCurrentScene();
	void setFilter(const QString& filter);
	void toggleScenes();
	void updateShortcuts();

private:
	void moveSelectedScenes(int movement);

private:
	QAction* m_toggle_action;
	QToolButton* m_show_button;
	QListView* m_scenes;
	QLineEdit* m_filter;
	QToolButton* m_hide_button;
	QFrame* m_resizer;
	QSortFilterProxyModel* m_filter_model;
	Document* m_document;

	int m_width;
	QPoint m_mouse_current;
	bool m_resizing;
};

#endif // FOCUSWRITER_SCENE_LIST_H
