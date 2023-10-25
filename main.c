#include <stdio.h>
#include <dirent.h>
#include <string.h>
#define TRUE 1

DIR* open_db(char* db_name);
int select_db(char* path_local_db);
void working_with_db(char* path_local_db);

int main(void) 
{
	int operation = 0;
	char check;
	char path_local_db[255] = "./db";

	while(operation != 3) 
	{
		printf("Select the operation: 1 - Open DB ; 2 - Create DB ; 3 - Exit\n");
		scanf("%d%c", &operation, &check);
		if(check != '\n') break;

		switch (operation)
		{
		case 1:
			int code = select_db(path_local_db);
			if (code == -1) {
				operation = 2;
				break;
			}
			//current_dir = opendir(path_local_db);//open_db(path_local_db);
			working_with_db(path_local_db);
			strcpy(path_local_db, "./db");
			break;
		
		case 2:
			break;
		
		case 3:
			break;

		default:
			break;
		}
	}
	
	return 0;
}

int select_db(char* path_local_db)
{
	DIR *dir_with_dbs = opendir(path_local_db);
	struct dirent *element;
	int i = 0;
	int num_of_dir = 0;
	char check;

	printf("f123Select the db:\n");

	while ((element = readdir(dir_with_dbs)) != NULL)
	{
		i++;
		printf("\t%d - %s\n", i, element->d_name);
	}
	rewinddir(dir_with_dbs);
	i = 0;

	scanf("%d%c", &num_of_dir, &check);
	if(check != '\n') 
	{
		printf("ERROR!\n");
		return -1;
	}

	while (i != num_of_dir)
	{
		element = readdir(dir_with_dbs);
		i++;
	}

	if(element == NULL || strcmp(element->d_name, ".") == 0 || strcmp(element->d_name, "..") == 0) 
	{
		printf("ERROR!\n");
		return -1;
	}

	path_local_db = strcat(path_local_db, "/");
	path_local_db = strcat(path_local_db, element->d_name);

	closedir(dir_with_dbs);
	return 1;
}

DIR* open_db(char* db_name)
{
	DIR* tmp = opendir(db_name);
	return tmp;
}

void working_with_db(char* path_local_db) 
{
	DIR *current_dir = opendir(path_local_db);
	struct dirent *element;
	while ((element = readdir(current_dir)) != NULL) 
	{
		printf("\t%s\n", element->d_name);
	}
}