/*
	SPDX-FileCopyrightText: 2010-2020 Graeme Gott <graeme@gottcode.org>

	SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef FOCUSWRITER_ALERT_H
#define FOCUSWRITER_ALERT_H

#include <QWidget>
class QGraphicsOpacityEffect;
class QLabel;
class QTimeLine;
class QToolButton;

class Alert : public QWidget
{
	Q_OBJECT

public:
	enum Icon {
		NoIcon = 0,
		Information,
		Warning,
		Critical,
		Question
	};

	Alert(QWidget* parent = 0);
	Alert(Icon icon, const QString& text, const QStringList& details, bool expandable, QWidget* parent = 0);

	bool underMouse() const;

	void fadeIn();
	void setExpandable(bool expandable);
	void setIcon(Icon icon);
	void setIcon(const QPixmap& pixmap);
	void setText(const QString& text, const QStringList& details);

	bool eventFilter(QObject* watched, QEvent* event);

protected:
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
	void enterEvent(QEnterEvent* event);
#else
	void enterEvent(QEvent* event);
#endif
	void leaveEvent(QEvent* event);
	void paintEvent(QPaintEvent* event);

private slots:
	void expanderToggled();
	void fadeInFinished();
	void fadeOut();

private:
	void init();

private:
	QToolButton* m_expander;
	QLabel* m_pixmap;
	QLabel* m_text;
	QString m_short_text;
	QString m_long_text;
	QTimeLine* m_fade_timer;
	QGraphicsOpacityEffect* m_fade_effect;
	bool m_expanded;
	bool m_always_expanded;
	bool m_under_mouse;
};

inline bool Alert::underMouse() const
{
	return m_under_mouse;
}

#endif // FOCUSWRITER_ALERT_H
