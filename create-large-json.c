#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define RETURN_NAME_LEN 30
char return_name[RETURN_NAME_LEN];

#define EMAIL_LEN 40
char email[EMAIL_LEN];


// Function return random name
// from predefined first name and surname
char *get_random_name();

char *get_email(const char *name)
{
const char *emails_provider[] = {
        "@gmail.com", "@yahoo.com", "@microsoft.com", "@apple.com",
        "@centrum.sk", "@super.com"};
    const unsigned int length_of_emails_provider = sizeof(emails_provider)/sizeof(emails_provider[0]);
    const char *random_email_provider = emails_provider[rand() % length_of_emails_provider];
    for(int i = 0; i < EMAIL_LEN; ++i)
    {
        email[i] = '\0';
    }

    // find length of name
    
    int i = 0;
    while (name[i++] != '\0');
    unsigned int length_of_name = i;
  
    

    // find index of a white space in name
    char *space = strchr(name, ' ');
    const unsigned int index = (int)(space - name);
   
    // get first name
    char firstname[15];
    memcpy(firstname,&name[0],index);
    firstname[index] = 0;

    // get last name
    char lastname[15];
    memcpy(lastname,&name[index + 1], length_of_name);


    /*strcat(email, );*/
    strcat(email, firstname);
    //strcat(email, "_");
    strcat(email, lastname);
    strcat(email, random_email_provider);
    return email;

}






int main(int argc, char *argv[])
{
    
    srand(time(0));
    if (argc < 3)
    {
        
        printf("Usage: -> %s filename.json <ammount: int>\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *filename = (const char *) argv[1];
    const int ammount = (const int) atoi(argv[2]);

    printf("Json: %s,\nData ammount: %d\n", filename, ammount);

    for (int i = 0; i < 5; ++i)
    {
        const char *name = get_random_name();
        const char *email_r = get_email(name);
        printf("Name: %s, email: %s\n", name, email_r );
    }


    return EXIT_SUCCESS;
}



char *get_random_name()
{
    const char *name[] = {"Tomas", "Jarko", "Mirka",
                          "Veronika","Liam", "Noah", 
                          "Oliver", "Elijah", "Olivia",
                          "Emma", "Eva", "Charlote",
                          "Timotej", "Miloslav", "Anna", "Rozalia",
                          "James", "Amelia","Benjamin","Isabella",
                          "Lucas", "Mia", "Henry", "Evelyn", "Alexander", "Harper", "Tony"};
    const unsigned int length_of_names = sizeof(name)/sizeof(name[0]);

    const char *surname[] ={"Lukac", "Mesik", "Smith","Johnson",
                            "Anderson", "Miller", "Garcia", "Williams", "Nelson",
                            "Lopez", "Hernandez", "Lee", " Thomson", "White",
                            "Harris", "Sanchez", "Clark", "King", "Green",
                            "Parker", "Stark"};
    const unsigned int length_of_surnames = sizeof(surname)/sizeof(surname[0]);

    const char *random_first_name = name[rand() % length_of_names];
    const char *random_surname = surname[rand() % length_of_surnames];

    
    // clear variable return_name
    for (int i = 0; i < RETURN_NAME_LEN; ++i)
    {
        return_name[i] = '\0';
    }

    // create string e.g. Tomas Lukac 
    // from random_first_name random_surname 
    strcat(return_name, random_first_name);
    strcat(return_name, " ");
    strcat(return_name, random_surname);
    strcat(return_name, "\0");
    
    return return_name;
}