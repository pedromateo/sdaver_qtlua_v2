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
 */

#include "sw_message.h"

#include <QScrollBar>
#include <QRect>

#include <QAbstractTextDocumentLayout>

namespace csu {
namespace qt {
namespace widgets {
namespace shadow_frame {

using namespace csu::qt::painters;

///
/// constructor
///

Message::Message(const std::string& message,ShadowFrame* parent,QWidget *decorated)
    : ShadowWidget(parent, decorated),textboxInited_(false)
{
    this->setObjectName(decorated->objectName()+"_Message");
    //customize the painting context
    pcontext_.backColor = QColor(112,179,248);
    pcontext_.lineColor = QColor(9,95,184);
    pcontext_.transparency = 215;
    pcontext_.penStyle = Qt::SolidLine;
    pcontext_.capStyle = Qt::RoundCap;
    pcontext_.canvas = this;
    pcontext_.region = QRect(0,0,this->width()-1,this->height()-1);

    message_.push_back(message);
}

void Message::clearMessage()
{
    message_.clear();
}

void Message::addMessage(const std::string & message)
{
    message_.push_back(message);
}

void Message::removeMessage(const std::string & message)
{
    StringList::iterator it=message_.begin();
    for (;it!=message_.end();it++)
    {
        if ((*it)==message){
            message_.erase(it);
            return;
        }
    }
}

std::string Message::toStdString()
{
    if (message_.empty())
        return "";

    StringList::iterator it=message_.begin();
    std::string result="";
    for (;it!=message_.end();it++)
    {
        result+=(*it)+"\n\n";
    }
    return result;
}

void Message::locate(void)
{
    //do not locate if textBox does not exists
    if (textBox_.get() == NULL) return;

    //First we get the point (0,0) of the decorated widget

    QWidget* topWidget = topLevelWidget();
    assert(topWidget);

    /// Then we move the decoration widget wherever we want,
    /// using the decorated widget origins point as reference
    QRect wbase_geo = topWidget->geometry();
    QPoint wdeco_point = decorated_->mapTo(topWidget,
                                           QPoint(0,0));
    QRect wdeco_geo = decorated_->geometry();
    QRect msg_geo = textBox_->geometry();

    //separation
    int sep = 2;

    bool top = true;
    bool right = true;
    int xoffset = 0;
    int yoffset = 0;

    /// calculate better position
    /*       //points
        int top_y = wdeco_point.y() - sep - msg_geo.height();
        int bottom_y = wdeco_point.y() + wdeco_geo.height() + sep + msg_geo.height();
        int left_x = wdeco_point.x() - sep - msg_geo.width();
        int right_x = wdeco_point.x() + wdeco_geo.width() + sep + msg_geo.width();

        //check top
        if (top_y >= 0) top = true;
        else if (bottom_y > wbase_geo.height()) top = true;
        else top = false;
        //check right
        if (right_x <= wbase_geo.width()) right = true;
        else if (left_x < 0) right = true;
        else right = false;
*/
    int px_above = wdeco_point.y();
    int px_below = wbase_geo.height() - (wdeco_geo.height() + wdeco_geo.y()) ;
    if (px_below > px_above) top = false;

    int px_left = wdeco_point.x();
    int px_right = wbase_geo.width() - (wdeco_geo.x() + wdeco_geo.width()) ;
    if (px_left > px_right) right = false;

    //std::cout << "top " << top << " right " << right << std::endl;

    // calculate box offset

    //if top-right
    if(top && right)
    {
        xoffset = wdeco_point.x() + wdeco_geo.width() + sep;
        yoffset = wdeco_point.y() - sep - msg_geo.height();
    }
    //else if bottom-right
    else if(!top && right)
    {
        xoffset = wdeco_point.x() + wdeco_geo.width() + sep;
        yoffset = wdeco_point.y() + wdeco_geo.height() + sep;
    }
    //else if top-left
    else if(top && !right)
    {
        xoffset = wdeco_point.x() - sep - msg_geo.width();
        yoffset = wdeco_point.y() - sep - msg_geo.height();
    }
    //else if bottom-left
    else if(!top && !right)
    {
        xoffset = wdeco_point.x() - sep - msg_geo.width();
        yoffset = wdeco_point.y() + wdeco_geo.height() + sep;
    }
    //else (top-right)
    else
    {
        xoffset = wdeco_point.x() + wdeco_geo.width() + sep;
        yoffset = wdeco_point.y() - sep;
    }

    //move( p.x() + this->width() - 1,
    //      p.y() - this->height() + 1);
    if (xoffset < 0) xoffset = 0;
    if (yoffset < 0) yoffset = 0;
    move (xoffset, yoffset);
}

///
/// paint event
///

void Message::paintEvent( QPaintEvent * event )
{

    //only create the box the first time
    if (!textboxInited_)
    {
        //fill text box
        QTextEdit* box = new QTextEdit(this);
        textBox_.reset(box);
        textBox_->resize(0,0);

        //Interpret linebreaks
        textBox_->setLineWrapMode(QTextEdit::NoWrap);

        //Text Alignment
        textBox_->setAlignment(Qt::AlignLeft|Qt::AlignHCenter);

        //Text size
        textBox_->setFontPointSize(10);

        //No scrollbars
        textBox_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBox_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        textBox_->setVisible(false);

        //Setting text
        QString text="\n";
        text.append(toStdString().c_str());
        textBox_->setText(text.trimmed());

        //Setting Color and stylesheet

        QString styleSheet="border: 2px solid "+pcontext_.lineColor.name()+";";
        styleSheet.append("border-radius: 10px;");
        styleSheet.append("background-color: rgba(92, 172, 238, 95%);");
        textBox_->setStyleSheet(styleSheet);

        QPalette p;
        QColor backColor;

        backColor=pcontext_.backColor;
        backColor.setAlpha(pcontext_.transparency);

        p.setColor(QPalette::Background, backColor);
        p.setColor(QPalette::Base, backColor);
        p.setColor(QPalette::Text, pcontext_.textColor);

        textBox_->setPalette(p);

        //Setting textbox size
        QFontMetrics fm(textBox_->font());
        QSize fsize = fm.size(0,textBox_->toPlainText());
        textBox_->resize(fsize.width()+(textBox_->document()->documentMargin()*2)+5,fsize.height());
        //Setting Message size
        resize(textBox_->geometry().width(),textBox_->geometry().height());

        textboxInited_ = true;

    }else{
        //do painting
        textBox_->setVisible(true);
    }

    //locate
    locate();
}

} //shadow_frame
} //widgets
} //qt
} //csu
