/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 30th, 2020, 12:59 PM
 * Purpose:  Specification for the Table Structure
 */

#ifndef DBTABLE_H
#define DBTABLE_H

#include "array.h"

struct DBTable{
    int nCols;//Number of columns in the table
    Array *columns;//Column arrays in the table
};


#endif /* DBTABLE_H */

