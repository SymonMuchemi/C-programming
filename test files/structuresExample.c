#include <stdlib.h>
#include <stdio.h>

struct User
{
    char *name;
    char *email;
    int age;
};

struct User *new_user(char *name, char *email, int age)
{
    struct User *user;
    user = malloc(sizeof(struct User));

    if (user == NULL)
        return (NULL);

    user->name = name;
    user->email = email;
    user->age = age;

    return user;
};

int main(void)
{
    struct User *user;

    user = new_user("muchemi", "muchemi@simon.dev", 20);
    if (user == NULL){
        return (1);
    }
    printf("Username: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Age: %d.", user->age);

    return (0);
}
