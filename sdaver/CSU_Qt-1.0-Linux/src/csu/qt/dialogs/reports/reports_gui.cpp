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
#include "reports_gui.h"
#include "ui_reports_gui.h"

#include <cassert>
#include <csu/qt/utils/qt_utils.h>

namespace csu{
namespace qt{
namespace dialogs{
namespace reports_gui{

    using namespace csu::base::ui::abstract_ui_report;

    ReportsDialog::ReportsDialog(ReportList * reportList,QWidget *parent) :
            QDialog(parent),
            ui(new Ui::ReportsDialog)
    {
        ui->setupUi(this);

        ///
        /// configure UI
        ///

        reportList_=reportList;


        /// configure report table

        ui->reportTable->setAlternatingRowColors(true);
        //Static Size
        int totalSize=this->width()-30;
        ui->reportTable->setColumnWidth(1,120);
        totalSize-=120;
        ui->reportTable->setColumnWidth(0,totalSize);
        //Set the total number of rows
        ui->reportTable->setRowCount(reportList_->size());
        // fill the rows
        ReportList::iterator it = reportList_->begin();
        for (int row=0;it!=reportList_->end();++it,++row)
        {
            ui->reportTable->setItem(row,0,new QTableWidgetItem((*it).name().c_str()));
            ui->reportTable->setItem(row,1,new QTableWidgetItem((*it).date().c_str()));
        }

        ///
        /// configure property tree

        // tree
        ui->reportTree->setVisible(false);

        ///
        QStringList treeLabels;
        treeLabels.push_back("Evaluation Report Title");
        treeLabels.push_back("Hint Type");
        treeLabels.push_back("Widget Name");
        treeLabels.push_back("Evaluator Type");

        ui->reportTree->setHeaderLabels(treeLabels);

       //Hint Column has a fixed size
        ui->reportTree->setColumnWidth(1,80);


        //FIXME Look for a way to adjust column size automatically
//                    totalSize=ui->reportTable->width();
//                    ui->reportTree->setColumnWidth(1,90);
//                    totalSize-=90;
//                    ui->reportTree->setColumnWidth(2,180);
//                    totalSize-=180;
//                    ui->reportTree->setColumnWidth(0,totalSize);

    }

    ReportsDialog::~ReportsDialog()
    {
        delete ui;
    }

    void ReportsDialog::changeEvent(QEvent *e)
    {
        QDialog::changeEvent(e);
        switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
        }
    }

    void ReportsDialog::on_showButton_clicked()
    {
        //using namespace csu::base::report;


        if (ui->reportTree->isVisible())
        {
            //Hide the tree
            ui->reportTree->setVisible(false);
            ui->showButton->setText("Show >>");

        }else
        {

            if (reportList_->size()>0){
                //Show the tree
                ui->reportTree->setVisible(true);
                ui->showButton->setText("<< Hide");
                showTree();

            }
        }
        //this->adjustSize();
    }

    void ReportsDialog::showTree(void)
    {
        ui->reportTree->clear();

        //Get the selected report from the selected row
        ReportList::iterator it=reportList_->begin();

        for(int index=0;index<ui->reportTable->currentRow();it++,index++);


        //Get report list
        AbstractUIReport::ReportList::const_iterator itrep=it->reports().begin();

        QTreeWidgetItem * rootnode= new QTreeWidgetItem();
        rootnode->setText(0,"Evaluation Report");

        //Iterate throught all reports in the report list
        for(;itrep!=it->reports().end();itrep++)
        {
            QTreeWidgetItem *parentnode = new QTreeWidgetItem();

            AbstractUIReport auxrep = (AbstractUIReport)(*itrep);

            //Assign the report name to the tree node
            parentnode->setText(0,auxrep.reportType().c_str());
            parentnode->setToolTip(0,auxrep.description().c_str());
            //Iterate throught all statements
            AbstractUIReport::StatementList::const_iterator itstat=auxrep.statements().begin();
            for (;itstat!=auxrep.statements().end();itstat++)
            {
                QTreeWidgetItem * childnode = new QTreeWidgetItem();

                //Insert the statement at the parent leaf
                AbstractUIStatement  st= ((AbstractUIStatement)*itstat);

                //First Column: statement name
                childnode->setText(0,st.description().c_str());

                //Second Column: statement Type
                childnode->setText(1,(*st.typetoString()).c_str());

                //Third Column: widget name
                childnode->setText(2,st.widgetName().c_str());
                childnode->setToolTip(2,st.widgetPath().c_str());

                //Fourth Column: evaluator type
                childnode->setText(3,st.evaluatorType().c_str());

                parentnode->addChild(childnode);

            }

            //Insert the parent node at the root node
            rootnode->addChild(parentnode);

        }


        //Assign the root node to the tree
        ui->reportTree->addTopLevelItem(rootnode);
        rootnode->setExpanded(true);
//        ui->reportTree->resizeColumnToContents(0);
//        ui->reportTree->resizeColumnToContents(1);
//        ui->reportTree->resizeColumnToContents(2);
//        ui->reportTree->resizeColumnToContents(3);
    }

    void ReportsDialog::on_reportTable_itemSelectionChanged()
    {
        if (ui->reportTree->isVisible())
        {
            showTree();

        }
    }

    void ReportsDialog::on_exportButton_clicked()
    {

        //Get the selected report from the selected row
        ReportList::iterator it=reportList_->begin();

        for(int index=0;index<ui->reportTable->currentRow();it++,index++);

        qt_utils::exportFileDialog("Export Report to",it->toHtml());

    }

    void ReportsDialog::on_reportTree_collapsed(QModelIndex index)
    {
        //AdjustSize
        ui->reportTree->resizeColumnToContents(0);
        ui->reportTree->setColumnWidth(1,80);
        ui->reportTree->resizeColumnToContents(1);
        ui->reportTree->resizeColumnToContents(2);
    }

    void ReportsDialog::on_reportTree_itemExpanded(QTreeWidgetItem* item)
    {
        //AdjustSize
        ui->reportTree->resizeColumnToContents(0);
        ui->reportTree->setColumnWidth(1,80);
        ui->reportTree->resizeColumnToContents(1);
        ui->reportTree->resizeColumnToContents(2);
    }

} //reports_gui
} //dialogs
} //qt
} //csu







