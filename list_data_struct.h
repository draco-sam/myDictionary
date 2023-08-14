#ifndef LIST_DATA_STRUCT_H
#define LIST_DATA_STRUCT_H

#include <QStringList>

struct ListData{
    QStringList table[50];
    uint16_t    size = 50;
};

#endif // LIST_DATA_STRUCT_H
