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

#include "ui_checklist.h"
#include "checklist.h"
#include <iostream>
#include <cassert>



namespace csu{
namespace qt{
namespace dialogs{
namespace checklist{

CheckListDialog::CheckListDialog(OptionMap& om, QWidget* parent) :
        QDialog(parent),
        m_ui(new Ui::CheckListDialog)
{
    

    m_ui->setupUi(this);

    //Filling Graphical TreeWidget info
    m_ui->treeWidget->setHeaderLabel("Available Evaluators");


    QTreeWidgetItem * root = new QTreeWidgetItem();
    root->setText(0,"All Evaluators");
    root->setText(1,"");
    root->setText(2,"parent");
    root->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );    
    root->setCheckState(0,Qt::Checked);

    m_ui->treeWidget->addTopLevelItem(root);

    //Expand the main evalution categories
    m_ui->treeWidget->expandAll();

    //Inserting the evaluators inside the tree using its path to do it
    OptionMap::iterator it = om.begin();
    it = om.begin();
    QString delimiter("::");
    while (it != om.end())
    {
        QString absoluteName(it->first.c_str());

        _createPath(root,absoluteName,delimiter,it->second);

        it++;
    }

}

//Inserting the evaluators inside the tree using its path to do it
void CheckListDialog::_createPath(QTreeWidgetItem * parentNode,const QString & absolutePath,const QString & delimiter,bool checked)
{
    QStringList path = absolutePath.split(QRegExp(delimiter));
    QStringList::iterator itPath=path.begin();
    assert(parentNode);
    for (int count=0;itPath!=path.end();itPath++,count++)
    {
        bool found=false;
        int pos;
        //Look for the child named by itPath in parentNode
        for (pos=0;pos<parentNode->childCount();pos++)
        {
            if (*itPath==parentNode->child(pos)->text(0))
            {
                found=true;
                break;
            }
        }
        if (!found){
            QTreeWidgetItem * temp = new QTreeWidgetItem();
            temp->setText(0,*itPath);                        

            temp->setText(1,"parent");

            temp->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled );

            if (checked)
                temp->setCheckState(0,Qt::Checked);
            else
                temp->setCheckState(0,Qt::Unchecked);

            parentNode->addChild(temp);
            parentNode=temp;

        }else{
            //Found
            parentNode=parentNode->child(pos);
        }
    }
    //The last element wasnt a parent node
    parentNode->setText(1,"leaf");
    parentNode->setText(2,absolutePath);
}

CheckListDialog::~CheckListDialog()
{}

// Construct the optionmap according to the checked evaluators in the tree
void _constructMap(QTreeWidgetItem * item,OptionMap * values)
{

    for (int i=0;i<item->childCount();i++)
    {
        if (item->child(i)->text(1)!="parent"){
            bool result;

            if (item->child(i)->checkState(0)==Qt::Checked)
                result=true;
            else
                result=false;
            (*values)[item->child(i)->text(2).toStdString()] = result;
        }
        _constructMap(item->child(i),values);
    }
}

// This method returns the selected evaluators represented as an OptionMap
OptionMap& CheckListDialog::getValues()
{
    OptionMap * values= new OptionMap();

    _constructMap(m_ui->treeWidget->topLevelItem(0),values);

    return *values;
}



void CheckListDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



/// //////////////////////////////
/// Help method used to work with TreeWidget
/// //////////////////////////////
void CheckListDialog::_activateEvaluatorChildren(QTreeWidgetItem * item){
    for (int i=0;i<item->childCount();i++)
    {
        item->child(i)->setCheckState(0,Qt::Checked);
        _activateEvaluatorChildren(item->child(i));
    }
}

/// //////////////////////////////
/// Help method used to work with TreeWidget
/// //////////////////////////////
void CheckListDialog::_activateEvaluatorParents(QTreeWidgetItem * item){
    if (item!=m_ui->treeWidget->topLevelItem(0))
    {
        bool state=true;
        for (int i=0;i<item->parent()->childCount();i++)
        {
            if (item->parent()->child(i)->checkState(0)==Qt::Unchecked)
            {
                state=false;
                break;
            }

        }
        if (state)
        {
            item->parent()->setCheckState(0,Qt::Checked);
            _activateEvaluatorParents(item->parent());
        }

    }

}

/// //////////////////////////////
/// Help method used to work with TreeWidget
/// //////////////////////////////
void CheckListDialog::_deactivateEvaluatorChildren(QTreeWidgetItem * item){

    for (int i=0;i<item->childCount();i++)
    {
        item->child(i)->setCheckState(0,Qt::Unchecked);
        _deactivateEvaluatorChildren(item->child(i));
    }

}

/// //////////////////////////////
/// Help method used to work with TreeWidget
/// //////////////////////////////
void CheckListDialog::_deactivateEvaluatorParents(QTreeWidgetItem * item){
    if (item!=m_ui->treeWidget->topLevelItem(0))
    {
        item->parent()->setCheckState(0,Qt::Unchecked);
        _deactivateEvaluatorParents(item->parent());
    }

}

void csu::qt::dialogs::checklist::CheckListDialog::on_treeWidget_itemChanged(QTreeWidgetItem* item, int column)
{

    m_ui->treeWidget->blockSignals(true);

   if (item->checkState(0)==Qt::Checked){
        _activateEvaluatorChildren(item);
        _activateEvaluatorParents(item);

    }else{

        _deactivateEvaluatorChildren(item);
        _deactivateEvaluatorParents(item);
    }
     m_ui->treeWidget->blockSignals(false);

}

}//
}//dialogs
}//qt
}//csu


