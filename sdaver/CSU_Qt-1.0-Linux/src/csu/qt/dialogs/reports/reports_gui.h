// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
 *   This program is free software; you can redistribute it and/or
 *   modify
 *   it under the terms of the GNU Lesser General Public License as
 *   published by the Free Software Foundation; either version 3.0 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *   02111-1307 USA
 *
 *   This file is part of the OHTu-Open Usability Evaluation Framework,
 *   http://sourceforge.net/projects/ohtu/
 *
 */
#ifndef REPORTS_GUI_H
#define REPORTS_GUI_H

#include <QDialog>
#include <csu/base/ui/abstract_ui_report/abs_ui_report.h>
#include <csu/base/ui/abstract_ui_report/abs_ui_statement.h>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QString>
#include <QTreeWidgetItem>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QStringList>

namespace Ui {
    class ReportsDialog;
}

namespace csu{
    namespace qt{
        namespace dialogs{
            namespace reports_gui{

                using namespace csu::base::ui::abstract_ui_report;

                typedef std::list<AbstractUIReport> ReportList;

                class ReportsDialog : public QDialog {
                    Q_OBJECT
                public:
                    explicit ReportsDialog(ReportList *,QWidget *parent = 0);
                    virtual ~ReportsDialog();
                    void showTree(void);

                protected:
                    void changeEvent(QEvent *e);

                private:
                    Ui::ReportsDialog *ui;
                    ReportList * reportList_;

                private slots:
                    void on_reportTree_collapsed(QModelIndex index);
                    void on_reportTree_itemExpanded(QTreeWidgetItem* item);
                    void on_exportButton_clicked();
                    void on_reportTable_itemSelectionChanged();
                    void on_showButton_clicked();
                };

            } //reports_gui
        } //dialogs
    } //qt
} //csu
#endif // REPORTS_GUI_H
