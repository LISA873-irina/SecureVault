#ifndef SECURERECORDS_H
#define SECURERECORDS_H

void secureRecords();
void addRecord();
void viewRecord();
void updateRecord();
void deleteRecord();
void searchRecord();
void sortRecord();

typedef struct{
    char recordName[50];
    char details[100];
} SecureRecord;

#endif