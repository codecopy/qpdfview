/*

Copyright 2012 Adam Reichold

This file is part of qpdfview.

qpdfview is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

qpdfview is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with qpdfview.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef FORMFIELDDIALOG_H
#define FORMFIELDDIALOG_H

#include <QtCore>
#include <QtGui>

#include <poppler-qt4.h>
#include <poppler-form.h>

class FormFieldDialog : public QDialog
{
    Q_OBJECT

public:
    FormFieldDialog(QMutex* mutex, Poppler::FormField* formField, QWidget* parent = 0);

protected:
    void showEvent(QShowEvent* event);
    void hideEvent(QHideEvent* event);

private:
    QMutex* m_mutex;
    Poppler::FormField* m_formField;

    QWidget* m_widget;

    Poppler::FormFieldText* formFieldText() const;
    Poppler::FormFieldChoice* formFieldChoice() const;

    QLineEdit* lineEdit() const;
    QPlainTextEdit* plainTextEdit() const;
    QComboBox* comboBox() const;
    QListWidget* listWidget() const;

};

#endif // FORMFIELDDIALOG_H