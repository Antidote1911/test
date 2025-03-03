#ifndef ADAPTER_H
#define ADAPTER_H

#include <QFileDialog>
#include <QString>
#include <fstream>
#include "mainwindow.h"

// rust functions
extern "C" char* get_version();
extern "C" char* get_random(int);



#endif // ADAPTER_H
