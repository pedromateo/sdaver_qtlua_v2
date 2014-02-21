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
#ifndef USECASEDESIGNER_H
#define USECASEDESIGNER_H

#include <QDialog>
#include <QTreeWidgetItem>

//Use Case classes
#include <csu/base/usecases/use_case.h>
#include <csu/base/usecases/use_case_stage.h>
#include <csu/base/usecases/use_case_stage_item.h>


//Painting classes
#include <csu/qt/widgets/shadow_widget/shadowframe.h>
#include <csu/qt/painters/rectangle.h>


namespace Ui {
    class UseCaseDesigner;
}

namespace csu {
namespace qt {
namespace dialog {
namespace usecasedesigner {

    using namespace csu::base::usecases;
    using namespace csu::qt::widgets::shadow_frame;

class UseCaseDesigner : public QDialog {
    Q_OBJECT
public:

    UseCaseDesigner(QWidget *parent = 0);
    void selectWidget(QWidget * w);
    ~UseCaseDesigner();

    const UseCaseList * useCaseList();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::UseCaseDesigner *ui;

    UseCaseList * useCaseList_;
    UseCase * temporalUseCase_;
    UseCaseStage * temporalStage_;
    bool editing_;    
    bool editingStage_;
    bool newelement_;
    QTreeWidgetItem * selectedItem_;
    ShadowFrame * shadow_;


private:
    UseCase * _getUseCase(const std::string &);
    void _editing(bool v);
    bool _editing();
    bool _editingStage(bool v);
    bool _editingStage();

    ///
    /// This method update the widget table that are used in a particular stage
    /// and also paint them at the painting frame
    ///
    void _updateStageItemTable(UseCaseStage *stage=0);
    void _initializeDefValues();

private slots:    

    ///
    /// Method that removes use case stages
    ///
    void on_deleteStageButton_clicked();

    ///
    /// Method that start/cancel the edition of a single use case stage
    ///
    void on_editcancelStageButton_clicked();

    ///
    /// Method to manage the creation and saving of use case stages
    ///
    void on_newsaveStageButton_clicked();

    ///
    /// Method to delete a single use case
    ///
    void on_deleteUseCaseButton_clicked();
    void on_usecaseTree_itemClicked(QTreeWidgetItem* item, int column);

    ///
    /// Method that start/cancel the edition of a single use case
    ///
    void on_editcancelUseCaseButton_clicked();
    void on_closeDialogButton_clicked();

    ///
    /// Method to manage the creation and saving of use cases
    ///
    void on_newsaveUseCaseButton_clicked();




};

}
}
}
}

#endif // USECASEDESIGNER_H
