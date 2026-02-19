#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
int unique_phone(char temp[],AddressBook *addressBook){
    int i;
    for(i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].phone,temp)==0){
            printf("Entered number already exists,Please enter a unique number\n");
            return 1;
        }
        
    }
    return 0;
}
int unique_email(char temp[],AddressBook *addressBook){
    int i;
    for(i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].email,temp)==0){
            printf("Entered email already exists,Please enter a unique email\n");
            return 1;
        }
        
    }
    return 0;
}
int unique_name(char temp[],AddressBook *addressBook){
    int i;
    for(i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].name,temp)==0){
            printf("Entered name already exists,Please enter a unique name\n");
            return 1;
        }
        
    }
    return 0;
}
int validate_name(char temp[])
{
    int i=0;
    while(temp[i]!='\0'){
        if(temp[i]>='a'&&temp[i]<='z'||temp[i]>='A'&&temp[i]<='Z'||temp[i]==' '){
            i++;
        }
        else{
            printf("Enter a valid name\n");
            return 1;
        }
        
    }
    return 0;
}

int validate_phone(char temp[]){
    int i=0;
    while(temp[i]!='\0'){
        if(temp[i]>='0'&& temp[i]<='9'){
            i++;
        }
        else{
            printf("Enter a valid number\n");
            return 1;
        }
    }
    if(i>10||i<10){
        printf("Enter a valid number\n");
            return 1;
    }else{
        return 0;
    }
    return 0;
}

int validate_email(char temp[])
{
    int i=0;
    char com[]=".com";
    char target[]="@";
    if (strstr(temp,com)==NULL){
        printf("Entered email is invalid,\".com\" is missing");
        return 1;

    }
    if(strstr(temp,target)==NULL){
        printf("Entered email is invalid,\"@\" is missing");
        return 1;
    }
    return 0;
    
}


void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    Contact dummy;
    // Sort contacts based on the chosen criteria
    switch(sortCriteria){
        case 1:
            printf("Sorted based on name\n");
            for(int i=0;i<addressBook->contactCount;i++){
                for(int j=0;j<addressBook->contactCount-1;j++){
                    if((strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name))>0)
                    {
                    dummy=addressBook->contacts[j];
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                    addressBook->contacts[j+1]=dummy;              
                  }
                }
            }
            break;
        case 2:
            printf("Sorted based on phone number\n");
            for(int i=0;i<addressBook->contactCount;i++){
                for(int j=0;j<addressBook->contactCount-1;j++){
                    if((strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone))>0)
                    {
                    dummy=addressBook->contacts[j];
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                    addressBook->contacts[j+1]=dummy;              
                  }
                }
            }
            break;
        case 3:
            printf("Sorted based on email\n");
            for(int i=0;i<addressBook->contactCount;i++){
                for(int j=0;j<addressBook->contactCount-1;j++){
                    if((strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email))>0)
                    {
                    dummy=addressBook->contacts[j];
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                    addressBook->contacts[j+1]=dummy;              
                  }
                }
            }
            break;
        default:
            printf("Selection criteria is invalid\n");
            return;
    }
    printf("_________________________________________________________\n");
    printf("INDEX\tNAME\t\tMOBILE_NUMBER\t\tEMAIL\n");
    printf("_________________________________________________________\n");
    for(int i=0;i<addressBook->contactCount;i++){
            printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);

    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char temp[50];
    printf("\tMenu - Create contact");
    printf("___________________________________________________\n");
    do{
        printf("Enter the name:\n");
        scanf(" %[^\n]",temp);
    }while(validate_name(temp)|unique_name(temp,addressBook));
    strcpy(addressBook->contacts[addressBook->contactCount].name,temp);
    do{
        printf("Enter the phone:\n");
        scanf("%s",temp);
    }while(validate_phone(temp)|unique_phone(temp,addressBook));
    strcpy(addressBook->contacts[addressBook->contactCount].phone,temp);
    do{
        printf("Enter the email:\n");
        scanf("%s",temp);
    }while(validate_email(temp)|unique_email(temp,addressBook));
    strcpy(addressBook->contacts[addressBook->contactCount].email,temp);
    addressBook->contactCount++;
    printf("Contact created successfully\n");
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int opt;
    int count=0;
    char temp[20];
    printf("\tMenu - Search contact");
    printf("\nPress 1 for search by name");
    printf("\nPress 2 for search by phone");
    printf("\nPress 3 for search by email\n");
    scanf("%d",&opt);
    switch(opt){
        case 1:
            do{
            printf("Enter the name:");
            scanf(" %[^\n]",temp);
            }while(validate_name(temp));
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcasestr(addressBook->contacts[i].name,temp)!=NULL){
                    count++;
                    printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

                }
                
            }
            
            if(count==0){
                    printf("Contact not found\n");
                    return 0;
                }
            break;
        case 2:
            
            printf("\nEnter the phone number:");
            scanf(" %[^\n]",temp);
            
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcasestr(addressBook->contacts[i].phone,temp)!=NULL){
                    count++;
                    printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

                }
                
            }
            
            if(count==0){
                    printf("Contact number not found\n");
                    return 0;
                }
            break;
        case 3:
            printf("\nEnter the email:");
            scanf(" %[^\n]",temp);
            
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcasestr(addressBook->contacts[i].email,temp)!=NULL){
                    count++;
                    printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

                }
                
            }
            
            if(count==0){
                    printf("Contact email not found\n");
                    return 0;
                }  
            break;
        default:

            printf("Entered option is invalid\n");
    }
    return 1;
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char var[50];
    int index;
    int opt;
    printf("\tMenu - Edit contact");
    if(!(searchContact(addressBook)))
        return;
    printf("\nEnter the index to edit");
    scanf("%d",&index);
    if(index<0 || index>addressBook->contactCount){
        printf("You have entered a invalid index\n");
        return ;
    }
    edit:
    printf("1. Edit Name\t 2.Edit Phone\t3.Edit email\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
            do{
            printf("Enter the name to edit\n");
            scanf(" %[^\n]",var);
            }while(validate_name(var)|unique_name(var,addressBook));
            strcpy(addressBook->contacts[index-1].name,var);
            printf("Name edited successfully\n");
            break;
        case 2:
            do{
            printf("Enter the phone to edit\n");
            scanf(" %[^\n]",var);
            }while(validate_phone(var)|unique_phone(var,addressBook));
            strcpy(addressBook->contacts[index-1].phone,var);
            printf("Phone edited successfully\n");
            break;
        case 3:
            do{
            printf("Enter the email to edit\n");
            scanf(" %[^\n]",var);
            }while(validate_email(var)|unique_email(var,addressBook));
            strcpy(addressBook->contacts[index-1].email,var);
            printf("Email edited successfully\n");
            break;
        default:
            printf("Entered option is invalid\n");
            goto edit;
            
    }
    printf("Contact edited successfully\n");
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int index;
    printf("Menu-----Delete contact\n");
    if(!(searchContact(addressBook)))
        return;
    printf("Enter the index to edit------->");
    scanf("%d",&index);
    if(index<0||index>addressBook->contactCount){
        printf("You have entered a invalid index\n");
        return;
    }
    for(int i=index-1;i<addressBook->contactCount-1;i++){
        addressBook->contacts[i]=addressBook->contacts[i+1];
        
    }
    addressBook->contactCount--;
    printf("Contact deleted sucessfully\n");

}
