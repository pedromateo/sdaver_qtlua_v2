#ifndef TESTGENERATION_H
#define TESTGENERATION_H

#include <string>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QEvent>

class TestGeneration
{
public:

    static void GenerateWindow(int widgets, const std::string& filename){

        std::cout << "Loading base files" << std::endl;

        ///
        /// load base files

        // ---------------------------------------------------------------------
        QFile basepre("../window_pre.txt");
        if (!basepre.open(QFile::ReadOnly | QFile::Text)){
            std::cout << "ERROR Loading basepre" << std::endl;
            return;
        }
        QTextStream inpre(&basepre);
        QString basepre_string = inpre.readAll();
        std::cout << "basepre content = " << basepre_string.toStdString() << std::endl;

        // ---------------------------------------------------------------------
        QFile basecore("../window_core.txt");
        if (!basecore.open(QFile::ReadOnly | QFile::Text)){
            std::cout << "ERROR Loading basecore" << std::endl;
            return;
        }
        QTextStream incore(&basecore);
        QString basecore_string = incore.readAll();
        std::cout << "basecore content = " << basecore_string.toStdString() << std::endl;

        // ---------------------------------------------------------------------
        QFile basepost("../window_post.txt");
        if (!basepost.open(QFile::ReadOnly | QFile::Text)){
            std::cout << "ERROR Loading basepost" << std::endl;
            return;
        }
        QTextStream inpost(&basepost);
        QString basepost_string = inpost.readAll();
        std::cout << "basepost content = " << basepost_string.toStdString() << std::endl;

        ///
        /// create window file
        QFile file(filename.c_str());
        if ( file.open(QIODevice::ReadWrite))
        {
            QTextStream stream( &file );
            //
            stream << QString(basepre_string);
            //
            for (int i = 0; i < widgets; i++){
                stream << QString(basecore_string).replace("##widget##",QString::number(i)) << "\n";
            }
            //
            stream << QString(basepost_string);
        }
        file.close();

        std::cout << "done." << std::endl;
    }

    static void GenerateRulesFile(int rules, int widgets, const std::string& filename){

        std::cout << "Loading base" << std::endl;

        ///
        /// load base file
        QFile basefile("../rules_base.txt");
        if (!basefile.open(QFile::ReadOnly | QFile::Text)){
            std::cout << "ERROR Loading base" << std::endl;
            return;
        }
        QTextStream in(&basefile);
        QString base_string = in.readAll();

        std::cout << "base content = " << base_string.toStdString() << std::endl;

        ///
        /// create rules file
        QFile file(filename.c_str());
        if ( file.open(QIODevice::ReadWrite))
        {
            QTextStream stream( &file );
            for (int i = 0; i < rules; i++){
                for (int j = 0; j < widgets; j++){
                    stream << QString(base_string).replace("##rule##",QString::number(i)).replace("##widget##",QString::number(j)) << "\n";
                    //std::cout << "index = " << QString::number(i).toStdString() << std::endl;
                }
            }
        }
        file.close();

        std::cout << "done." << std::endl;
    }
};

class TestEvent : public QEvent
{
public:

    static const QEvent::Type myType = static_cast<QEvent::Type>(1000);

    TestEvent(int n) : QEvent(myType), nwidgets(n)
    {}

public:
    int nwidgets;
};

#endif // TESTGENERATION_H
