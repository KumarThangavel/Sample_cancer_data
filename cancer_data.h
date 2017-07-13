

#define MAX_FILE_SIZE 100
#define MAX_COUNTRY_SIZE 100
#define MAX_BUFFER_SIZE 1024

#define INPUT_FILE_NAME "Allover_count.csv"

typedef struct cancer_details
{
        char Country[MAX_COUNTRY_SIZE];
        long int Total_cancer_count;
        long int Lung_cancer_count;
        long int Liver_cancer_count;
        long int Colorectal_cancer_count;
        long int Stomach_cancer_count;
        long int Breast_cancer_count;

}CANCER_DETAILS;


void parse_and_store_input_data(char *input_file_name, int *num_of_record);
void printing_cancer_data( int num_of_record, CANCER_DETAILS *cancer_details);



