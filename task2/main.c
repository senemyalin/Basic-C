#include <stdio.h>

typedef struct {

    int employee_id;
    char employee_name[50];
    char department_of_employee[20];
    int birth_year;
    int salary;

}employeeData;

void menu() {

    int choice;
    for (;;) {
        printf("EMPLOYEE RECORD SYSTEM\n");
        printf("1 - Add new record\n");
        printf("2 - Update new record\n");
        printf("3 - Delete record\n");
        printf("4 - Print all records\n");
        printf("5 - Save as text file\n");
        printf("6 - End program\n\n ");


        FILE* myfile = fopen("employee.bin", "rb");
        printf("ENTER A CHOICE => ");
        scanf("%d", &choice);

        if (choice == 1) {
            addRecord(myfile);
        }
        else if (choice == 2) {
            updateRecord(myfile);
        }
        else if (choice == 3) {
            deleteRecord(myfile);
        }
        else if (choice == 4) {
            showRecords(myfile);
        }
        else if (choice == 5) {
            convertTextFile(myfile);
        }
        else
            break;
    }
    printf("\n**************************************\n");
}


void updateRecord(FILE* file) {
    int id;
    int percentage;
    printf("Enter id to update amount of employee: ");
    scanf("%d", &id);

    employeeData employee_data;


    fseek(file, sizeof(employee_data) * (id - 1), SEEK_SET); //it helps to find id which I want to change
    fread(&employee_data, sizeof(employee_data), 1, file);

    printf("Enter the percentage of increase for salary: ");
    scanf("%d", &employee_data.salary);
    employee_data.salary = employee_data.salary +
        (employee_data.salary * percentage * 0.01);
    fseek(file, sizeof(employee_data.birth_year), SEEK_CUR);
    fwrite(&employee_data.salary, sizeof(employee_data.salary), 1, file);

}
void convertTextFile(FILE* file) {
    FILE* text_file = fopen("employee.txt", "w");

}

void addRecord(FILE* file) {
    int id;
    employeeData employee_data;


    printf("Enter id to create new record: ");
    scanf("%d", &id);

    fopen(file, "wb");
    for (;;) {
        if (fread(file, sizeof(int), 1, employee_bin_in) == id)
            printf("This id is already exist")
            fclose(file);
        return;
    }

    printf("Employee name: ");
    scanf("%d", &employee_data.name);
    printf("\nDeparment: ");
    scanf("%d", &employee_data.department);
    printf("\nBirth year: ");
    scanf("%d", &employee_data.birth_year);
    printf("\nSalary: ");
    scanf("%d", &employee_data.salary);

    fopen(file, "rb");


}

int main(void) {

    menu();
    return 0;
}