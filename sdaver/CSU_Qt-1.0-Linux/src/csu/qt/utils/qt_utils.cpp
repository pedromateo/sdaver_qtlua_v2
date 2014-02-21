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

#include "qt_utils.h"
#include <QFileInfo>
#include <QCoreApplication>
#include <QApplication>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocumentWriter>
#include <QStringList>
#include <iostream>
#include <fstream>
#include <sstream>
//#include <boost/lexical_cast.hpp>

namespace csu {
namespace qt{

/// ///
///
/// widget utils
///
/// ///



/// ///
///
/// directory and file utils
///
/// ///

/// returns true if it is a valid binary
bool qt_utils::isExecutable ( const QString &bin )
{
    QFileInfo fi ( bin );
    return fi.exists ()  && fi.isExecutable ();
}

///gets the directory from a full path (linux)
QString qt_utils::getDirFromPath ( const QString &s )
{
    /*only on linux*/
    int levels = s.count ( "/" );
    return s.section ( "/",0,levels-1 );
}

///gets the current directory
QString qt_utils::getCurrentDir()
{
    return getDirFromPath ( QCoreApplication::applicationFilePath () );
}

///gets the working directory
QString qt_utils::getWorkingDir()
{
    return QDir::current().absolutePath();
}

/// ///
///
/// messageBox utils
///
/// ///

//shows an OK/Cancel dialog
bool qt_utils::showOkCancelDialog( const QString &s )
{
    QMessageBox msgBox;
    msgBox.setText("Question:");
    msgBox.setInformativeText(s);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    return msgBox.exec();
}

///shows an error dialog
void qt_utils::newErrorDialog ( const QString &s )
{
    QMessageBox::critical ( 0, "Error", s, "&OK");
}

///shows an info dialog
void qt_utils::newInfoDialog ( const QString &s )
{
    QMessageBox::information(  0, "Info", s, "&OK");
}

/// ///
///
/// file dialog utils
///
/// ///

///returns the path of the selected file (open)
QString qt_utils::openFileDialog ( const QString& title,
                                   const QString& dir,
                                   const QString& ext )
{
    return QFileDialog::getOpenFileName ( 0, title,
                                          dir,
                                          ext );
}

///returns the path of the selected file (save)
QString qt_utils::saveFileDialog( const QString& title,
                                  const QString& dir,
                                  const QString& ext )
{
    return QFileDialog::getSaveFileName ( 0, title,
                                          dir,
                                          ext );
}

///returns the selected path
QString qt_utils::selectPathDialog( const QString& title,
                                    const QString& dir)
{
    return QFileDialog::getExistingDirectory (0,
                                              title,
                                              dir);
}

///returns a screenshot
bool qt_utils::saveScreenShot ( const QString & fileName, bool saveDialog )
{
    ///get the photo
    QPixmap pix = QPixmap::grabWindow ( QApplication::desktop()->winId() );

    ///save it
    QString format = "png";
    QString path = "";
    //with dialog...
    if ( saveDialog )
    {
        path = QFileDialog::getSaveFileName ( 0,
                                              "Save Screenshot...",
                                              QDir::currentPath(), "*.png" );
    }
    //or not...
    else
    {
        path = fileName;
    }
    //save it
    if ( path == "" ) return false;
    //check extension
    if ( !path.endsWith ( ".png" ) ) path = path + ".png";
    //if (!path.endsWith(format)) path = fileName + format;
    pix.save ( path, format.toAscii() );
    return true;
}


///returns a desktop screenshot
QPixmap qt_utils::getDesktopScreenShot ()
{
    ///get the photo
    QPixmap pix;
    pix = QPixmap::grabWindow ( QApplication::desktop()->winId() );
    return pix;
}

///returns a window screenshot
QPixmap qt_utils::getWindowScreenShot (int wid)
{
    ///get the photo
    QPixmap pix;
    pix = QPixmap::grabWindow ( wid );
    return pix;
}

/// returns a current window screenshot
QPixmap qt_utils::getCurrentWindowScreenShot()
{
    // update the GUI
    //QApplication::activeWindow()->update();
    //sleep(1);
    // get the photo
    QPixmap pix;
    //pix = QPixmap::grabWindow ( QApplication::activeWindow()->winId());
    pix = QPixmap::grabWidget( QApplication::activeWindow());
    return pix;
}

void qt_utils::exportToPdf(const QString& fileName,const QTextDocument * saveText)
{
    //QString fileNameAux=QFileInfo(fileName).baseName();

    QString fileNameAux=fileName;
    if (QFileInfo(fileNameAux).suffix()!="pdf")
        fileNameAux.append(".pdf");
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileNameAux);
    saveText->print(&printer);
}

bool qt_utils::exportToPlaintext(const QString& fileName,const QTextDocument * saveText)
{
    //        QString fileNameAux=QFileInfo(fileName).baseName();
    QString fileNameAux=fileName;
    if (QFileInfo(fileNameAux).suffix()!="txt")
        fileNameAux.append(".txt");
    QTextDocumentWriter writer(fileNameAux);
    writer.setFormat("plaintext");
    return writer.write(saveText);

}

bool qt_utils::exportToOdt(const QString& fileName,const QTextDocument * saveText)
{
    //        QString fileNameAux=QFileInfo(fileName).baseName();
    QString fileNameAux=fileName;
    fileNameAux.append(".odt");
    QTextDocumentWriter writer(fileNameAux);
    writer.setFormat("odf");
    return writer.write(saveText);
}

//FIXME no funciona cuando se le mete la lista de formatos
void qt_utils::exportFileDialog(const QString &title,
                                const QTextDocument * saveText,
                                const QStringList & exportFormats)
{

    const QString pdfString="PDF File (*.pdf)";
    const QString txtString="Text File (*.txt)";
    const QString odtString="ODF files (*.odt)";

    QString * possibleFormats = new QString();

    //FIXME TODO
    // It does not work if the export format list is passed as an argument
    //        if (exportFormats.size()==0)
    //        {
    //                possibleFormats->append(pdfString+";;"+txtString+";;"+odtString);
    //        }else{
    //            QStringList::const_iterator it=exportFormats.begin();
    //            for (;it!=exportFormats.end();it++)
    //            {
    //                if ((*it).toStdString()=="pdf"){
    //                    possibleFormats->append(pdfString);
    //                }else if ((*it).endsWith("txt", Qt::CaseSensitive)){
    //                    possibleFormats->append(txtString);
    //                }if ((*it).endsWith("odt", Qt::CaseSensitive)){
    //                    possibleFormats->append(odtString);
    //                }else{
    //                    std::cout<<"Unknown Format "<<(*it).toStdString()<<std::endl;
    //                    return;
    //                }
    //                possibleFormats->append(";;");
    //            }
    //        }

    //FIXME Delete this when fixed the previous TODO
    possibleFormats->append(pdfString+";;"+txtString+";;"+odtString);

    QString * selectedFilter = new QString();

    QString fileName = QFileDialog::getSaveFileName(0, title,QString(),
                                                    *possibleFormats,
                                                    selectedFilter);


    if (!fileName.isEmpty())
    {

        if (selectedFilter->endsWith("(*.pdf)", Qt::CaseSensitive))
        {
            exportToPdf(fileName,saveText);

        }else if (selectedFilter->endsWith("(*.txt)", Qt::CaseSensitive))
        {
            exportToPlaintext(fileName,saveText);
        }else if (selectedFilter->endsWith("(*.odt)", Qt::CaseSensitive))
        {
            exportToOdt(fileName,saveText);
        }
    }
}

//FIXME problemas cuando se le introduce el la lista especifica de formatos
void qt_utils::exportFileDialog(const QString &title,
                                const std::string& saveText,
                                const QStringList & exportFormats)
{
    QTextDocument * document;

    //Check if the content is html formatted
    if (saveText.find("<html")!=saveText.size()){
        //           std::cout<<"Es HTML"<<std::endl;
        document = new QTextDocument();

        document->setHtml(saveText.c_str());
    }else{
        document= new QTextDocument(saveText.c_str());
    }
    exportFileDialog(title,document,exportFormats);
}

}//qt
}//csu
