#ifndef ADAPTER_H
#define ADAPTER_H

#include <QFileDialog>
#include <QString>

// rust functions
extern "C" char* get_version();
extern "C" char* get_random(int);
extern "C" char* get_shuffle(int, char*);



#endif // ADAPTER_H
