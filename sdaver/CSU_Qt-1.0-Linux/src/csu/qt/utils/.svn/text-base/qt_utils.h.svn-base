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

#ifndef QT_UTILS_H
#define QT_UTILS_H

#include <QDesktopWidget>
#include <QTextDocument>

namespace csu {
namespace qt{

class qt_utils{
public:

    /// ///
    ///
    /// directory and file utils
    ///
    /// ///

    /// returns true if it is a valid binary
    static bool isExecutable ( const QString &bin );

    ///gets the directory from a full path (linux)
    static QString getDirFromPath ( const QString &s );

    ///gets the current directory
    static QString getCurrentDir();

    ///gets the working directory
    static QString getWorkingDir();

    /// ///
    ///
    /// messageBox utils
    ///
    /// ///

    //shows an OK/Cancel dialog
    static bool showOkCancelDialog( const QString &s );

    ///shows an error dialog
    static void newErrorDialog ( const QString &s );

    ///shows an info dialog
    static void newInfoDialog ( const QString &s );

    /// ///
    ///
    /// file dialog utils
    ///
    /// ///

    ///returns the path of the selected file (open)
    static QString openFileDialog ( const QString& title,
                                    const QString& dir,
                                    const QString& ext );

    ///returns the path of the selected file (save)
    static QString saveFileDialog( const QString& title,
                                   const QString& dir,
                                   const QString& ext );

    //Show a Export File Dialog with a rich text (QTextDocument)
    //Supported formats are: "pdf","txt" and "odt"
    //if exporFormats is blank, all possibles will be shown
    //FIXME no funciona cuando se le mete la lista de formatos
    static void exportFileDialog(const QString& title,
                                 const QTextDocument * saveText,
                                 const QStringList & exportFormats=QStringList());

    //Show a Export File Dialog with a raw string
    //Supported formats are: "pdf","txt" and "odt"
    //if exporFormats is blank, all possibles will be shown
    //FIXME TODO
    static void exportFileDialog(const QString &title,
                                 const std::string& saveText,
                                 const QStringList & exportFormats=QStringList());

    //Export to Pdf the content of saveText to file FileName
    static void exportToPdf(const QString& fileName,const QTextDocument * saveText);

    //Export to ODT the content of saveText to file FileName
    static bool exportToOdt(const QString& fileName,const QTextDocument * saveText);

    //Export to Plain Txt the content of saveText to file FileName
    static bool exportToPlaintext(const QString& fileName,const QTextDocument * saveText);

    ///returns the selected path
    static QString selectPathDialog( const QString& title,
                                     const QString& dir);

    ///returns a screenshot
    static bool saveScreenShot ( const QString & fileName, bool saveDialog );

    ///returns a desktop screenshot
    static QPixmap getDesktopScreenShot ();

    ///returns a window screenshot
    static QPixmap getWindowScreenShot (int wid);

    /// returns a current window screenshot
    static QPixmap getCurrentWindowScreenShot();

};//QtUtils

}//qt
}//csu

#endif //QT_UTILS_HPP
