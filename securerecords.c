#include<stdio.h>
#include "securerecords.h"
#include<string.h>

void secureRecords(){

    int choice;
    while(1){

        printf("\n===== Secure Records =====\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Search Record\n");
        printf("6. Sort Records\n");
        printf("7. Back\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){

            addRecord();
        }
        else if (choice == 2){

            viewRecord();
        }
        else if (choice == 3){

            updateRecord();
        }
        else if (choice == 4){

            deleteRecord();
        }
        else if (choice == 5){

            searchRecord();
        }
        else if (choice == 6){

            sortRecord();
        }
        else if (choice == 7){

            return;
        }
        else{
            printf("Invalid choice!\n");
        }

    }
        void addRecord(){

            SecureRecord newRecord;
            printf("Enter record name: ");
            scanf(" %[^\n]", newRecord.recordName);
            printf("Enter details: ");
            scanf(" %[^\n]", newRecord.details);

            FILE *file = fopen("secure_records.dat", "ab");
            if (file == NULL)
            {
                printf("Unable to open file!\n");
                return;
            }
            fwrite(&newRecord, sizeof(newRecord), 1, file);
            fclose(file) ;
            printf("Record added successfully!\n");

        }

        void viewRecord(){

             FILE *file = fopen("secure_records.dat", "rb");
             if (file == NULL)
            {
                printf("No secure records found!\n");
                return;
            }

            SecureRecord recordRead;
            while (fread(&recordRead, sizeof(recordRead), 1, file) == 1)
            {
                printf("\nRecord Name: %s\n", recordRead.recordName);
                printf("Details: %s\n", recordRead.details);
            }

            fclose(file);

        }

        void updateRecord(){

        }

        void deleteRecord(){

        }

        void searchRecord(){

        }

        void sortRecord(){

        }

    }
