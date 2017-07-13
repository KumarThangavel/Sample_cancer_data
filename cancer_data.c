#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "cancer_data.h"


void printing_cancer_data( int num_of_record, CANCER_DETAILS *cancer_details)
{

        int i = 0;

        for(i=0; i<num_of_record; i++)
        {
                printf("Total Cancer Count of %s - %ld\n",cancer_details[i].Country, cancer_details[i].Total_cancer_count);
                printf("Lungs Cancer Count of %s - %ld\n", cancer_details[i].Country, cancer_details[i].Lung_cancer_count);
                printf("Liver Cancer Count of %s - %ld\n", cancer_details[i].Country, cancer_details[i].Liver_cancer_count);
                printf("Colorectal Cancer Count of %s - %ld\n", cancer_details[i].Country, cancer_details[i].Colorectal_cancer_count);
                printf("Stomach Cancer Count of %s - %ld\n", cancer_details[i].Country, cancer_details[i].Stomach_cancer_count);
                printf("Breast Cancer Count of %s - %ld\n\n", cancer_details[i].Country, cancer_details[i].Breast_cancer_count);
        
        }

}


void parse_and_store_input_data(char *input_file_name, int *num_of_record)
{
        char tmp[MAX_BUFFER_SIZE];
        int i = 0;
        int ret = 0;

        FILE *fp = fopen(input_file_name, "r");
        if(fp == NULL)
        {
                printf("file ptr fp is null\n");
                return;
        }

        while(fgets(tmp, sizeof(tmp), fp)!= NULL)
        {
                *num_of_record = *num_of_record + 1;
        }

        rewind(fp);
        printf("number of record : %d\n\n", *num_of_record-1);

        CANCER_DETAILS *cancer_details = malloc((*num_of_record-1) * sizeof(CANCER_DETAILS));
        if(cancer_details == NULL)
        {
                printf("Unable to allocate memory for cancer_details\n");
                return;
        }
        
        if(fgets(tmp, sizeof(tmp), fp) == NULL)   // To move the file pointer to next line(First row) to skip the header
        {
                 printf("tmp buffer is empty\n");
                 return;
        }
        

	for( i=0; i < *num_of_record-1 ; i++)
       	{
                if(fgets(tmp, sizeof(tmp), fp) == NULL)
                {
                        printf("tmp buffer is empty\n");
                        return;
                }

                char *ptr;
                char *p = strtok(tmp, ",");

                if(p == NULL)
                {
                        printf("p is null\n");
                        return;
                }
                strcpy(cancer_details[i].Country, p);

                p= strtok('\0', ",");
                cancer_details[i].Total_cancer_count = strtol(p, &ptr, 10);

                p= strtok('\0', ",");
                cancer_details[i].Lung_cancer_count = strtol(p, &ptr, 10);

                p= strtok('\0', ",");
                cancer_details[i].Liver_cancer_count = strtol(p, &ptr, 10);

                p= strtok('\0', ",");
                cancer_details[i].Colorectal_cancer_count = strtol(p, &ptr, 10);

                p= strtok('\0', ",");
                cancer_details[i].Stomach_cancer_count = strtol(p, &ptr, 10);

                p= strtok('\0', ",");
                cancer_details[i].Breast_cancer_count = strtol(p, &ptr, 10);
                                 
        }


        printing_cancer_data(*num_of_record-1, cancer_details);

        fclose(fp);
        free(cancer_details);
}

