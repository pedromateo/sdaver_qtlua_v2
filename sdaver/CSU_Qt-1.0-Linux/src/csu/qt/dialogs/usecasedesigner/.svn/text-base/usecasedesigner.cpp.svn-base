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

#include "usecasedesigner.h"
#include "ui_usecasedesigner.h"


#include <boost/lexical_cast.hpp>
#include <cassert>


#include <csu/qt/utils/qt_utils.h>


namespace csu {
namespace qt {
namespace dialog {
namespace usecasedesigner {


using namespace csu::qt::widgets::shadow_frame;

UseCaseDesigner::UseCaseDesigner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UseCaseDesigner)
{
    ui->setupUi(this);

    //FIXME Watch this, it's a bit tricky and im not sure about its behaviour in some situations
    //Positioning windows in the screen
    parent->move(QPoint(0,0));
    this->move(QPoint(parent->width()+5,0));

    shadow_=new ShadowFrame(parent,0,0,true);
    useCaseList_= new UseCaseList();

    _initializeDefValues();

}


UseCaseDesigner::~UseCaseDesigner()
{
    delete ui;
}

void UseCaseDesigner::_initializeDefValues(){
    //Initial Default Values
    ui->usecaseDescEdit->setAcceptRichText(false);
    _editing(false);
    _editingStage(false);
    selectedItem_=NULL;
    temporalStage_=NULL;
    temporalUseCase_=NULL;
    ui->deleteUseCaseButton->setEnabled(false);
    ui->informationToolBox->setCurrentIndex(0);
}


void UseCaseDesigner::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

const UseCaseList * UseCaseDesigner::useCaseList()
{
    return useCaseList_;
}

///
/// Method to manage the creation and saving of use cases
///
void UseCaseDesigner::on_newsaveUseCaseButton_clicked()
{

    ///Cant delete a use case if the dialog is in new or edit stage
    //Disable delete button
    ui->deleteUseCaseButton->setEnabled(false);


    if (_editing())
    {
        //Saving
        std::string usecasename=ui->usecaseNameEdit->text().toStdString();
        std::string usecasedesc=ui->usecaseDescEdit->document()->toPlainText().toStdString();

        //New Use case case
        if (newelement_)
        {
            //There cant be any other use case with the same name
            if (_getUseCase(usecasename)==NULL){
                //Save Values
                temporalUseCase_->name(usecasename);
                temporalUseCase_->description(usecasedesc);

                //Update data structures
                this->useCaseList_->push_back(temporalUseCase_);

                //Update Graphical Widgets
                QTreeWidgetItem * newUseCase = new QTreeWidgetItem();
                newUseCase->setText(0,ui->usecaseNameEdit->text());

                ui->usecaseTree->addTopLevelItem(newUseCase);
                //newUseCase->setSelected(true);
                on_usecaseTree_itemClicked(newUseCase,0);


            }else{
                //There is another use case with the same
                csu::qt::qt_utils::newErrorDialog("There is another Use Case with the same name.");
                _editing(false);
                return;
            }
        }else{
            //It is an update of a created Use Case
            UseCase * storedUseCase=_getUseCase(selectedItem_->text(0).toStdString());
            UseCase * temp=_getUseCase(usecasename);

            //check if there is another stored use case with the same name
            if ((!temp) || (temp==storedUseCase)){
                storedUseCase->name(usecasename);
                storedUseCase->description(usecasedesc);
                selectedItem_->setText(0,ui->usecaseNameEdit->text());
            }else{
                //Show error
                csu::qt::qt_utils::newErrorDialog("There is another Use Case with the same name.");

            }


        }

        _editing(false);

    }else{
        //Change from new to save state
        newelement_=true;
        QString name("UseCase");

        name.append((boost::lexical_cast<std::string>(ui->usecaseTree->topLevelItemCount()+1)).c_str());

        temporalUseCase_=new UseCase(name.toStdString());

        assert(temporalUseCase_);

        selectedItem_=NULL;


        //Update Graphical Widgets (Line Edits) and give them the focus
        ui->usecaseNameEdit->setText(name);
        ui->usecaseNameEdit->selectAll();
        ui->usecaseDescEdit->clear();
        ui->usecaseNameEdit->setFocus();
        _editing(true);
    }


}

///
/// Method that start/cancel the edition of a single use case
///
void UseCaseDesigner::on_editcancelUseCaseButton_clicked()
{

    //Disable delete button
    ui->deleteUseCaseButton->setEnabled(false);


    if (ui->usecaseTree->indexOfTopLevelItem(selectedItem_)!=-1)
        _editing()?_editing(false):_editing(true);

}


void UseCaseDesigner::on_closeDialogButton_clicked()
{
    this->close();
    shadow_->clear();
}

///
/// Method to delete a single use case
///
void UseCaseDesigner::on_deleteUseCaseButton_clicked()
{
    //Cant delete if editing stage
    if (!_editing() && selectedItem_)
    {
        UseCase * temp =_getUseCase(selectedItem_->text(0).toStdString());
        if (!temp)
            return;

        this->useCaseList_->remove(temp);
        ui->usecaseTree->takeTopLevelItem(ui->usecaseTree->indexOfTopLevelItem(selectedItem_));

        //Now that the current item has been delete, a new one has to be chosen to be selected
        if (ui->usecaseTree->topLevelItemCount()!=0)
        {
            selectedItem_=ui->usecaseTree->selectedItems().first();
            temp =_getUseCase(selectedItem_->text(0).toStdString());
            ui->usecaseNameEdit->setText(temp->name().c_str());
            ui->usecaseDescEdit->setDocument(new QTextDocument(temp->description().c_str()));
        }else{
            //There are no more items inside the tree
            selectedItem_=NULL;
            ui->deleteUseCaseButton->setEnabled(false);
            ui->usecaseNameEdit->clear();
            ui->usecaseDescEdit->clear();
        }


    }

}

void UseCaseDesigner::on_usecaseTree_itemClicked(QTreeWidgetItem* item, int column)
{

    ui->usecaseTree->setCurrentItem(item);

    _editing(false);
    _editingStage(false);

    //It is a use case
    if (ui->usecaseTree->indexOfTopLevelItem(item)!=-1)
    {

        //Get the Use Case related to the item clicked
        UseCase * aux=_getUseCase(item->text(column).toStdString());

        //Due to the fact that it is selected, it can be also deleted
        ui->deleteUseCaseButton->setEnabled(true);


        if (!aux)
            return;

        //Update graphical widgets with the selected use case values
        ui->usecaseNameEdit->setText(aux->name().c_str());
        ui->usecaseDescEdit->setDocument(new QTextDocument(aux->description().c_str()));
        ui->informationToolBox->setCurrentIndex(0);

        //Clear stage tool page
        ui->stageNameEdit->clear();
        ui->longDescStageEdit->clear();
        ui->shortDescStageEdit->clear();
        ui->stageItemTable->clear();
        ui->deleteStageButton->setEnabled(false);

    }else{


        UseCase * aux=_getUseCase(item->parent()->text(column).toStdString());

        UseCaseStage * stage=aux->stage(item->text(column).toStdString());

        //Update graphical widgets with the selected use case values
        ui->stageNameEdit->setText(stage->name().c_str());
        ui->shortDescStageEdit->setText(stage->shortDesc().c_str());
        ui->longDescStageEdit->setText(stage->longDesc().c_str());
        _updateStageItemTable(stage);
        ui->informationToolBox->setCurrentIndex(1);

        //Due to the fact that it is selected, it can be also deleted
        ui->deleteStageButton->setEnabled(true);


        //Clear use case tool page
        ui->usecaseNameEdit->clear();
        ui->usecaseDescEdit->clear();
        ui->deleteUseCaseButton->setEnabled(false);
    }

    selectedItem_=item;
}

///
/// Method to manage the creation and saving of use case stages
///
void UseCaseDesigner::on_newsaveStageButton_clicked()
{



    if (_editingStage())
    {

        QTreeWidgetItem * selectedUseCase;
        //Check if the actual selected item is a stage or a use case
        if (ui->usecaseTree->indexOfTopLevelItem(selectedItem_)!=-1)
        {
            selectedUseCase=selectedItem_;

        }else{
            //currentUseCase = _getUseCase(selectedItem_->parent()->text(0).toStdString());
            selectedUseCase=selectedItem_->parent();
        }

        //Saving
        std::string stagename=ui->stageNameEdit->text().toStdString();
        UseCase * currentUseCase = _getUseCase(selectedUseCase->text(0).toStdString());

        //New Use case stage
        if (newelement_)
        {
            if (currentUseCase->stage(stagename)!=NULL)
            {
                //Salta un error cuando se utiliza el dialogo
                _editingStage(false);
                csu::qt::qt_utils::newErrorDialog("There is another Stage with the same name.");
                return;
            }

            //Save Values
            temporalStage_->name(stagename);
            temporalStage_->shortDesc(ui->shortDescStageEdit->text().toStdString());
            temporalStage_->longDesc(ui->longDescStageEdit->document()->toPlainText().toStdString());


            //Update data structures
            currentUseCase->addUseCaseStage(temporalStage_);


            //Update Graphical Information

            QTreeWidgetItem * aux = new QTreeWidgetItem();
            aux->setText(0,stagename.c_str());
            selectedUseCase->addChild(aux);
            ui->usecaseTree->collapseAll();
            ui->usecaseTree->expandItem(selectedUseCase);

            on_usecaseTree_itemClicked(aux,0);

        }else{
            //It is an update of a created Use Case Stage

            //Get the stage with the old name
            UseCaseStage * storedStage=currentUseCase->stage(selectedItem_->text(0).toStdString());
            UseCaseStage * modStage = NULL;

            //change the stage name
            if ((stagename!=selectedItem_->text(0).toStdString()))
            {
                modStage=currentUseCase->stage(stagename);
            }


            //check if there is another stored use stage case with the same name
            if (modStage!=NULL){
                //First of all close de editing stage
                _editingStage(false);
                //Show error
                csu::qt::qt_utils::newErrorDialog("There is another Stage with the same name.");
                return;
            }else{

                storedStage->name(stagename);
                storedStage->shortDesc(ui->shortDescStageEdit->text().toStdString());
                storedStage->longDesc(ui->longDescStageEdit->document()->toPlainText().toStdString());

                //Update graphical information
                selectedItem_->setText(0,stagename.c_str());
            }

        }

        _editingStage(false);

    }else{

        newelement_=true;

        //Change from new to save
        _editingStage(true);
        QString name("Stage");

        temporalStage_=new UseCaseStage(name.toStdString());

        assert(temporalStage_);


        //Update Graphical Widgets Line Edit and give them the focus
        ui->shortDescStageEdit->clear();
        ui->longDescStageEdit->clear();
        ui->stageNameEdit->setText(name);
        ui->stageNameEdit->setFocus();
        _updateStageItemTable(temporalStage_);
    }

}

///
/// Method that start/cancel the edition of a single use case stage
///
void UseCaseDesigner::on_editcancelStageButton_clicked()
{
    _editingStage()?_editingStage(false):_editingStage(true);

    if (!_editingStage())
    {
        //If !editiginStage means Cancel command
        _updateStageItemTable();
        ui->stageNameEdit->clear();
        ui->shortDescStageEdit->clear();
        ui->longDescStageEdit->clear();
    }
}

///
/// Method that removes use case stages
///
void UseCaseDesigner::on_deleteStageButton_clicked()
{

    //Check if selected item is a use case stage one
    if (ui->usecaseTree->indexOfTopLevelItem(selectedItem_)!=-1)
    {
        ui->deleteStageButton->setEnabled(false);
        return;
    }

    QTreeWidgetItem * usecase = selectedItem_->parent();

    UseCase * currentUseCase = _getUseCase(usecase->text(0).toStdString());

    currentUseCase->removeUseCaseStage(selectedItem_->text(0).toStdString());
    usecase->removeChild(selectedItem_);

    on_usecaseTree_itemClicked(usecase,0);
}



UseCase * UseCaseDesigner::_getUseCase(const std::string & usecaseName)
{

    UseCaseList::iterator it=useCaseList_->begin();

    for (;it!=useCaseList_->end();it++)
    {
        if ((*it)->name()==usecaseName)
            return (*it);
    }

    return NULL;

}

void UseCaseDesigner::_editing(bool v)
{

    if (v){
        ui->newsaveUseCaseButton->setText("Save");
        ui->editcancelUseCaseButton->setText("Cancel");
        ui->usecaseDescEdit->setReadOnly(false);
        ui->usecaseNameEdit->setReadOnly(false);
        ui->usecaseDescEdit->setFocus();


    }else{
        ui->newsaveUseCaseButton->setText("New");
        ui->editcancelUseCaseButton->setText("Edit");
        ui->usecaseDescEdit->setReadOnly(true);
        ui->usecaseNameEdit->setReadOnly(true);
        temporalUseCase_=NULL;
        newelement_=false;
    }
    editing_=v;
}

bool UseCaseDesigner::_editingStage(bool v)
{

    if (v){
        ui->newsaveStageButton->setText("Save Stage");
        ui->editcancelStageButton->setText("Cancel");
        ui->deleteStageButton->setEnabled(false);
        ui->stageNameEdit->setReadOnly(false);
        ui->shortDescStageEdit->setReadOnly(false);
        ui->longDescStageEdit->setReadOnly(false);
        ui->stageNameEdit->setFocus();

    }else{
        ui->newsaveStageButton->setText("New Stage");
        ui->editcancelStageButton->setText("Edit Stage");
        ui->stageNameEdit->setReadOnly(true);
        ui->deleteStageButton->setEnabled(true);
        ui->shortDescStageEdit->setReadOnly(true);
        ui->longDescStageEdit->setReadOnly(true);
        newelement_=false;
    }

    editingStage_=v;

    return editingStage_;
}

bool UseCaseDesigner::_editing()
{
    return editing_;
}

bool UseCaseDesigner::_editingStage()
{
    return editingStage_;
}

///
/// This method update the widget table that are used in a particular stage
/// and also paint them at the painting frame
///
void UseCaseDesigner::_updateStageItemTable(UseCaseStage * stage)
{
    ui->stageItemTable->clear();
    ui->stageItemTable->setRowCount(0);

    shadow_->clear();

    //Used to Clear the stage item table
    if (!stage)
        return;

    UseCaseStageItemList::const_iterator it=stage->getUseCaseStageItems().begin();

    for (;it!=stage->getUseCaseStageItems().end();it++)
    {
        ui->stageItemTable->setRowCount(ui->stageItemTable->rowCount()+1);
        ui->stageItemTable->setItem(ui->stageItemTable->rowCount()-1,0,new QTableWidgetItem((*it)->name().c_str()));

        Figure::PaintingContext * context= new Figure::PaintingContext();
        context->lineColor=Qt::blue;
        context->lineWidth=2;

        Rectangle * r = new Rectangle((*it)->x(),(*it)->y(),(*it)->width(),(*it)->height(),context);
        shadow_->paintFigure((*it)->name(),r);
    }
}

//This method paint/erase a concrete widget in an auxiliar hidden frame
void UseCaseDesigner::selectWidget(QWidget * w)
{

    if (_editingStage() && temporalStage_){

        assert(shadow_);

        QList<QTableWidgetItem *> wlist=ui->stageItemTable->findItems(w->objectName(),Qt::MatchExactly);

        if (wlist.count()==0)
        {

            Figure::PaintingContext * context= new Figure::PaintingContext();
            context->lineColor=Qt::blue;
            context->lineWidth=2;

            Rectangle * r = new Rectangle(w->mapTo(this->parentWidget(),shadow_->pos()).x(),
                                          w->mapTo(this->parentWidget(),shadow_->pos()).y(),
                                          w->width(),
                                          w->height(),context);

            shadow_->paintFigure(w->objectName().toStdString(),r);

            ui->stageItemTable->setRowCount(ui->stageItemTable->rowCount()+1);

            ui->stageItemTable->setItem(ui->stageItemTable->rowCount()-1,0,new QTableWidgetItem(w->objectName()));


            UseCaseStageItem* aux = new UseCaseStageItem(w->objectName().toStdString(),
                                                         w->objectName().toStdString(),//change overcomming
                                                         w->mapTo(this->parentWidget(),shadow_->pos()).x(),
                                                         w->mapTo(this->parentWidget(),shadow_->pos()).y(),
                                                         w->width(),
                                                         w->height());
            temporalStage_->addUseCaseStageItem(aux);
        }else{

            ui->stageItemTable->removeRow(wlist.first()->row());
            shadow_->removeFigure(w->objectName().toStdString());

        }
    }
}

}
}
}
}




















