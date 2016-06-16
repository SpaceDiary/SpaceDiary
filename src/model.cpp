#include "model.h"

Model::Model():QObject()
{

}

Model::Model(QDir mainDir, QDir loadDir):QObject()
{
    this->mainDir=mainDir;

    QDir::setCurrent(loadDir.path());

    QFile fSectors("sectors.txt");
    if (fSectors.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fSectors);
        QString str;
        while (!stream.atEnd())
        {
            str = stream.readLine();
            Sector* sector = new Sector(str, this);
            sectors.append(sector);
        }
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fSectors.close();
    }

    QFile fResources("resources.txt");
    if (fResources.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fResources);
        QString str;
        while (!stream.atEnd())
        {
            str = stream.readLine();
            resources.append(str.toInt());
        }
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fResources.close();
    }

    QFile fDate("date.txt");
    if (fDate.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&fDate);
        QString str;
        while (!stream.atEnd())
        {
            str = stream.readLine();
            date.append(str.toInt());
        }
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fDate.close();
    }

}

void Model::save(QDir saveDir)
{
    QDir::setCurrent(saveDir.path());
    this->saveDate();
    this->saveResources();
    this->saveSectors();
    QDir::setCurrent(mainDir.path());
}

void Model::saveDate()
{
    QFile fDate("date.txt");
    if (fDate.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fDate);
        QString str;
        str = QString::number(date.at(0));
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(date.at(1));
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fDate.close();
    }
}

void Model::saveResources()
{
    QFile fResource("resources.txt");
    if (fResource.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fResource);
        QString str;
        str = QString::number(resources.at(0));
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(resources.at(1));
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(resources.at(2));
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        str = QString::number(resources.at(3));
        stream << str.toUpper()<<endl;
        qDebug()<<str;
        if (stream.status()!=QTextStream::Ok)
        {
            qDebug()<<"Ошибка чтения файла";
        }
        fResource.close();
    }
}

void Model::saveSectors()
{
    QFile fSectors("sectors.txt");
    if (fSectors.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&fSectors);
        QString str;
        for (int i=0; i<sectors.size(); i++)
        {
            str = sectors.at(i)->getName();
            stream << str<<endl;
            qDebug()<<str;
            if (stream.status()!=QTextStream::Ok)
            {
                qDebug()<<"Ошибка чтения файла";
            }
            sectors.at(i)->save();
        }
        fSectors.close();
    }
}

void Model::incDay()
{
    date[0]++;
}

void Model::incPeriod()
{
    date[0]=1;
    date[1]++;

    for (int i=0; i<sectors.size(); i++)
    {
        sectors.at(i)->period();
    }
}

void Model::extract(int i)
{
    resources[i]++;
}

bool Model::checkUnitName(QString name)
{
    for (int i=0; i<sectors.size(); i++)
    {
        if (sectors.at(i)->checkUnitName(name)) return true;
    }
    return false;
}




