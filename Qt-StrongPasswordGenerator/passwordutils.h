#ifndef PASSWORDUTILS_H
#define PASSWORDUTILS_H

#include <QChar>
#include <QVector>
#include <QMap>



class PasswordUtils
{
public:
    PasswordUtils() = delete;
    static const QMap<int, QVector<QChar>> charTypeLists;



};

#endif // PASSWORDUTILS_H
