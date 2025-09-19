#ifndef LIST_DATA_STRUCT_H
#define LIST_DATA_STRUCT_H

#include <QStringList>

struct ListData{
    QStringList table[4096];
    uint16_t    size = 4096;
};

#endif // LIST_DATA_STRUCT_H
