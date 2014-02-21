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

#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QtGui/QDialog>
#include <boost/ptr_container/ptr_list.hpp>
#include <QCheckBox>
#include <QTreeWidgetItem>
#include <map>

namespace Ui {
class CheckListDialog;
}

namespace csu{
namespace qt{
namespace dialogs{
namespace checklist{

    typedef std::map<std::string, bool> OptionMap;

    class CheckListDialog : public QDialog
    {
        Q_OBJECT
        Q_DISABLE_COPY(CheckListDialog)
    public:
        explicit CheckListDialog(OptionMap&, QWidget *parent = 0);
        virtual ~CheckListDialog();

        OptionMap & getValues();


    protected:
        virtual void changeEvent(QEvent *e);

    private:
        //Help methods
        void _deactivateEvaluatorChildren(QTreeWidgetItem * item);
        void _deactivateEvaluatorParents(QTreeWidgetItem * item);
        void _activateEvaluatorChildren(QTreeWidgetItem * item);
        void _activateEvaluatorParents(QTreeWidgetItem * item);
        void _createPath(QTreeWidgetItem * parentNode,const QString & path,const QString & delimiter,bool checked);
        Ui::CheckListDialog *m_ui;


private slots:
        void on_treeWidget_itemChanged(QTreeWidgetItem* item, int column);
};
}//
}//dialogs
}//qt
}//csu

#endif // DIALOG_H
